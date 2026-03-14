#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    if (N == 1)
        cout << -1 << '\n';
    else {
        cout << 1 << ' ';
        for (int i = 2; i <= N; i++)
            cout << ((N << 1) + (i - 1)) << ' ' << ((N << 1) - (i - 1)) << ' ' << (i == N ? N * 2 : i + 1) << ' ';
        cout << 2 << ' ' << N * 3 << '\n';
    }

    return 0;
}