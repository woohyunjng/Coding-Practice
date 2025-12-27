#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, S, ans = 0;

    cin >> H >> S;

    if (H <= 2)
        ans = 1;
    else if (H <= 4)
        ans = S + 2;
    else
        ans = S + (H + S + 1) / 2;

    cout << ans << '\n';

    return 0;
}