#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;

int N, sa[MAX], lcp[MAX], group[MAX], nxt[MAX], rnk[MAX], ans[MAX][2], V[MAX][2], par[MAX]; // V[i][0] = sa, V[i][1] = 길이

vector<int> adj[MAX];
set<int> st;

set<int> dfs(int node) {
    set<int> val, tmp;
    set<int>::iterator it;
    if (sa[V[node][0]] + V[node][1] == N)
        val.insert(sa[V[node][0]]);

    for (int i : adj[node]) {
        if (par[i] != node)
            continue;
        tmp = dfs(i);
        if (val.size() < tmp.size())
            swap(val, tmp);
        while (!tmp.empty())
            val.insert(*tmp.begin()), tmp.erase(tmp.begin());
    }

    int st = 1, en = V[node][1], md, AP = val.size(), K = V[par[node]][1] + 1, X;
    it = val.begin(), X = 0;

    while (it != val.end())
        X++, it = val.lower_bound(*it + K);

    if (ans[AP][0] <= X) {
        ans[AP][1] = ans[AP][0] < X ? 0 : ans[AP][1], ans[AP][0] = X;
        st = K, en = V[node][1];
        while (st <= en) {
            md = st + en >> 1, X = 0, it = val.begin();
            while (it != val.end())
                X++, it = val.lower_bound(*it + md);
            if (X == ans[AP][0])
                ans[AP][1] = max(ans[AP][1], md), st = md + 1;
            else
                en = md - 1;
        }
    }

    return val;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    int K, X, Y, Z, C = 0;

    cin >> S, N = S.size();

    for (int i = 0; i < N; i++)
        sa[i] = i, group[i] = S[i] - 'a';
    group[N] = -1, K = 1, X = 0;

    function<bool(int, int)> cmp = [&](int X, int Y) {
        if (group[X] == group[Y])
            return group[X + K] < group[Y + K];
        return group[X] < group[Y];
    };

    while (K <= N) {
        sort(sa, sa + N, cmp);
        for (int i = 1; i < N; i++)
            nxt[sa[i]] = nxt[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        for (int i = 0; i < N; i++)
            group[i] = nxt[i];
        K <<= 1;
    }

    for (int i = 0; i < N; i++)
        rnk[sa[i]] = i;
    for (int i = 0; i < N; i++) {
        Y = rnk[i];
        if (!Y)
            continue;
        while (S[i + X] == S[sa[Y - 1] + X])
            X++;
        lcp[Y] = X, X = max(0, X - 1);
    }

    vector<pr> arr;

    arr.push_back({0, 0}), V[0][0] = 0, V[0][1] = N - sa[0];
    par[0] = -1;

    for (int i = 1; i < N; i++) {
        while (!arr.empty() && lcp[arr.back()[0]] >= lcp[i])
            arr.pop_back();
        V[++C][0] = i, V[C][1] = N - sa[i], Z = C;
        if (!arr.empty()) {
            X = arr.back()[0], Y = arr.back()[1];
            if (lcp[i] < V[Y][1]) {
                adj[++C].push_back(Y), arr.pop_back(), par[C] = par[Y];
                if (par[Y] != -1)
                    adj[par[Y]].push_back(C);
                par[Y] = C, V[C][0] = X, V[C][1] = lcp[i];
                arr.push_back({X, C}), Y = C;
            }
            adj[Y].push_back(Z), par[Z] = Y;
        } else
            par[Z] = -1;
        arr.push_back({i, Z});
    }

    ans[1][0] = N, ans[1][1] = N;

    for (int i = 0; i <= C; i++) {
        if (par[i] != -1)
            continue;
        dfs(i);
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i][1] << ' ';
    cout << '\n';

    return 0;
}