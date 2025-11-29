#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X[2], Y[2], ansX, ansY;

    cin >> X[0] >> Y[0] >> X[1] >> Y[1];

    if ((abs(X[0] - X[1]) + abs(Y[0] - Y[1])) & 1) {
        cout << -1 << '\n';
        return 0;
    }

    ansX = (X[0] + X[1]) / 2, ansY = (Y[0] + Y[1]) / 2;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++) {
            if (abs(X[0] - (ansX + i)) + abs(Y[0] - (ansY + j)) ==
                    abs(X[1] - (ansX + i)) + abs(Y[1] - (ansY + j)) &&
                abs(ansX + i) <= 1'000'000'000 && abs(ansY + j) <= 1'000'000'000) {
                cout << ansX + i << ' ' << ansY + j << '\n';
                return 0;
            }
        }

    return 0;
}