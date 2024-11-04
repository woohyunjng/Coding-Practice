#include <bits/stdc++.h>
#define int long long

#define MAX 200010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

pr max(pr A, pr B) {
    if (A.first == B.first)
        return {A.first, max(A.second, B.second)};
    else if (A.first > B.first)
        return A;
    else
        return B;
}

pr dp[MAX][6];
int cost[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, val = 0, sm = 0;
    string S, K = "bessie";

    pr tmp;

    cin >> S;
    N = S.size();

    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        sm += cost[i];
    }

    for (int i = 0; i < 6; i++)
        dp[0][i] = {-1, 0};

    dp[0][5] = {0, 0};

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 6; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j == 5)
                dp[i][j].second += cost[i];

            if (S[i - 1] != K[j])
                continue;
            X = (j == 0) ? 5 : j - 1;
            if (dp[i - 1][X].first == -1)
                continue;

            tmp = {dp[i - 1][X].first, dp[i - 1][X].second + cost[i]};
            if (j == 5)
                tmp.first++;

            dp[i][j] = max(dp[i][j], tmp);
        }
    }

    cout << dp[N][5].first << '\n'
         << sm - dp[N][5].second << '\n';

    return 0;
}