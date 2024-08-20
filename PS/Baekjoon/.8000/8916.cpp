#include <bits/stdc++.h>
#define int long long

#define MAX 22
#define MOD 9999991
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], bigger[MAX], dp[1 << MAX][2], tree[1 << MAX];
int fac[MAX], inv_fac[MAX];

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1;
        N = N * N % MOD;
    }
    return res;
}

void init(int L) {
    fac[0] = 1;
    for (int i = 1; i <= L; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv_fac[L] = fpow(fac[L], MOD - 2);
    for (int i = L - 1; i >= 0; i--)
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
}

int comb(int A, int B) {
    int X = fac[A], Y = inv_fac[B], Z = inv_fac[A - B];
    return X * Y % MOD * Z % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K;
    stack<int> nodes, nodes_2;

    init(20);

    cin >> T;

    while (T--) {
        fill(tree, tree + MAX, 0);
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            K = 1;

            while (tree[K] != 0) {
                if (arr[i] < arr[tree[K]])
                    K = K << 1;
                else
                    K = K << 1 | 1;
            }
            tree[K] = i;
            nodes.push(K);
            nodes_2.push(K);
        }

        while (!nodes.empty()) {
            K = nodes.top(), nodes.pop();
            dp[K][0]++;
            dp[K >> 1][0] += dp[K][0];

            dp[K][1] = comb(dp[K << 1][0] + dp[K << 1 | 1][0], dp[K << 1][0]);
            if (dp[K << 1][1])
                dp[K][1] = dp[K][1] * dp[K << 1][1] % MOD;
            if (dp[K << 1 | 1][1])
                dp[K][1] = dp[K][1] * dp[K << 1 | 1][1] % MOD;
        }

        cout << dp[1][1] << '\n';

        while (!nodes_2.empty()) {
            K = nodes_2.top(), nodes_2.pop();
            tree[K] = dp[K][0] = dp[K][1] = 0;
        }
    }

    return 0;
}