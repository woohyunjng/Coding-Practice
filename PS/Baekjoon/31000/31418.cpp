#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;
const int MOD = 998244353;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int W, H, K, T, X, Y, A, B, C, D, V, ans = 1;

    cin >> W >> H >> K >> T;
    while (K--) {
        cin >> X >> Y;
        A = max(1ll, X - T), B = min(W, X + T);
        C = max(1ll, Y - T), D = min(H, Y + T);
        V = (B - A + 1) * (D - C + 1) % MOD, ans = ans * V % MOD;
    }

    cout << ans << '\n';

    return 0;
}