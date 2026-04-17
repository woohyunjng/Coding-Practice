#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, X, N, K, A;
    bool res = true, flag;

    cin >> T >> X >> N;
    for (int i = 1; i <= N; i++) {
        cin >> K, flag = false;
        while (K--)
            cin >> A, flag |= (A == X);
        res &= flag;
    }

    cout << (res ? "YES" : "NO") << '\n';

    return 0;
}
