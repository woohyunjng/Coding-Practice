#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][2], sz[MAX], sm[MAX], A[MAX], depth[MAX], max_depth[MAX];
vector<int> adj[MAX];

void dfs(int K, int pr) {
    vector<int> arr, X, Y;

    sz[K] = 1, sm[K] = A[K], max_depth[K] = depth[K];

    for (int i : adj[K]) {
        if (i == pr)
            continue;
        depth[i] = depth[K] + 1;
        dfs(i, K);
        max_depth[K] = max(max_depth[K], max_depth[i]);

        sz[K] += sz[i], sm[K] += sm[i];
        dp[K][0] += sm[i] + dp[i][0];
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [&](int A, int B) { return sz[A] * sm[B] < sz[B] * sm[A]; });

    for (int i = 0; i < arr.size(); i++) {
        if (!X.empty())
            X.push_back(X.back() + sz[arr[i]]), Y.push_back(Y.back() + sm[arr[i]]);
        else
            X.push_back(sz[arr[i]]), Y.push_back(sm[arr[i]]);
        dp[K][0] += (X.back() - sz[arr[i]]) * sm[arr[i]] * 2;
    }

    if (!arr.empty())
        dp[K][1] = INF;

    for (int i = 0; i < arr.size(); i++) {
        if (max_depth[arr[i]] != max_depth[K])
            continue;

        dp[K][1] = min(dp[K][1],
                       dp[K][0] - dp[arr[i]][0] + dp[arr[i]][1] - (X[i] - sz[arr[i]]) * sm[arr[i]] * 2 - sz[arr[i]] * (Y.back() - Y[i]) * 2 + sm[arr[i]] * (X.back() - sz[arr[i]]) * 2);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T, X, Y;
    cin >> N >> T;

    for (int i = 2; i <= N; i++) {
        cin >> X >> A[i];
        adj[X].push_back(i), adj[i].push_back(X);
    }

    depth[1] = 0;
    dfs(1, 0);

    cout << 2 * (N - 1) - max_depth[1] * T << ' ' << dp[1][T];

    return 0;
}