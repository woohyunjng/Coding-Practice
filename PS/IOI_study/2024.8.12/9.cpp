#include <bits/stdc++.h>
#define int long long

#define MAX 5000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX], str[MAX];
vector<int> arr[30];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, res, X;
    string A, B, lcs;

    cin >> T;

    while (T--) {
        cin >> A;
        cin >> B;
        N = A.size(), M = B.size();

        for (int i = 1; i <= 26; i++)
            arr[i].clear();

        for (int i = 1; i <= N; i++)
            arr[A[i - 1] - 'a' + 1].push_back(i);
        for (int i = 1; i <= M; i++)
            str[i] = B[i - 1] - 'a' + 1;

        res = 0;

        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= 2 && !dp[i - 1][j - 1])
                    continue;
                X = lower_bound(arr[str[i]].begin(), arr[str[i]].end(), dp[i - 1][j - 1] + 1) - arr[str[i]].begin();
                if (X == arr[str[i]].size())
                    continue;
                if (dp[i][j])
                    dp[i][j] = min(dp[i][j], arr[str[i]][X]);
                else
                    dp[i][j] = arr[str[i]][X];
                res = max(res, j);
            }
        }

        cout << res << '\n';
        if (res) {
            lcs.clear();
            for (int i = M; i >= 1; i--) {
                if (dp[i][res] != dp[i - 1][res]) {
                    lcs.push_back(B[i - 1]);
                    res--;
                }
            }
            reverse(lcs.begin(), lcs.end());
            cout << lcs << '\n';
        }

        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= M; j++) {
                dp[i][j] = 0;
            }
            str[i] = 0;
        }
    }

    return 0;
}