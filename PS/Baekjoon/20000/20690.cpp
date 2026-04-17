#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, V, X = 0, Y = 1;

    cin >> N, N--;
    while (N--) {
        cin >> V;
        if (!V)
            X++, Y = max(Y, X);
        else
            X = 1, Y = min(Y, 2);
    }

    cout << Y << '\n';

    return 0;
}