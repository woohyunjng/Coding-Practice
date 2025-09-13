#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, L, R, S;

    cin >> T;
    while (T--) {
        cin >> L >> R >> S;
        cout << min((S - L) * 2, (R - S) * 2 - 1) + 1 << '\n';
    }

    return 0;
}