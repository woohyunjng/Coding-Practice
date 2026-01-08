#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 3001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int X[MAX];
vector<int> R[MAX];
vector<pr> dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, V, ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> X[i];

    for (int i = 1; i <= N; i++) {
        K = X[i], R[i].push_back(0);
        for (int j = i + 1; j <= N; j++) {
            V = min(X[j] - K, (j == N ? INF : X[j + 1]) - X[j]), K = X[j] + V;
            R[j].push_back(V);
        }

        K = X[i];
        for (int j = i - 1; j >= 1; j--) {
            V = min(K - X[j], X[j] - (j == 1 ? -INF : X[j - 1])), K = X[j] - V;
            R[j].push_back(V);
        }
    }

    for (int i = 1; i <= N; i++) {
        sort(R[i].begin(), R[i].end()), R[i].erase(unique(R[i].begin(), R[i].end()), R[i].end());
        if (i == 1) {
            for (int j : R[i])
                dp[i].push_back({X[i] + j, j * j});
        } else {
            K = (int)dp[i - 1].size() - 1;
            for (int j : R[i]) {
                while (K > 0 && dp[i - 1][K][0] > X[i] - j)
                    K--;
                dp[i].push_back({X[i] + j, dp[i - 1][K][1] + j * j});
            }
        }

        for (int j = 1; j < (int)dp[i].size(); j++)
            dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][1]);
    }

    for (pr i : dp[N])
        ans = max(ans, i[1]);
    cout << ans << '\n';

    return 0;
}