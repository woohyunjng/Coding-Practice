#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, K, D, A, B;

    cin >> T;
    while (T--) {
        cin >> N >> M >> K >> D;

        D = D * 2 / (M * N);
        B = D / ((M - 1) * K + M * (N - 1)), A = B * K;

        if (B == 0)
            cout << -1 << '\n';
        else
            cout << ((M - 1) * A + M * (N - 1) * B) * M * N / 2 << '\n';
    }

    return 0;
}