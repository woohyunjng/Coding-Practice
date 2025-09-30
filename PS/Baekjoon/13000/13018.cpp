#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;

    cin >> N >> K;

    if (N == K) {
        cout << "Impossible" << '\n';
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        if (i <= N - K)
            cout << i % (N - K) + 1 << ' ';
        else
            cout << i << ' ';
    }
    cout << '\n';

    return 0;
}