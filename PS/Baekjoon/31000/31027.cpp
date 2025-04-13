#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int A[2][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans, X, Y, Z, S = 0;

    cin >> N, X = Y = Z = 0;
    for (int i = 1; i <= N; i++)
        cin >> A[0][i], S += A[0][i];
    for (int i = 1; i <= N; i++)
        cin >> A[1][i], S += A[1][i];

    for (int i = 1; i <= N / 2; i++)
        X += A[0][i] + A[1][i];
    for (int i = 1; i <= N; i++)
        Y += A[0][i];
    for (int i = 1; i <= N / 2 + 1; i++)
        Z += A[0][i] + A[1][i];

    ans = max(X, min(Y, Z));
    cout << ans << ' ' << S - ans << '\n';

    return 0;
}