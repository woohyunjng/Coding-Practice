#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X, Y;
    string S;

    cin >> T;
    while (T--) {
        cin >> S, N = S.size();
        X = Y = 0;

        for (int i = 0, j = N - 1;; i++, j--) {
            Y++;
            if (i >= j) {
                X = 1;
                break;
            } else if (S[i] != S[j])
                break;
        }

        cout << X << ' ' << Y << '\n';
    }

    return 0;
}