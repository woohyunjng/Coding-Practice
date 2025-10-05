#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 4> matrix;

const int MOD = 1'000'000'007;

matrix mul(matrix X, matrix Y) {
    matrix res = {0, 0, 0, 0};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                res[i * 2 + j] = (res[i * 2 + j] + X[i * 2 + k] * Y[k * 2 + j]) % MOD;
    return res;
}

matrix fpow(matrix X, int K) {
    matrix res = {1, 0, 0, 1};
    while (K) {
        if (K & 1)
            res = mul(res, X);
        K >>= 1, X = mul(X, X);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans;
    matrix val;

    cin >> N;
    if (N & 1) {
        cout << 0 << '\n';
        return 0;
    }

    val = fpow({4, -1 + MOD, 1, 0}, (N - 2) / 2);
    ans = (val[0] * 3 + val[1]) % MOD;
    cout << ans << '\n';

    return 0;
}