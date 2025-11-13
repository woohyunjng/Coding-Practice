#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int N, ans = 0;

    cin >> N;
    while (N)
        ans += N, N >>= 1;
    cout << ans << '\n';

    return 0;
}