#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 1001;
const int VMAX = 2050;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], B[MAX], C[MAX], dp[2][MAX][VMAX];
vector<int> arr[MAX];
vector<pr> val[MAX][VMAX];

int dis(int X, int Y) { return abs(A[X] - A[Y]) + abs(B[X] - B[Y]); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, W, M, X, Y, ans = INF;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i] >> C[i];
    cin >> W >> M;

    for (int i = 1; i <= N; i++) {
        arr[i].push_back(0), arr[i].push_back(W);
        for (int j = 1; j <= N; j++) {
            if (i == j || dis(i, j) > W)
                continue;
            arr[i].push_back(dis(i, j)), arr[i].push_back(W - dis(i, j));
        }
        sort(arr[i].begin(), arr[i].end()), arr[i].erase(unique(arr[i].begin(), arr[i].end()), arr[i].end());
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (i == j || dis(i, j) > W)
                continue;
            X = lower_bound(arr[i].begin(), arr[i].end(), dis(i, j)) - arr[i].begin(), val[i][X].push_back({j, 0});
            X = lower_bound(arr[j].begin(), arr[j].end(), W - dis(i, j)) - arr[j].begin(), val[i][(int)arr[i].size() - 1].push_back({j, X});
        }

    for (int i = 1; i <= N; i++)
        for (int j = 0; j < arr[i].size(); j++)
            dp[0][i][j] = INF;
    dp[0][1][0] = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++)
            for (int k = 0; k < arr[j].size(); k++)
                dp[(i + 1) & 1][j][k] = INF;
        for (int j = 1; j <= N; j++)
            for (int k = 0; k < arr[j].size(); k++) {
                if (dp[i & 1][j][k] == INF)
                    continue;
                dp[i & 1 ^ 1][j][k] = min(dp[i & 1 ^ 1][j][k], dp[i & 1][j][k]);
                if (k + 1 < arr[j].size())
                    dp[i & 1][j][k + 1] = min(dp[i & 1][j][k + 1], dp[i & 1][j][k] + C[j] * (arr[j][k + 1] - arr[j][k]));
                for (pr l : val[j][k])
                    dp[i & 1 ^ 1][l[0]][l[1]] = min(dp[i & 1 ^ 1][l[0]][l[1]], dp[i & 1][j][k]);
            }
    }

    for (int i = 0; i < arr[2].size(); i++)
        ans = min(ans, dp[M & 1][2][i]);
    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}