#include <bits/stdc++.h>
using namespace std;

const int MAX = 2187;

int A[MAX][MAX], ans[3];

void dnc(int X, int Y, int S) {
    bool flag = true;
    for (int i = X; i < X + S; i++)
        for (int j = Y; j < Y + S; j++)
            flag &= A[X][Y] == A[i][j];

    if (flag)
        ans[A[X][Y] + 1]++;
    else {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                dnc(X + i * S / 3, Y + j * S / 3, S / 3);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    dnc(0, 0, N);

    for (int i = 0; i < 3; i++)
        cout << ans[i] << '\n';

    return 0;
}