#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int K, X, Y, tmpX, tmpY;
    vector<int> ans;

    cin >> K >> X, Y = (1ll << (K + 1)) - X;

    while (X != Y) {
        if (X > Y)
            ans.push_back(2), tmpX = X - Y, tmpY = Y * 2;
        else
            ans.push_back(1), tmpX = X * 2, tmpY = Y - X;
        X = tmpX, Y = tmpY;
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
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