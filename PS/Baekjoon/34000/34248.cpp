#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, V = 0;

    cin >> N;
    while (N--) {
        cin >> X;
        V += (X == 1 ? 1 : -1);
    }

    cout << (V >= 0 && V % 3 == 0 ? "Yes" : "No") << '\n';

    return 0;
}
