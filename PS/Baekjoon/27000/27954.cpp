#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, T, X, Y, A, B, C = 0;
    cin >> N >> M >> Q;

    vector<vector<char>> arr(N, vector<char>(M));
    A = N - 1, B = M - 1;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> X >> Y;
            if (C & 1)
                A = (A - X + N) % N, B = (B - Y + M) % M;
            else
                A = (A + X) % N, B = (B + Y) % M;
            C ^= 1;
        } else {
            if (C & 1) {
                for (int i = A; i >= 0; i--) {
                    for (int j = B; j >= 0; j--)
                        cout << arr[i][j];
                    for (int j = M - 1; j > B; j--)
                        cout << arr[i][j];
                    cout << '\n';
                }
                for (int i = N - 1; i > A; i--) {
                    for (int j = B; j >= 0; j--)
                        cout << arr[i][j];
                    for (int j = M - 1; j > B; j--)
                        cout << arr[i][j];
                    cout << '\n';
                }
            } else {
                for (int i = A + 1; i < N; i++) {
                    for (int j = B + 1; j < M; j++)
                        cout << arr[i][j];
                    for (int j = 0; j <= B; j++)
                        cout << arr[i][j];
                    cout << '\n';
                }
                for (int i = 0; i <= A; i++) {
                    for (int j = B + 1; j < M; j++)
                        cout << arr[i][j];
                    for (int j = 0; j <= B; j++)
                        cout << arr[i][j];
                    cout << '\n';
                }
            }
        }
    }

    return 0;
}