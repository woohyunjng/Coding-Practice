#include <bits/stdc++.h>
#define int long long

#define MAX 42
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int P, C[MAX];
vector<int> adj[MAX];

int dfs(int node, int mask) {
    vector<int> arr;
    int res = 0, val = INF;

    if (!(mask & (1ll << node)))
        res += C[node], mask |= (1ll << node);
    for (int i : adj[node])
        if (!(mask & (1ll << i))) {
            arr.push_back(i);
            res += C[i], mask |= (1ll << i);
        }

    if (node == P)
        return res;

    for (int i : arr)
        val = min(val, dfs(i, mask));

    return res + val;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B;
    cin >> N >> M, P = N - 1;

    for (int i = 0; i < N; i++)
        cin >> C[i];

    for (int i = 0; i < M; i++) {
        cin >> A >> B, --A, --B;
        adj[A].push_back(B), adj[B].push_back(A);
    }

    cout << dfs(0, 0) << '\n';

    return 0;
}