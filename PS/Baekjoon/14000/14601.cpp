#include <bits/stdc++.h>
using namespace std;

const int MAX = 128;

int ans[MAX][MAX], cnt;

void dnc(int X, int Y, int K, int A, int B) {
    if (K == 0)
        return;

    int PX, PY, VX, VY, V = ++cnt;
    bool flag = false;

    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++) {
            PX = X + (1 << (K - 1)) * i, PY = Y + (1 << (K - 1)) * j;
            if (A < PX && B < PY && !flag)
                dnc(PX - (1 << (K - 1)), PY - (1 << (K - 1)), K - 1, A, B), flag = true;
            else {
                VX = X + (1 << (K - 1)) + i - 2, VY = Y + (1 << (K - 1)) + j - 2;
                ans[VX][VY] = V;
                dnc(PX - (1 << (K - 1)), PY - (1 << (K - 1)), K - 1, VX, VY);
            }
        }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, X, Y;

    cin >> K >> X >> Y, X--, Y--;
    swap(X, Y), X = (1 << K) - 1 - X;

    dnc(0, 0, K, X, Y), ans[X][Y] = -1;

    for (int i = 0; i < (1 << K); i++, cout << '\n')
        for (int j = 0; j < (1 << K); j++)
            cout << ans[i][j] << ' ';

    return 0;
}