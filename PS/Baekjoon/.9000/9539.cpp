#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;
typedef priority_queue<pr, vector<pr>, greater<pr>> pr_pq;

const int MAX = 400000;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[MAX];
pr V[MAX];

pr_pq dfs(int node, int par) {
    pr_pq pq, tmp;
    pr K, R;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        tmp = dfs(i, node);
        if (tmp.size() > pq.size())
            swap(tmp, pq);
        while (!tmp.empty())
            K = tmp.top(), tmp.pop(), pq.push(K);
    }

    R = V[node];
    if (R[0] > 0) {
        while (!pq.empty() && R[1] <= 0)
            K = pq.top(), pq.pop(), R[0] = max(R[0], K[0] - R[1]), R[1] += K[1];
    }

    while (!pq.empty() && pq.top()[0] <= R[0] + R[1])
        K = pq.top(), pq.pop(), R[1] += K[1];
    if (R[1] >= 0)
        pq.push(R);

    return pq;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, S, X, Y, ans = 0;
    pr K;

    cin >> T;
    while (T--) {
        cin >> N >> S;
        for (int i = 1; i <= N; i++) {
            adj[i].clear(), cin >> X;
            if (X >= 0)
                V[i] = {0, X};
            else
                V[i] = {-X, X};
        }

        for (int i = 1; i < N; i++) {
            cin >> X >> Y;
            adj[X].push_back(Y), adj[Y].push_back(X);
        }

        V[S][1] += INF;

        pr_pq res = dfs(1, 0);
        ans = res.top()[1];

        cout << (ans > 0x1f1f1f1f1f1f1f1f ? "escaped" : "trapped") << '\n';
    }

    return 0;
}