#include <bits/stdc++.h>
using namespace std;

void solve() {
    int A, B, C, D;
    bool ans;

    cin >> A >> B >> C >> D;
    ans = A == B && B == C && C == D;

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