#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;

    cin >> N >> K;
    if (N == 1 && K == 2)
        cout << -1 << '\n';
    else if (K <= 1) {
        for (int i = 1; i <= N; i++)
            cout << K << ' ';
        cout << '\n';
    } else if (K == 2) {
        for (int i = 1; i < N; i++)
            cout << 0 << ' ';
        cout << 2 << '\n';
    } else {
        for (int i = 1; i <= K - 1; i++)
            cout << i - 1 << ' ';
        for (int i = K; i <= N; i++)
            cout << 0 << ' ';
        cout << '\n';
    }

    return 0;
}