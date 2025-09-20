#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int X, Y, ans = -1;

    cin >> X >> Y;

    if (X < Y)
        ans = 2;
    else if (Y + 2 <= X && Y >= 2)
        ans = 3;

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