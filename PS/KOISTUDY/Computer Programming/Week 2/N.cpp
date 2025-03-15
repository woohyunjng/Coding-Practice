#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans = 1;

    cin >> N >> K;
    for (int i = 1; i <= K; i++)
        ans = ans * (N - K + i) / i;
    cout << ans << '\n';

    return 0;
}