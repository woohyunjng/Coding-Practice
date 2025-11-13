#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cout << (N + 1) / 2 << ' ' << i << '\n';
    }

    return 0;
}