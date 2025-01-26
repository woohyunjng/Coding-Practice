#include <bits/stdc++.h>
#define int long long

#define MAX 300000
using namespace std;

int L[MAX], R[MAX], res;
vector<int> adj[MAX];

int dfs(int node, int par) {
    vector<int> arr;
    int X = 0, K;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        K = dfs(i, node), X = max(X, K);
        arr.push_back(K);
    }

    if (L[node] <= X && X <= R[node])
        return X;
    else if (X < L[node])
        return L[node];
    else {
        for (int i : arr)
            if (i > R[node])
                res += i - R[node];
        return R[node];
    }
}

void solve() {
    int N, X, Y;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        adj[i].clear();
    }

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    res = 0;
    cout << dfs(1, 0) + res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}