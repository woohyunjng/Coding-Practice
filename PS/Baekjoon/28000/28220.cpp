#include <bits/stdc++.h>
#define int long long

#define MAX 104
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], dp[MAX][MAX][MAX * MAX], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, R, res = INF;
    cin >> N >> L >> R;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] -= L, sm[i] = sm[i - 1] + A[i];
    }
    R -= L;

    if (sm[N] < 0 || sm[N] > R * N) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= R; j++)
            for (int k = 0; k <= R * N; k++)
                dp[i][j][k] = INF;

    for (int i = 0; i <= R; i++)
        dp[0][i][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= R; j++) {
            for (int k = 0; k <= R * i; k++) {
                dp[i][j][k] = j ? dp[i][j - 1][k] : INF;
                if (k >= j)
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - j] + abs(sm[i] - k));
            }
        }
    }

    cout << dp[N][R][sm[N]] << '\n';

    return 0;
}