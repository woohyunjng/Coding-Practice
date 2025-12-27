#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, L, R, X, S;

    cin >> T;
    while (T--) {
        cin >> L >> R, X = max(L, (R + 1) / 2);
        cout << X << ' ', S = X;
        for (int i = R; i > X; i--)
            cout << (S > 0 ? -i : i) << ' ', S += (S > 0 ? -i : i);
        for (int i = X - 1; i >= L; i--)
            cout << (S > 0 ? -i : i) << ' ', S += (S > 0 ? -i : i);
        cout << '\n';
    }

    return 0;
}