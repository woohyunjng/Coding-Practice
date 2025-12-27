#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

void solve() {
    string S;
    int C = 0;

    cin >> S;
    for (char i : S)
        C += i == 'Y';
    cout << (C > 1 ? "NO" : "YES") << '\n';
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