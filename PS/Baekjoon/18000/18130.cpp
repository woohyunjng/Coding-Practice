#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, P, K, C, X, ans = 0, mx_ans = -1, V;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> P >> K >> C, X = (Q - 1) / K;
        V = X * (X + 1) / 2 * C + P;
        if (mx_ans == -1 || V < mx_ans)
            ans = i, mx_ans = V;
    }

    cout << ans << ' ' << mx_ans << '\n';

    return 0;
}