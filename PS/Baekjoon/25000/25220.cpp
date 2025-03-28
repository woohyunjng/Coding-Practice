#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;

int B[MAX], P[MAX], U[MAX], L[MAX], R[MAX], V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0, Y, ans = 0;
    bool flag = true;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> B[i];
    for (int i = 1; i < N; i++)
        cin >> P[i];
    for (int i = 1; i < N; i++)
        cin >> U[i];

    for (int i = 1; i < N; i++) {
        L[i] = min(B[i], P[i]), B[i] -= L[i], P[i] -= L[i];
        R[i] = min(B[i + 1], P[i]), B[i + 1] -= R[i], P[i] -= R[i];
        ans += P[i];
    }

    for (int i = N - 1; i >= 1; i--) {
        flag &= R[i] >= X;
        R[i] -= X, L[i + 1] += X;
        X += P[i], Y = min(X, U[i]);
        X -= Y, V[i] += Y;
    }
    flag &= X == 0;

    if (flag) {
        cout << "YES" << '\n';
        cout << ans << '\n';

        for (int i = 1; i < N; i++)
            cout << L[i] << ' ' << V[i] << ' ' << R[i] << '\n';
    } else
        cout << "NO" << '\n';

    return 0;
}