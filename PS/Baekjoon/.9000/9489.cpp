#include <bits/stdc++.h>
#define int long long

#define MAX 2000000

using namespace std;

int A[MAX], parent[MAX];
vector<int> adj[MAX];

int dfs(int node, int x, int d) {
    if (d == 2)
        return 1;
    int res = 0;
    for (int i : adj[node]) {
        if (i == x)
            continue;
        res += dfs(i, x, d + 1);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans = 0, X, Y, P;
    vector<int> arr;

    while (true) {
        cin >> N >> K;
        if (N == 0 && K == 0)
            break;

        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            arr.push_back(A[i]);
        }

        X = 1, P = 0;
        while (X <= N) {
            Y = X;
            while (Y + 1 <= N && A[Y + 1] == A[X] + Y - X + 1)
                Y++;
            for (int i = X; i <= Y; i++)
                parent[A[i]] = A[P], adj[A[P]].push_back(A[i]);
            P++, X = Y + 1;
        }

        X = parent[parent[K]];
        if (X != 0)
            ans = dfs(X, parent[K], 0);
        else
            ans = 0;
        cout << ans << '\n';

        for (int i = 1; i <= N; i++)
            parent[A[i]] = 0, adj[A[i]].clear();
    }

    return 0;
}