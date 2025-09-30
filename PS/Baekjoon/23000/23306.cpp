#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, E, ans;
    cin >> N;

    cout << "? " << 1 << '\n', cout.flush();
    cin >> S;

    cout << "? " << N << '\n', cout.flush();
    cin >> E;

    if (S == E)
        ans = 0;
    else if (S == 0)
        ans = 1;
    else
        ans = -1;

    cout << "! " << ans << '\n', cout.flush();

    return 0;
}