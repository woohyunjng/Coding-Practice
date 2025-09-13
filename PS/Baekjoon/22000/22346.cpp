#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 63;
const int MAX_K = 10'001;

int D[MAX][MAX_K + 1], C[MAX], V[MAX];

int dnc(int d, int l, int r, int k) {
    if (d == 0)
        return l <= r ? 1 : 0;

    int m = 1ll << d, ans = 0, K = k - V[d], X;
    if (r < m)
        return dnc(d - 1, l, r, k);
    else if (l > m)
        return dnc(d - 1, l - m, r - m, k);

    for (int i = 0; i <= min(C[d - 1], K); i++)
        ans = max(ans, min(r - m, D[d - 1][i + 1] - 1) + min(m - l, D[d - 1][min({MAX_K - 1, C[d - 1], K - i}) + 1] - 1) + 1);

    return max(ans, dnc(d - 1, 1, max(r - m, m - l), k));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, S, Q, L, R, K;
    vector<int> arr;

    cin >> N >> Q, X = N;
    while (X)
        arr.push_back(X), X >>= 1;

    reverse(arr.begin(), arr.end()), S = arr.size();

    D[0][1] = 2;

    for (int i = 1; i < S; i++) {
        V[i] = !(arr[i] & 1), X = min(C[i - 1], MAX_K);
        C[i] = C[i - 1] << 1ll | V[i];

        for (int j = 1; j <= X; j++)
            D[i][j] = D[i - 1][j];
        if (V[i] && X + 1 <= MAX_K)
            D[i][++X] = 1ll << i;
        for (int j = 1; X + j <= min(C[i], MAX_K); j++)
            D[i][X + j] = D[i - 1][j] + (1ll << i);
        if (C[i] + 1 <= MAX_K)
            D[i][C[i] + 1] = 1ll << (i + 1);
    }

    while (Q--) {
        cin >> L >> R >> K;
        cout << dnc(S - 1, L, R, K) << '\n';
    }

    return 0;
}