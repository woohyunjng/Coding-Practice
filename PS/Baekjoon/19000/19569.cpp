#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N, X;

    cin >> N;

    if (N % 5 != 1 && N % 5 != 4) {
        cout << "NO" << '\n', cout.flush();
        return 0;
    }

    cout << "YES" << '\n', cout.flush();
    cout << 1 << '\n', cout.flush(), N--;

    if (N % 5 == 3) {
        cin >> X, N -= X;
        cout << 3 - X << '\n', cout.flush(), N -= 3 - X;
    }

    while (N) {
        cin >> X;
        if (X == 1) {
            cout << 1 << '\n', cout.flush();
            cin >> X;
            cout << 3 - X << '\n', cout.flush();
        } else
            cout << 5 - X << '\n', cout.flush();
        N -= 5;
    }

    return 0;
}