#include <bits/stdc++.h>

#define MAX 30
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, dp[MAX][MAX][MAX][MAX][MAX], arr[MAX][MAX];
pr go[8] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

int get_dp(int A_1, int B_1, int A_2, int B_2, int L) {
    if (arr[A_1][B_1] != arr[A_2][B_2])
        return 0;
    if (dp[A_1][B_1][A_2][B_2][L] != -1)
        return dp[A_1][B_1][A_2][B_2][L];

    if (L == 1)
        return dp[A_1][B_1][A_2][B_2][L] = 1;

    int res = 0, X_1, Y_1, X_2, Y_2;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            X_1 = A_1 + go[i].first;
            Y_1 = B_1 + go[i].second;
            X_2 = A_2 + go[j].first;
            Y_2 = B_2 + go[j].second;

            if (X_1 < 1 || X_1 > N || Y_1 < 1 || Y_1 > N || X_2 < 1 || X_2 > N || Y_2 < 1 || Y_2 > N)
                continue;
            res += get_dp(X_1, Y_1, X_2, Y_2, L - 1);
        }
    }

    return dp[A_1][B_1][A_2][B_2][L] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int L, res = 0;
    cin >> N >> L;

    fill(&dp[0][0][0][0][0], &dp[N + 1][N + 1][N + 1][N + 1][L + 1], -1);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> arr[i][j];

    if (L & 1) {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                res += get_dp(i, j, i, j, (L + 1) / 2);
    } else {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = 0; k < 8; k++) {
                    int X = i + go[k].first, Y = j + go[k].second;
                    if (X < 1 || X > N || Y < 1 || Y > N)
                        continue;
                    res += get_dp(i, j, X, Y, L / 2);
                }
            }
        }
    }

    cout << res;

    return 0;
}