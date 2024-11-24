#include <bits/stdc++.h>
#define int long long

#define MAX_N 100100
#define MAX_M 30
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dis[MAX_M][MAX_M], cost[MAX_N][MAX_M], cost_sm[MAX_N][MAX_M], dp[MAX_N][MAX_M], res[MAX_N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K;
    string S;

    cin >> N >> M >> K >> S;

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= M; j++)
            cin >> dis[i][j];

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= M; j++)
            for (int k = 1; k <= M; k++)
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cost[i][j] = dis[S[i - 1] - 'a' + 1][j];
            cost_sm[i][j] = cost_sm[i - 1][j] + cost[i][j];
        }
    }

    fill(&dp[0][0], &dp[N][M], INF), fill(res, res + N + 1, INF);
    res[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = dp[i - 1][j] + cost[i][j];
            if (i >= K)
                dp[i][j] = min(dp[i][j], res[i - K] + cost_sm[i][j] - cost_sm[i - K][j]);
            res[i] = min(res[i], dp[i][j]);
        }
    }

    cout << res[N] << '\n';

    return 0;
}