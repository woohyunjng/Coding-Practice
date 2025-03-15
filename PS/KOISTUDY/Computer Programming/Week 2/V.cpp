#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 13;

int X[MAX], Y[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, W, ans = 10000000, val, A[2], B[2];

    cin >> N >> W;
    for (int i = 0; i < W; i++)
        cin >> X[i] >> Y[i];

    for (int i = 0; i < (1 << W); i++) {
        A[0] = A[1] = 1, B[0] = B[1] = N, val = 0;
        for (int j = 0; j < W; j++) {
            if (i & (1 << j)) {
                val += abs(A[0] - X[j]) + abs(A[1] - Y[j]);
                A[0] = X[j], A[1] = Y[j];
            } else {
                val += abs(B[0] - X[j]) + abs(B[1] - Y[j]);
                B[0] = X[j], B[1] = Y[j];
            }
        }
        ans = min(ans, val);
    }

    cout << ans << '\n';

    return 0;
}