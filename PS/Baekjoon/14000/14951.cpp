#include <bits/stdc++.h>
using namespace std;

const int MAX = 300001;

int A[MAX], depth[MAX], parent[MAX], dp[MAX], S[MAX];
bool vst[MAX], chk[MAX];
vector<int> adj[MAX];

int dfs(int node, int par) {
    int X;
    depth[node] = depth[par] + 1, parent[node] = par;
    X = depth[node];

    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        X = max(X, dfs(i, node));
    }
    return X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs(1, 0), X = max_element(depth + 1, depth + N + 1) - depth;
    dfs(X, 0), Y = max_element(depth + 1, depth + N + 1) - depth;

    for (int i = Y; i; i = parent[i])
        vst[i] = true, arr.push_back(i);

    N = arr.size();
    for (int i = 0; i < N; i++) {
        A[i + 1] = dfs(arr[i], 0) - 1;
        S[i + 1 - A[i + 1]]++, S[i + 1 + A[i + 1]]--;
    }

    N--, X = S[1];
    for (int i = 2; i < N; i++) {
        X += S[i], dp[i] = dp[i - 2];
        if (X > 0)
            continue;
        if (i & 1)
            dp[i] = max(dp[i], 1);
        if (i >= 3)
            dp[i] = max(dp[i], dp[i - 3] + 1);
    }

    cout << (N - (N > 1 ? dp[N - 2] : 0) + 1) / 2 << '\n';

    return 0;
}