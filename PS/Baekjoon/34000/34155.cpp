#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 998244353;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 1, X;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X;
        ans *= N - (X == i ? 1 : 2), ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}