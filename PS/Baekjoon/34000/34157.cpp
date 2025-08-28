#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MAX_LOG = 20;
const int MOD = 998244353;

int in[MAX], out[MAX], dp[MAX], A[MAX], cnt;
vector<int> adj[MAX], arr[MAX];

int inv(int N) {
    int res = 1, K = MOD - 2;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1, N = N * N % MOD;
    }
    return res;
}

void dfs(int node, int par) {
    in[node] = ++cnt;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
    }
    out[node] = cnt;
}

void calc(int node, int par) {
    for (int i : arr[node]) {
        dp[node] *= (A[i] - 1) * inv(A[i]) % MOD, dp[node] %= MOD;
        A[i]--;
    }

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dp[i] = dp[node], calc(i, node);
    }

    for (int i : arr[node])
        A[i]++;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V;
    vector<int> val;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        for (int j = 0; j < A[i]; j++)
            cin >> V, arr[V].push_back(i);
    }

    for (int i = 0; i < N - 1; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    dfs(1, 0);

    for (int i = 1; i <= N; i++) {
        val = arr[i], arr[i].clear();
        for (int j : val)
            if (in[j] <= in[i] && in[i] <= out[j])
                arr[i].push_back(j);
    }

    dp[1] = 1, calc(1, 0);
    for (int i = 2; i <= N; i++)
        cout << dp[i] << '\n';

    return 0;
}