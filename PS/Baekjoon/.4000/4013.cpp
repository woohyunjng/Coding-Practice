#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 600000;

vector<int> adj[MAX], rev[MAX], st, scc_adj[MAX];
int V[MAX], A[MAX], cnt, num[MAX], in[MAX], dp[MAX];
bool vst[MAX];

void dfs(int node) {
    vst[node] = true;
    for (int i : adj[node]) {
        if (vst[i])
            continue;
        dfs(i);
    }
    st.push_back(node);
}

void dfs2(int node) {
    num[node] = cnt, A[cnt] += V[node];
    for (int i : rev[node]) {
        if (num[i])
            continue;
        dfs2(i);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, S, ans = 0;
    cin >> N >> M;

    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), rev[Y].push_back(X);
    }

    for (int i = 1; i <= N; i++)
        cin >> V[i];

    for (int i = 1; i <= N; i++) {
        if (vst[i])
            continue;
        dfs(i);
    }

    while (!st.empty()) {
        X = st.back(), st.pop_back();
        if (num[X])
            continue;
        cnt++, dfs2(X);
    }

    for (int i = 1; i <= N; i++)
        for (int j : adj[i]) {
            if (num[i] == num[j])
                continue;
            scc_adj[num[i]].push_back(num[j]);
        }

    N = cnt;
    for (int i = 1; i <= N; i++) {
        sort(scc_adj[i].begin(), scc_adj[i].end());
        scc_adj[i].erase(unique(scc_adj[i].begin(), scc_adj[i].end()), scc_adj[i].end());
    }

    cin >> S;

    queue<int> q;
    q.push(num[S]), fill(vst + 1, vst + N + 1, false), vst[num[S]] = true;

    while (!q.empty()) {
        X = q.front(), q.pop();
        for (int i : scc_adj[X]) {
            if (!in[i]++)
                q.push(i);
        }
    }

    q.push(num[S]);
    while (!q.empty()) {
        X = q.front(), q.pop();
        dp[X] += A[X];

        for (int i : scc_adj[X]) {
            dp[i] = max(dp[i], dp[X]);
            if (!--in[i])
                q.push(i);
        }
    }

    cin >> S;
    while (S--)
        cin >> X, ans = max(ans, dp[num[X]]);
    cout << ans << '\n';

    return 0;
}