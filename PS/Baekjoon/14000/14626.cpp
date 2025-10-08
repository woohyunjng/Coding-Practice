#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    int V, K, ans = 0;

    cin >> S;
    for (int i = 0; i < 13; i++) {
        if (S[i] == '*')
            V = i;
        else
            K = S[i] - '0', ans += K * (i % 2 ? 3 : 1);
    }

    ans = (10 - ans % 10) % 10;
    if (V % 2)
        ans = (ans * 7) % 10;

    cout << ans << '\n';

    return 0;
}