#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int A[MAX], ans[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, Y;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    X = Y = A[1], ans[1] = 1;

    for (int i = 2; i <= N; i++) {
        if (A[i] <= Y)
            ans[i] = A[i] + K >= Y;
        else if (A[i] >= X)
            ans[i] = A[i] - K <= X;
        else
            ans[i] = 1;
        if (ans[i])
            X = max(X, A[i]), Y = min(Y, A[i]);
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}