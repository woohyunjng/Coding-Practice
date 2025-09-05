#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        X = i;
        while (X)
            ans += (X % 10 == 3 || X % 10 == 6 || X % 10 == 9), X /= 10;
    }

    cout << ans << '\n';

    return 0;
}