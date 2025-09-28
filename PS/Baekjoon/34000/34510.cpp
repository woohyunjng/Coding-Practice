#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H[3], N, ans;

    cin >> H[0] >> H[1] >> H[2] >> N;
    ans = N * H[2] + (N + 1) / 2 * H[1] + (N % 2) * H[0];
    cout << ans << '\n';

    return 0;
}