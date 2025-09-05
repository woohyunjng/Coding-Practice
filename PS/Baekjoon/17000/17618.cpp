#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, V, ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        X = i, V = 0;
        while (X)
            V += X % 10, X /= 10;
        ans += i % V == 0;
    }

    cout << ans << '\n';

    return 0;
}