#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int N, M, res;
    cin >> N >> M;

    res = max(N, M) + 1;
    cout << res << '\n';
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