#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S, T;
    int N;

    cin >> N >> S >> T;
    sort(S.begin(), S.end()), sort(T.begin(), T.end());

    cout << (S == T ? "YES" : "NO") << '\n';
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