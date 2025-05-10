#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, X, Y, ans;

    cin >> Q;
    while (Q--) {
        cin >> X >> Y, ans = 2;

        if (X >= 0 && Y == 0)
            ans = 0;
        else if (X >= 0 || X >= Y || Y == 0)
            ans = 1;

        cout << ans << '\n';
    }

    return 0;
}