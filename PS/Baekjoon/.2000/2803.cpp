#include <bits/stdc++.h>
#define int long long

#define MAX 21
#define MOD 1000000007

using namespace std;

int fpow(int K) {
    int X = 2, res = 1;
    while (K) {
        if (K & 1)
            res = (res * X) % MOD;
        X = (X * X) % MOD, K >>= 1;
    }
    return res;
}

int cnt[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, T, X, A, res = 0;
    cin >> N >> M;

    while (N--) {
        cin >> T, X = 0;
        while (T--)
            cin >> A, X |= (1 << (A - 1));
        cnt[X]++;
    }

    for (int i = 0; i < M; i++)
        for (int j = 0; j < (1 << M); j++)
            if (j & (1 << i))
                cnt[j] += cnt[j ^ (1 << i)];

    for (int i = 0; i < (1 << M); i++)
        res = (res + fpow(cnt[i]) * ((M - __builtin_popcount(i)) % 2 ? -1 : 1) + MOD) % MOD;
    cout << res << '\n';

    return 0;
}