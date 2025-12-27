#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A, T, P, ans;

    cin >> A >> T;
    P = 10 + 2 * (25 - A + T);
    cout << max(0ll, P) << '\n';

    return 0;
}