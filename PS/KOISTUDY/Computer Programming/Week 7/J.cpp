#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 1001;

pr go[8] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int A[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, X, Y;
    string S;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < N; j++) {
            if (S[j] == 'g')
                A[i][j] = 0;
            else if (S[j] == 's')
                A[i][j] = 1;
            else if (S[j] == 'h')
                A[i][j] = 2;
        }
    }

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++) {
                X = j + go[i][0] * 3, Y = k + go[i][1] * 3;
                if (X < 0 || X >= N || Y < 0 || Y >= N)
                    continue;
                ans += A[j][k] == 0 && A[j + go[i][0]][k + go[i][1]] == 1 && A[j + go[i][0] * 2][k + go[i][1] * 2] == 2 && A[j + go[i][0] * 3][k + go[i][1] * 3] == 1;
            }

    cout << ans << '\n';

    return 0;
}