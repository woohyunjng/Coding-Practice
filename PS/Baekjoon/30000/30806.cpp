#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1500000;
const int MOD = 998244353;

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        N = N * N % MOD, K >>= 1;
    }
    return res;
}

int fac[MAX], inv[MAX], ans[MAX];
map<int, int> cnt;

int comb(int N, int K) { return fac[N] * inv[K] % MOD * inv[N - K] % MOD; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, X;
    vector<int> arr;

    fac[0] = 1;
    for (int i = 1; i < MAX; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[MAX - 1] = fpow(fac[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        while (S--) {
            cin >> X;
            cnt[X]++, arr.push_back(X);
        }
    }

    sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (int i : arr) {
        X = cnt[i];
        for (int j = 1; j <= X; j++)
            ans[j] = (ans[j] + comb(X, j)) % MOD;
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';

    return 0;
}