#include <bits/stdc++.h>
#define int long long
#define MAX 1510

using namespace std;

int A[MAX][MAX], sum[2][MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, Z;
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            cin >> A[i][j], sum[0][i][j] = A[i][j];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            sum[0][i][j] += sum[0][i - 1][j] + sum[0][i][j - 1] - sum[0][i - 1][j - 1];
            sum[1][i][j] = sum[1][i - 1][j - 1] + sum[0][i][j] - sum[0][i - 1][j];
        }

    cin >> Q;
    while (Q--) {
        cin >> X >> Y >> Z;
        cout << sum[1][X + Z - 1][Y + Z - 1] - sum[1][X - 1][Y - 1] - sum[0][X + Z - 1][Y - 1] + sum[0][X - 1][Y - 1] << '\n';
    }

    return 0;
}
