#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, C[4] = {0}, ans = 0;

    cin >> N;
    while (N--)
        cin >> X, C[X - 1]++;

    ans = C[3] + C[2] + C[1] / 2;
    C[0] -= C[2], C[1] %= 2;

    if (C[1])
        ans++, C[0] -= 2;
    if (C[0] > 0)
        ans += (C[0] + 3) / 4;

    cout << ans << '\n';

    return 0;
}