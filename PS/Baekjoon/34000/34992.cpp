#include <bits/stdc++.h>
using namespace std;

const int MAX = 500000;

int S[MAX], L[MAX], R[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;

    cin >> K;
    for (int i = 0; i < K; i++)
        cin >> S[i];
    N = S[K - 1] >> 1;

    if (S[0] != 0) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i + 1 < K; i++) {
        R[S[i] + 1] = S[i + 1] + (i + 1 != K - 1);
        if (S[i] + 2 == S[i + 1])
            L[S[i] + 1] = S[i];
        else {
            L[S[i] + 1] = S[i] + 3;
            for (int j = S[i] + 3; j < S[i + 1] - 1; j += 2)
                L[j] = j - 3, R[j] = j + 2;
            L[S[i + 1] - 1] = S[i + 1] - 4, R[S[i + 1] - 1] = S[i + 1] - 2;
        }
    }

    cout << N << '\n';
    for (int i = 0; i < N; i++)
        cout << L[i << 1 | 1] << ' ' << R[i << 1 | 1] << '\n';

    return 0;
}