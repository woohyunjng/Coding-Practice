#include <bits/stdc++.h>
#define int long long

#define MAX 6000
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int V[MAX], A[MAX], C[MAX], dp[4][MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, st, en, mid, res = 0, K[4];
    bool flag;

    cin >> N >> X;
    for (int i = 1; i <= N; i++)
        cin >> V[i] >> A[i] >> C[i];

    for (int x = 1; x <= 3; x++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= X; j++) {
                dp[x][i][j] = max(dp[x][i - 1][j], dp[x][i][j - 1]);
                if (V[i] == x && j >= C[i])
                    dp[x][i][j] = max(dp[x][i][j], dp[x][i - 1][j - C[i]] + A[i]);
            }

    st = 0, en = INF;
    while (st <= en) {
        mid = st + en >> 1;
        K[1] = K[2] = K[3] = -1;

        for (int x = 1; x <= 3; x++)
            for (int i = 0; i <= X; i++) {
                if (dp[x][N][i] >= mid) {
                    K[x] = i;
                    break;
                }
            }

        if (K[1] == -1 || K[2] == -1 || K[3] == -1) {
            en = mid - 1;
            continue;
        }

        flag = K[1] + K[2] + K[3] <= X;
        if (flag)
            res = mid, st = mid + 1;
        else
            en = mid - 1;
    }

    cout << res << '\n';

    return 0;
}