#include <bits/stdc++.h>
#define int long long

#define MAX 510
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX], A[MAX], B[MAX], sm_A[MAX], sm_B[MAX], dp_sm[MAX][MAX][MAX];
vector<pair<double, int>> arr_A[MAX], arr_B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sm_A[i] = sm_A[i - 1] + A[i];

        for (int j = 1; j <= i; j++)
            arr_A[i].push_back({(double)(sm_A[i] - sm_A[j - 1]) / (i - j + 1), j});
        sort(arr_A[i].begin(), arr_A[i].end());
    }

    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        sm_B[i] = sm_B[i - 1] + B[i];

        for (int j = 1; j <= i; j++)
            arr_B[i].push_back({(double)(sm_B[i] - sm_B[j - 1]) / (i - j + 1), j});
        sort(arr_B[i].begin(), arr_B[i].end());
    }

    dp[0][0] = 1;

    for (int j = 1; j <= N; j++) {
        for (int i = 0; i <= N; i++) {
            for (int X = 0, Y = 0; X < i; X++) {
                while (Y < j && arr_A[i][X].first > arr_B[j][Y].first)
                    Y++;
                dp[i][j] = (dp[i][j] + dp_sm[arr_A[i][X].second - 1][j][j - 1] - (Y ? dp_sm[arr_A[i][X].second - 1][j][Y - 1] : 0) + MOD) % MOD;
            }
            dp_sm[i][j][0] = dp[i][arr_B[j][0].second - 1];
            for (int k = 1; k < j; k++)
                dp_sm[i][j][k] = (dp_sm[i][j][k - 1] + dp[i][arr_B[j][k].second - 1]) % MOD;
        }
    }

    cout << dp[N][N];

    return 0;
}