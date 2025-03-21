#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 101;
const int MAX_C = 10010;

int dp[MAX_N][MAX_C], X[MAX_N], C[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> X[i];
    for (int i = 1; i <= N; i++)
        cin >> C[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < MAX_C; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= C[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - C[i]] + X[i]);
        }
    }

    for (int i = 1; i < MAX_C; i++) {
        if (dp[N][i] >= M) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}