#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

void solve() {
    int N, ans = 0, L, R, X;
    string S;

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            ans++;
            continue;
        }

        L = R = i;
        while (R + 1 < N && S[R + 1] == '0')
            R++;
        X = R - L + 1;

        if (L == 0 && R == N - 1)
            ans += (X + 2) / 3;
        else if (L == 0 || R == N - 1)
            ans += (X + 1) / 3;
        else
            ans += X / 3;
        i = R;
    }

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