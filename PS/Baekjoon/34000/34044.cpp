#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;

    if (N == 1)
        cout << -1 << '\n';
    else if (N % 2 == 0) {
        while (N >= 2)
            cout << 1331, N -= 2;
        cout << '\n';
    } else {
        cout << 194183, N -= 3;
        while (N >= 2)
            cout << 1331, N -= 2;
        cout << '\n';
    }

    return 0;
}

// (13, -2), (17, -6), (19, -8), (23, -1), (29, -7), (31, 2), (37, -4), (41, 3), (43, 1), (47, -3), (53, 2), (59, -4), (61, 5), (67, -1), (71, 6), (73, 4), (79, -2), (83, 5), (89, -1), (97, 2)
