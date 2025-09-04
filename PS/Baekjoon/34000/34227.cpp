#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, A, B, X, ans;
    bool flag;

    cin >> T;
    while (T--) {
        cin >> A >> B, A--, B--;
        ans = 0, flag = false;

        for (int i = 62; i >= 0; i--) {
            flag |= (B & (1ll << i)) != 0 && (A & (1ll << i)) != 0;
            if ((A & (1ll << i)) == (B & (1ll << i)))
                ans += flag && (((A & (1ll << i)) >> i) ^ 1);
            else {
                ans++, X = ((1ll << (i + 1)) - 1);
                if (!flag || (B & X) == X)
                    ans--;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}