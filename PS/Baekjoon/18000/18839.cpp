#include <bits/stdc++.h>
#define int long long

#define MAX 1100000
using namespace std;

typedef array<int, 2> pr;

int A[MAX], B[MAX];
pr dp[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, Z;
    bool X, Y;
    string res;
    cin >> N;

    for (int i = 1; i <= N * 2; i++)
        cin >> A[i];
    for (int i = 1; i <= N * 2; i++)
        cin >> B[i];

    for (int i = 1; i <= N * 2; i++) {
        X = A[i] >= A[i - 1] && dp[i - 1][0][0] != -1;
        Y = A[i] >= B[i - 1] && dp[i - 1][1][0] != -1;

        if (X && Y)
            dp[i][0] = {min(dp[i - 1][0][0], dp[i - 1][1][0]), max(dp[i - 1][0][1], dp[i - 1][1][1])};
        else if (X)
            dp[i][0] = dp[i - 1][0];
        else if (Y)
            dp[i][0] = dp[i - 1][1];
        else
            dp[i][0] = {-1, -1};

        X = B[i] >= A[i - 1] && dp[i - 1][0][0] != -1;
        Y = B[i] >= B[i - 1] && dp[i - 1][1][0] != -1;

        if (X && Y)
            dp[i][1] = {min(dp[i - 1][0][0], dp[i - 1][1][0]) + 1, max(dp[i - 1][0][1], dp[i - 1][1][1]) + 1};
        else if (X)
            dp[i][1] = {dp[i - 1][0][0] + 1, dp[i - 1][0][1] + 1};
        else if (Y)
            dp[i][1] = {dp[i - 1][1][0] + 1, dp[i - 1][1][1] + 1};
        else
            dp[i][1] = {-1, -1};
    }

    if (!(dp[N * 2][0][0] <= N && N <= dp[N * 2][0][1]) && !(dp[N * 2][1][0] <= N && N <= dp[N * 2][1][1])) {
        cout << -1 << '\n';
        return 0;
    }

    K = N;
    for (int i = N * 2; i >= 1; i--) {
        if ((i == N * 2 || Z >= A[i]) && dp[i][0][0] != -1 && dp[i][0][0] <= K && K <= dp[i][0][1])
            res.push_back('A'), Z = A[i];
        else
            res.push_back('B'), K--, Z = B[i];
    }

    reverse(res.begin(), res.end());
    cout << res << '\n';

    return 0;
}