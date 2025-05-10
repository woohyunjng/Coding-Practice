#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;
typedef priority_queue<int> pq;
typedef array<pq, 2> pqr;

const int MAX = 200001;

int A[MAX], B[MAX], K;
vector<pr> adj[MAX];

pqr dfs(int node, int par) {
    pqr res = {pq(), pq()}, val;
    int X;

    res[0].push(0);
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        val = dfs(i[0], node), A[i[0]] -= i[1], B[i[0]] -= i[1];

        if (K % 2 == 1 && !val[1].empty())
            X = val[1].top(), val[1].pop(), val[1].push(X + i[1]);

        if (res[0].size() < val[0].size())
            swap(res[0], val[0]), swap(A[node], A[i[0]]);
        while (!val[0].empty())
            res[0].push(val[0].top() + A[i[0]] - A[node]), val[0].pop();

        while (res[0].size() > (K >> 1))
            X = res[0].top(), res[0].pop(), res[1].push(-X - A[node] - B[node]);

        if (res[1].size() < val[1].size())
            swap(res[1], val[1]), swap(B[node], B[i[0]]);
        while (!val[1].empty())
            res[1].push(val[1].top() + B[i[0]] - B[node]), val[1].pop();
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X, Y, W, ans;
    pqr res;

    cin >> T;
    while (T--) {
        cin >> N >> K, ans = 0;

        for (int i = 1; i < N; i++) {
            cin >> X >> Y >> W;
            adj[X].push_back({Y, W}), adj[Y].push_back({X, W});
        }

        res = dfs(1, 0), X = 0;
        while (!res[0].empty())
            ans -= res[0].top() + A[1], res[0].pop(), X++;
        while (!res[1].empty() && X < K)
            ans += res[1].top() + B[1], res[1].pop(), X++;

        cout << ans * 2 << '\n';

        for (int i = 1; i <= N; i++)
            adj[i].clear(), A[i] = B[i] = 0;
    }

    return 0;
}