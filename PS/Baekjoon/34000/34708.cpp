#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N, K, ans;

    cin >> N >> K;

    if (N * 2 > K)
        ans = -1;
    else if (N * 2 == K)
        ans = N * 2 - 1;
    else
        ans = N * 2;

    cout << ans << '\n';

    return 0;
}
