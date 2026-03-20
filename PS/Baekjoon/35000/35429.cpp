#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, G = 0, S = 0, H = 0, ans; // 해시함수??
    string C;

    cin >> N >> C;
    for (char i : C) {
        if (i == 'G')
            G++;
        else if (i == 'S')
            S++;
        else if (i == 'H')
            H++;
    }

    ans = min({G, S / 2, H}), cout << ans << '\n';

    return 0;
}