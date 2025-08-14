#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, N, X, Y;

    cin >> Q;
    while (Q--) {
        cin >> N >> X >> Y;
        if (N * Y % (X + Y) == 0) {
            cout << 1 << '\n';
            cout << N * Y / (X + Y) << ' ' << X + Y << '\n';
        } else {
            cout << 2 << '\n';
            cout << N * Y / (X + Y) << ' ' << X + Y - N * Y % (X + Y) << '\n';
            cout << N * Y / (X + Y) + 1 << ' ' << N * Y % (X + Y) << '\n';
        }
    }

    return 0;
}