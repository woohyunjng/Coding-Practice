#include <bits/stdc++.h>
using namespace std;

int N, ans[2050][2050];

void dnc(int l, int r, int x, int y, int d) {
    if (l > r)
        return;
    int m = l + r >> 1;
    for (int i = x + d - 1; i <= y; i += d)
        if (m < N && i < N)
            ans[m][i] = 1;
    dnc(l, m - 1, x, y, d << 1), dnc(m + 1, r, x, y, d << 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, D = 0, X, Y;

    cin >> N >> K;
    while (!(K & 1))
        K >>= 1, D++;

    for (int i = 0; i * (1 << D) < N; i++)
        for (int j = 0; j * (1 << D) < N; j++) {
            X = i * (1 << D), Y = j * (1 << D);
            if (X + (1 << D) <= N && Y + (1 << D) <= N)
                ans[X + (1 << D) - 1][Y + (1 << D) - 1] = 1;
            dnc(X, X + (1 << D) - 2, Y, Y + (1 << D) - 2, 1);
        }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}