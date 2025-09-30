#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, R;

    cin >> N, L = 1, R = N;
    for (int i = 0; L <= R; i++) {
        if (i & 1)
            cout << L++ << ' ';
        else
            cout << R-- << ' ';
    }
    cout << '\n';

    return 0;
}