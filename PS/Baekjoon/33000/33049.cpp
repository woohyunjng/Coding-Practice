#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int P3, P4, P0, N, X, Y;
    cin >> P3 >> P4 >> P0, N = P3 + P4 + P0;

    X = (P3 + 2) / 3, Y = (P4 + 3) / 4;
    while (3 * X <= N - 4 * Y) {
        if ((N - 3 * X) % 4 == 0) {
            cout << X << ' ' << (N - 3 * X) / 4 << '\n';
            return 0;
        }
        X++;
    }

    cout << -1 << '\n';

    return 0;
}