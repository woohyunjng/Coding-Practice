#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 500001;

int S, A[MAX], H[MAX], R[MAX], C[MAX], B[MAX], in[MAX];
bool chk[MAX], cycle[MAX];
vector<int> adj[MAX];
vector<pr> con[MAX];

set<pr> dfs(int node) {
    set<pr> res, val;
    set<pr>::iterator iter;

    pr K;
    int X;

    res.insert({1, B[node]});

    for (int i : adj[node]) {
        val = dfs(i);
        if (val.size() > res.size())
            swap(val, res);
        while (!val.empty()) {
            K = *val.begin(), val.erase(val.begin());
            iter = res.lower_bound({K[0], 0});
            if (iter != res.end() && (*iter)[0] == K[0])
                K[1] += (*iter)[1], res.erase(iter);
            res.insert(K);
        }
    }

    for (pr i : con[node]) {
        X = i[1];
        while (true) {
            iter = prev(res.lower_bound({i[0] + 1, 0}));
            if ((*iter)[1] < X) {
                X -= (*iter)[1], res.erase(iter);
                continue;
            }
            K = *iter, res.erase(iter), res.insert({K[0], K[1] - X});
            res.insert({i[0] + 1, i[1]});
            break;
        }
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans = 0;
    set<pr> res;
    vector<int> comp, arr;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> H[i] >> C[i], R[i] = i;
        comp.push_back(H[i]), in[A[i]]++;
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 1; i <= N; i++)
        H[i] = lower_bound(comp.begin(), comp.end(), H[i]) - comp.begin() + 1;

    queue<int> q;

    for (int i = 1; i <= N; i++)
        if (in[i] == 0)
            q.push(i);

    while (!q.empty()) {
        X = q.front(), q.pop(), chk[X] = true;
        if (--in[A[X]] == 0)
            q.push(A[X]);
    }

    for (int i = 1; i <= N; i++) {
        if (chk[i])
            continue;
        X = i, arr.push_back(i), chk[i] = true;
        while (!chk[A[X]])
            X = A[X], arr.push_back(X), chk[X] = true;

        sort(arr.begin(), arr.end(), [&](int x, int y) { return H[x] < H[y]; });
        for (int j : arr) {
            R[j] = i, B[i] += C[j], cycle[j] = true;
            if (!con[i].empty() && con[i].back()[0] == H[j])
                con[i][(int)con[i].size() - 1][1] += C[j];
            else
                con[i].push_back({H[j], C[j]});
        }
        arr.clear();
    }

    for (int i = 1; i <= N; i++)
        if (!cycle[i]) {
            adj[R[A[i]]].push_back(i);
            con[i].push_back({H[i], C[i]}), B[i] = C[i];
        }

    for (int i = 1; i <= N; i++) {
        if (!cycle[i] || R[i] != i)
            continue;
        res = dfs(i);
        for (pr i : res)
            if (i[0] == 1)
                ans += i[1];
    }
    cout << ans << '\n';

    return 0;
}