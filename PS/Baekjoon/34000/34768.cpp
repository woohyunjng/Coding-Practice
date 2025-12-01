#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;

    cin >> N;

    for (int i = 1; i <= N; i++, cout << '\n')
        for (int j = 1; j <= N; j++) {
            X = (i - 1) * N + j;
            if (X & 1)
                cout << (X + 1) / 2 << ' ';
            else
                cout << (X / 2 + N * N / 2 - 2) % (N * N / 2) + 1 << ' ';
        }

    return 0;
}