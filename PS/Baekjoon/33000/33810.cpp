#include <bits/stdc++.h>
using namespace std;

string S = "SciComLove";

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int ans = 0;
    string T;

    cin >> T;
    for (int i = 0; i < 10; i++)
        ans += S[i] != T[i];

    cout << ans << '\n';

    return 0;
}