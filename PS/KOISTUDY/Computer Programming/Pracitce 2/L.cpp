#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, cnt, ans, X, Y;

    cin >> N >> M >> K;

    if (N != K - 1) {
        cout << "impossible." << '\n';
        return 0;
    }

    cnt = 1, ans = 0, X = 1, Y = 0;

    if (N > 0) {
        for (int i = 0; i < 20; i++) {
            ans++;
            if (N > (1 << i))
                N -= 1 << i, cnt <<= 1;
            else {
                X = N + cnt, Y = cnt - N;
                break;
            }
        }
    }

    if (M <= Y) {
        cout << ans << '\n';
        return 0;
    }
    M -= Y;

    ans += (M + X - 1) / X;
    cout << ans << '\n';
}