#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2000;

int A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans = 0, K;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    sort(A + 1, A + N + 1), sort(B + 1, B + N + 1);

    for (X = 1, Y = 1; X <= N; X++) {
        while (Y <= N && B[Y] < A[X])
            Y++;
        if (Y == N + 1)
            K = A[X] - B[Y - 1];
        else if (Y == 1)
            K = B[Y] - A[X];
        else
            K = min(B[Y] - A[X], A[X] - B[Y - 1]);
        ans = max(ans, K);
    }

    cout << ans << '\n';

    return 0;
}