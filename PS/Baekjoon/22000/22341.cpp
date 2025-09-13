#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C, X, Y, L, R;

    cin >> N >> C, L = R = N;
    while (C--) {
        cin >> X >> Y;
        if (X >= L || Y >= R)
            continue;
        if (X * R >= Y * L)
            L = X;
        else
            R = Y;
    }

    cout << L * R << '\n';

    return 0;
}