#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5001;

int ans[2][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, L, R;

    cin >> N, L = 0, R = N - 1;
    M = N;

    if (N % 4 == 2 || N % 4 == 3) {
        cout << -1 << '\n';
        return 0;
    }

    while (N >= 4) {
        ans[0][L] = ans[1][R] = N;
        ans[1][L] = ans[0][R - 1] = N - 1;
        ans[0][L + 1] = ans[0][R] = N - 2;
        ans[1][L + 1] = ans[1][R - 1] = N - 3;

        N -= 4, L += 2, R -= 2;
    }

    if (N == 1)
        ans[0][L] = ans[1][L] = 1;

    for (int i = 0; i < 2; i++, cout << '\n')
        for (int j = 0; j < M; j++)
            cout << ans[i][j] << ' ';

    return 0;
}