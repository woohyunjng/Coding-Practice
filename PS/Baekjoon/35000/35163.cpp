#include <bits/stdc++.h>
#define int long long
using namespace std;

int calc1(int X) {
    X %= 4;
    if (X == 0)
        return 6;
    else if (X == 1)
        return 2;
    else
        return 4;
}

int calc2(int X) {
    X %= 5;
    if (X == 0 || X == 3)
        return 3;
    else if (X == 1)
        return 5;
    else if (X == 2)
        return 1;
    else
        return 4;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, X, Y, K, ans;

    cin >> T;
    while (T--) {
        cin >> X >> Y, X = abs(X), Y = abs(Y), ans = -1;
        if (X > Y)
            swap(X, Y);
        if ((X == 0 && Y == 0) || (X == 1 && Y == 2)) {
            cout << -1 << '\n';
            continue;
        }

        if (3 + 2 * X <= Y) {
            ans = calc1(Y - (3 + 2 * X));
            if (X == 0 && Y == 3)
                ans = 4;
        } else if (X == 0)
            ans = Y == 1 ? 6 : 2;
        else if (X == 1)
            ans = Y <= 3 ? 2 : 3;
        else if (Y >= -2 + 2 * X) {
            ans = calc2(Y - (-2 + 2 * X));
            if (X == 2 && Y == 2)
                ans = 8;
            else if (X == 3 && Y == 4)
                ans = 2;
        } else if (X == 3)
            assert(Y == 3), ans = 2;
        else {
            K = X % 3 == 0 ? 0 : (X % 3 == 1 ? 2 : 1);
            ans = ((K + (Y - X)) % 3 + 1) * 2;
        }

        cout << ans << '\n';
    }

    return 0;
}