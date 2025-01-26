#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int N, res = 0;
    string S;

    cin >> S, N = S.size();

    for (char i : S)
        res += i - '0';

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