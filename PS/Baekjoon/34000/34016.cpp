#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, ans, X[2], Y[2];

    cin >> N >> M;

    ans = N + (N + 1) * N / 2 - 2;

    if (M == 1) {
        cin >> X[0] >> Y[0];
        if (X[0] == 1 && Y[0] == 2)
            ans += 3 + Y[0] - 1 - Y[0];
        else if (X[0] == 1)
            ans += 2 + Y[0] - 1 - Y[0];
    } else if (M == 2) {
        cin >> X[0] >> Y[0] >> X[1] >> Y[1];
        if (X[0] == 1 && X[1] == 1) {
            if (Y[0] > Y[1])
                swap(Y[0], Y[1]);
            ans -= 2 + Y[0] + Y[1];
            if (Y[0] == 2 && Y[1] == 3)
                ans += min(4 + Y[0] + 4 + Y[1], 4 + Y[0] + Y[0] + Y[1]);
            else if (Y[0] == 2)
                ans += min(3 + Y[0] + 3 + Y[1], 3 + Y[0] + Y[0] + Y[1]);
            else
                ans += min(2 + Y[0] + 2 + Y[1], 2 + Y[0] + Y[0] + Y[1]);
        } else if (X[0] == 1 || X[1] == 1) {
            if (X[0] != 1)
                swap(X[0], X[1]), swap(Y[0], Y[1]);
            swap(X[0], Y[0]);
            ans -= 1 + X[0];
            if (X[0] != X[1] && X[0] != Y[1]) {
                if (X[0] == 2)
                    ans += 3 + X[0];
                else
                    ans += 2 + X[0];
            } else {
                if (X[0] == X[1])
                    swap(X[1], Y[1]);
                if (X[0] == 2) {
                    if (X[1] == 3)
                        ans += 4 + X[0];
                    else
                        ans += 3 + X[0];
                } else {
                    if (X[1] == 2) {
                        if (X[0] == 3)
                            ans += 4 + X[0];
                        else
                            ans += 3 + X[0];
                    } else
                        ans += 2 + X[0];
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}