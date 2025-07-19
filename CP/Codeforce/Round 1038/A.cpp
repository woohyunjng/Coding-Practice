#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    bool ans = true;

    cin >> N >> M;

    if (N == 1 || M == 1)
        ans = false;
    else if (N == 2 && M == 2)
        ans = false;

    cout << (ans ? "YES" : "NO") << '\n';
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