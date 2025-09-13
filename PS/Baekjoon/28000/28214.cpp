#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, P, X, V, ans = 0;

    cin >> N >> K >> P;
    for (int i = 1; i <= N; i++) {
        V = 0;
        for (int j = 1; j <= K; j++)
            cin >> X, V += !X;
        ans += V < P;
    }
    cout << ans << '\n';

    return 0;
}