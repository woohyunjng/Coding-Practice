#include <bits/stdc++.h>
#define int long long
#define double long double

#define MAX 510
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], B[MAX];
double dp[MAX][MAX];
bool vst[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, Y;
    vector<int> arr_A, arr_B;
    double res = INF, val;

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        arr_A.push_back(i), arr_B.push_back(i);
    }

    sort(arr_A.begin(), arr_A.end(), [&](int a, int b) { return A[a] < A[b]; });
    sort(arr_B.begin(), arr_B.end(), [&](int a, int b) { return (B[a] == -1 ? INF : B[a]) < (B[b] == -1 ? INF : B[b]); });

    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= N; j++)
            for (int k = 0; k <= N; k++)
                dp[j][k] = INF;
        dp[0][0] = 0;

        for (int j = 1; j <= K; j++) {
            if (B[arr_B[j - 1]] == -1)
                break;

            dp[j][0] = dp[j - 1][0] + (double)B[arr_B[j - 1]] / j;
            for (int k = 1; k <= j; k++) {
                if (k != j)
                    dp[j][k] = min(dp[j - 1][k] + (double)B[arr_B[j - 1]] / (j - k), dp[j - 1][k - 1] + (double)A[arr_B[j - 1]] / (i + 1));
                else
                    dp[j][k] = dp[j - 1][k - 1] + (double)A[arr_B[j - 1]] / (i + 1);
            }
        }

        for (int j = 0; i + j <= K; j++) {
            fill(vst, vst + N + 1, false);
            val = dp[i + j][j];

            for (int k = 0; k < i + j; k++)
                vst[arr_B[k]] = true;

            X = 0;
            for (int k = 0; k < N && X < K - i - j; k++) {
                if (!vst[arr_A[k]])
                    val += (double)A[arr_A[k]] / (i + 1), X++;
            }

            res = min(res, val);
        }
    }

    cout << fixed << setprecision(10) << res << endl;

    return 0;
}