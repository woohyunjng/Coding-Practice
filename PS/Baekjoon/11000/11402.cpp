#include <bits/stdc++.h>
#define int long long

#define MAX 2010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int fpow(int N, int K, int M) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % M;
        K >>= 1;
        N = N * N % M;
    }
    return res;
}

int comb(int N, int K, int M) {
    if (N < K)
        return 0;

    int X = 1, Y = 1, Z = 1;
    for (int i = 1; i <= N; i++)
        X = X * i % M;
    for (int i = 1; i <= K; i++)
        Y = Y * i % M;
    for (int i = 1; i <= N - K; i++)
        Z = Z * i % M;
    Y = fpow(Y, M - 2, M);
    Z = fpow(Z, M - 2, M);
    return X * Y % M * Z % M;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, M, res = 1;
    vector<pr> arr;

    cin >> N >> K >> M;
    while (N != 0 || K != 0) {
        arr.push_back({N % M, K % M});
        N /= M, K /= M;
    }

    for (pr i : arr)
        res = res * comb(i.first, i.second, M) % M;

    cout << res;

    return 0;
}