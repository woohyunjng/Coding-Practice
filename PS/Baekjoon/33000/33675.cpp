#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, ans;

    cin >> T;
    while (T--) {
        cin >> N;
        if (N % 2 == 0) {
            ans = 1;
            for (int i = 1; i <= N / 2; i++)
                ans *= 2;
        } else
            ans = 0;
        cout << ans << '\n';
    }

    return 0;
}