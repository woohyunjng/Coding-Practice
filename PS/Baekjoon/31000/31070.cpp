#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MOD = 1000000007;

int N, K, fac[MAX], inv[MAX], ans, D[MAX];
vector<int> adj[MAX];

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        N = N * N % MOD, K >>= 1;
    }
    return res;
}

int comb(int N, int K) {
    if (K > N || K < 0)
        return 0;
    return fac[N] * inv[K] % MOD * inv[N - K] % MOD;
}

int dfs(int node, int par) {
    D[node] = D[par] + 1;
    int res = 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        res += dfs(i, node);
    }
    if (node != 1)
        ans += (comb(N - 1, K) - comb(N - 1 - res, K) + MOD) % MOD * 2 % MOD;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int U, V;
    vector<int> arr;

    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[N] = fpow(fac[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;

    D[0] = -1, dfs(1, 0);
    for (int i = 2; i <= N; i++)
        arr.push_back(D[i]);

    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
        ans = (ans - arr[i] * comb(i, K - 1) % MOD + MOD) % MOD;

    cout << ans << '\n';

    return 0;
}