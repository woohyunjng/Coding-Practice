#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T[4];

    cin >> T[0] >> T[1] >> T[2] >> T[3];
    cout << (T[0] + T[1] + T[2] + T[3] + 300 <= 1800 ? "Yes" : "No") << '\n';

    return 0;
}