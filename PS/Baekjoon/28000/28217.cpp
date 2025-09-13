#include <bits/stdc++.h>
using namespace std;

const int MAX = 11;

int A[MAX][MAX], B[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = MAX * MAX, V;

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            cin >> A[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            cin >> B[i][j];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < N; k++)
                for (int l = 0; l <= k; l++)
                    A[l][N - 1 - k] = A[k][l];
            for (int k = N - 1; k >= 0; k--)
                for (int l = 0; l < N - k; l++)
                    A[k + l][l] = A[k][l];

            V = 0;
            for (int k = 0; k < N; k++)
                for (int l = 0; l <= k; l++)
                    V += A[k][l] ^ B[k][l];
            ans = min(ans, V);
        }

        for (int j = 0; j < N; j++)
            reverse(A[j], A[j] + j + 1);
    }

    cout << ans << '\n';

    return 0;
}