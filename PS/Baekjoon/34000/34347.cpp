#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;

    cin >> T;
    while (T--) {
        cin >> N;

        if (N == 2) {
            cout << "YES" << '\n';
            cout << 1 << ' ' << 2 << '\n';
            cout << 1 << ' ' << 2 << '\n';
        } else if (N == 4) {
            cout << "YES" << '\n';
            cout << 2 << ' ' << 4 << ' ' << 1 << ' ' << 3 << '\n';
            cout << 2 << ' ' << 3 << ' ' << 1 << ' ' << 4 << '\n';
        } else
            cout << "NO" << '\n';
    }

    return 0;
}