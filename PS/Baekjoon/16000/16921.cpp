#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[12] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    if (N <= 11)
        cout << dp[N] << '\n';
    else
        cout << dp[11] + (N - 11) * 49 << '\n';

    return 0;
}