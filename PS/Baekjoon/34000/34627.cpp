#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int N, R[2], C[2], ans = 0, DX = 0, DY = 0;

    cin >> N >> R[0] >> C[0] >> R[1] >> C[1];

    if (C[0] != C[1])
        DX = C[0] > C[1] ? N - C[1] : C[1];
    if (R[0] != R[1])
        DY = R[0] > R[1] ? N - R[1] : R[1];

    ans = DX + DY;
    if (R[0] != R[1] && C[0] != C[1])
        ans -= min(DX, DY);

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