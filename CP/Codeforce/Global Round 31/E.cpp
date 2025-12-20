#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

void solve() {
    int L, R, V = 0, ans = 0;

    cin >> L >> R, V = 0;
    if (L == R) {
        cout << 0 << '\n';
        return;
    }

    for (int i = 60; i >= 0; i--) {
        if (((L >> i) & 1) != ((R >> i) & 1)) {
            V |= 1ll << i;
            break;
        } else
            V |= ((L >> i) & 1) << i;
    }

    if (L + R == (V << 1) - 1)
        ans += (R - V + 1) & -(R - V + 1);
    ans += min((V - L) & -(V - L), (R - V + 1) & -(R - V + 1)) - 1;
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}