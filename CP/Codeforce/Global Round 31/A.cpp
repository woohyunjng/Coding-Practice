#include <bits/stdc++.h>
using namespace std;

void solve() {
    int L, A, B, X, ans = 0;

    cin >> L >> A >> B, ans = X = A;
    X = (A + B) % L;
    while (X != A)
        ans = max(ans, X), X = (X + B) % L;
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