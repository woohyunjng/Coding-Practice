#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int L = 1, R = 1'000'000'000, X, T = 0;

    while (T < 100 && L < R) {
        cin >> X, T++;
        if (X - L < R - X)
            cout << '>' << '\n', cout.flush(), L = max(L, X + 1);
        else
            cout << '<' << '\n', cout.flush(), R = min(R, X - 1);
    }

    while (T < 100) {
        cin >> X, T++;
        if (X == L) {
            cout << '=' << '\n', cout.flush();
            return 0;
        } else if (X < L)
            cout << '>' << '\n', cout.flush();
        else
            cout << '<' << '\n', cout.flush();
    }

    return 0;
}