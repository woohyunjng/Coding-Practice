#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0)
            cout << 4 << ' ';
        else if (i % 3 == 1)
            cout << 3 << ' ';
        else
            cout << 5 << ' ';
    }
    cout << '\n';

    if (N % 3 == 1 || N % 3 == 2) {
        cout << (N + 2) / 3 * 2 << '\n';

        for (int i = 1; i <= N / 3; i++) {
            cout << (i - 1) * 3 + 1 << ' ' << (i - 1) * 3 + 2 << '\n';
            cout << (i - 1) * 3 + 2 << ' ' << (i - 1) * 3 + 2 << '\n';
        }

        if (N % 3 == 1) {
            cout << N << ' ' << N << '\n';
            cout << 1 << ' ' << N << '\n';
        } else {
            cout << N - 1 << ' ' << N - 1 << '\n';
            cout << 1 << ' ' << N - 1 << '\n';
        }
    } else {
        cout << (N + 2) / 3 * 2 + 1 << '\n';
        for (int i = 1; i <= N / 3; i++) {
            cout << (i - 1) * 3 + 1 << ' ' << (i - 1) * 3 + 2 << '\n';
            cout << (i - 1) * 3 + 2 << ' ' << (i - 1) * 3 + 2 << '\n';
        }
        cout << 1 << ' ' << N << '\n';
    }

    return 0;
}