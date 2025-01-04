#include <bits/stdc++.h>
#define int long long

using namespace std;

int fpow(int N, int K) {
    int res = 1;
    while (K--)
        res *= N;
    return res;
}

int cnt(string S, int T) {
    int res = 0, N = S.size(), K = S[0] - '0';
    if (N == 0)
        return 1;
    if (K < T) {
        res += fpow(T, N - 1) * K;
        res += cnt(S.substr(1), T);
    } else
        res += fpow(T, N - 1) * T;
    return res;
}

int calc(int X) {
    if (X < 10)
        return 0;
    int res = 0, val = 1, K;
    string S = to_string(X);

    for (int i = 1, j = 10; j <= X; i++, j *= 10)
        for (int k = 1; k < 10 && (k + 1) * j <= X; k++)
            res += fpow(k, i);

    K = S[0] - '0';
    S = S.substr(1);
    res += cnt(S, K);

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int L, R;
    cin >> L >> R;

    cout << calc(R) - calc(L - 1) << '\n';

    return 0;
}