#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int A[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 2e9, X, Y;

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    for (int i = 0; i < (1 << N); i++) {
        if (__builtin_popcount(i) * 2 != N)
            continue;

        X = Y = 0;
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++) {
                if ((i & (1 << j)) && (i & (1 << k)))
                    X += A[j][k];
                else if (!(i & (1 << j)) && !(i & (1 << k)))
                    Y += A[j][k];
            }
        ans = min(ans, abs(X - Y));
    }

    cout << ans << '\n';

    return 0;
}