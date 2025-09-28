#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    if (N == 2)
        cout << -1 << '\n';
    else if (N == 3)
        cout << 2 << ' ' << 5 << ' ' << 29 << '\n';
    else if (N == 4)
        cout << 2 << ' ' << 2 << ' ' << 3 << ' ' << 17 << '\n';
    else if (N == 6)
        cout << 2 << ' ' << 2 << ' ' << 3 << ' ' << 3 << ' ' << 3 << ' ' << 5 << '\n';
    else if (N % 2 == 1) {
        for (int i = 1; i <= 3; i++)
            cout << 2 << ' ';
        for (int i = 1; i <= N - 3; i++)
            cout << 3 << ' ';
        cout << '\n';
    } else {
        for (int i = 1; i <= 6; i++)
            cout << 2 << ' ';
        for (int i = 1; i <= N - 6; i++)
            cout << 3 << ' ';
        cout << '\n';
    }

    return 0;
}