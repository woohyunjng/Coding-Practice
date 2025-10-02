#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 100'007;

int fpow(int N, int K, int M) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % M;
        K >>= 1, N = N * N % M;
    }
    return res;
}

int _comb(int N, int K, int M) {
    if (N < K)
        return 0;

    int X = 1, Y = 1, Z = 1;
    for (int i = 1; i <= N; i++)
        X = X * i % M;
    for (int i = 1; i <= K; i++)
        Y = Y * i % M;
    for (int i = 1; i <= N - K; i++)
        Z = Z * i % M;
    return X * fpow(Y, M - 2, M) % M * fpow(Z, M - 2, M) % M;
}

int comb(int N, int K, int M) {
    if (N < K)
        return 0;

    vector<pr> arr;
    while (N || K) {
        arr.push_back({N % M, K % M});
        N /= M, K /= M;
    }

    int res = 1;
    for (pr i : arr)
        res = res * _comb(i[0], i[1], M) % M;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, V[2], K[2], ans;

    cin >> T;
    while (T--) {
        cin >> N >> M;
        if (N == 0 && M == 1)
            ans = 1;
        else if (N == 0 || M == 1 || M > N + 1)
            ans = 0;
        else {
            V[0] = comb(N - 1, M - 2, 1031), V[1] = comb(N - 1, M - 2, 97);
            K[0] = fpow(97, 1029, 1031), K[1] = fpow(1031, 95, 97);
            ans = (V[0] * K[0] % 1031 * 97 + V[1] * K[1] % 97 * 1031) % (1031 * 97);
        }
        cout << ans << '\n';
    }

    return 0;
}