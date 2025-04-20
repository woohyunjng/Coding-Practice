#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int N, X, Y, ansX = 0, ansY = 0;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X >> Y, Y += X;
        ansX ^= X, ansY ^= Y;
    }
    ansY -= ansX;
    cout << ansX << ' ' << ansY << '\n';
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