#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A, B, C, D, X, res;
    cin >> A >> B >> C >> D;

    X = A + B + C + D - 2;
    res = X % 4 + 1;

    cout << res << '\n';

    return 0;
}