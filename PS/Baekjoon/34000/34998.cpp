#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, ans;
    char C;

    cin >> T;
    while (T--) {
        cin >> N, ans = 0;
        for (int i = 0; i < (N << 1 | 1); i++) {
            cin >> C;
            if (i % 2 == 0)
                ans += (C == '!' ? 10 : C - '0');
        }
        cout << (ans >= 10 ? '!' : (char)('0' + ans)) << '\n';
    }

    return 0;
}