#include <bits/stdc++.h>
#define int long long
int N, K, res = 1, MOD = 1000000007;
signed main() {
    std::cin >> K;
    K += 2, N = 2;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1;
        N = N * N % MOD;
    }
    std::cout << (res - 5 + MOD) % MOD;
}