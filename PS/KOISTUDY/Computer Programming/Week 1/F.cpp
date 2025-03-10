#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A[4], ans;

    cin >> A[0] >> A[1] >> A[2] >> A[3];
    sort(A, A + 4);

    ans = max(0, 15000 - A[2]);
    ans = min(ans, max(0, 10000 - A[0]));

    cout << ans << '\n';

    return 0;
}