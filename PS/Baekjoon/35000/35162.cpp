#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, K, C, P;
    bool ans;

    cin >> T;
    while (T--) {
        cin >> K >> C >> P, ans = true;
        ans &= (K + C + P) >= 2;
        if (K > 0)
            ans &= (C + P) >= 2 || (K == 1 && C >= 1);
        cout << (ans ? 'Y' : 'N') << '\n';
    }

    return 0;
}