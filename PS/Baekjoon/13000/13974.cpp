#include <bits/stdc++.h>
#define int long long

#define MAX 5010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX], A[MAX][MAX], arr[MAX], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X;
    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            sm[i] = sm[i - 1] + arr[i];
            A[i][i] = i;
        }

        for (int i = 2; i <= N; i++) {
            for (int j = 1; j + i - 1 <= N; j++) {
                dp[j][j + i - 1] = INF;

                for (int k = A[j][j + i - 2]; k <= min(j + i - 1, A[j + 1][j + i - 1]); k++) {
                    X = dp[j][k] + dp[k + 1][j + i - 1] + sm[j + i - 1] - sm[j - 1];
                    if (dp[j][j + i - 1] > X) {
                        dp[j][j + i - 1] = X;
                        A[j][j + i - 1] = k;
                    }
                }
            }
        }

        cout << dp[1][N] << '\n';

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = 0;
                A[i][j] = 0;
            }
        }
    }

    return 0;
}