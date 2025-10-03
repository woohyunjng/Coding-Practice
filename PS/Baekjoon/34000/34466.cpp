#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A, B, C, D, ans = 2e9;

    cin >> A >> B >> C >> D;
    ans = min(ans, A + C + max(B, D));
    ans = min(ans, B + D + max(A, C));
    ans <<= 1;
    cout << ans << '\n';

    return 0;
}