#include <bits/stdc++.h>
#define double long double

using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int W, H, R;
    double ans;

    cin >> W >> H >> R;
    ans = W * H - R * R * acos(-1.0) / 4;
    cout << fixed << setprecision(6) << ans << '\n';

    return 0;
}