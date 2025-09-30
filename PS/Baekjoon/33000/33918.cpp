#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 201;
const int MAX_V = 25001;
const int INF = 2e9;

int A[MAX], dp[MAX][MAX_V], V[MAX_V];
deque<pr> lft[MAX_V], rgt[MAX_V];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, C, D, ans = INF;
    pr K;

    cin >> N >> M >> C >> D;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < C; j++)
            lft[j].clear(), rgt[j].clear(), V[j] = j - C;

        for (int j = 1; j <= M; j++) {
            while (V[j % C] < j + D && V[j % C] + C <= M) {
                V[j % C] += C, K = {dp[i - 1][V[j % C]], V[j % C]};
                while (!rgt[j % C].empty() && rgt[j % C].back()[0] >= K[0])
                    rgt[j % C].pop_back();
                rgt[j % C].push_back(K);
            }

            K = {dp[i - 1][j], j};
            while (!lft[j % C].empty() && lft[j % C].back()[0] >= K[0])
                lft[j % C].pop_back();
            lft[j % C].push_back(K);

            while (!rgt[j % C].empty() && rgt[j % C].front()[1] <= j)
                rgt[j % C].pop_front();
            while (!lft[j % C].empty() && lft[j % C].front()[1] < j - D)
                lft[j % C].pop_front();

            dp[i][j] = INF;
            if (!rgt[j % C].empty())
                dp[i][j] = min(dp[i][j], rgt[j % C].front()[0]);
            if (!lft[j % C].empty())
                dp[i][j] = min(dp[i][j], lft[j % C].front()[0]);
            dp[i][j] += abs(A[i] - j);
        }
    }

    for (int i = 1; i <= M; i++)
        ans = min(ans, dp[N][i]);

    cout << M * N - ans << '\n';

    return 0;
}