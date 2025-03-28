#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, A, B, ans, X, Y;

    cin >> T;
    while (T--) {
        cin >> A >> B, ans = 0;
        for (int i = 0; i < 31; i++) {
            X = (1 << i) - 1, Y = min(X, A) - max(0ll, X - B) + 1;
            if (Y <= 0)
                break;
            ans += Y;
        }
        cout << ans << '\n';
    }

    return 0;
}