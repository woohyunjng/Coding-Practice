#include <bits/stdc++.h>
#define int long long
#define MAX 1010
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][MAX], dp[MAX][MAX][2];
pr go[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, N, K, X = 1, Y = 1;
    cin >> H >> W >> N;

    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            cin >> arr[i][j];

    if (arr[1][1]) {
        dp[1][1][0] = N / 2;
        dp[1][1][1] = N - N / 2;

        if (N % 2)
            go[1][1] = {1, 2};
        else
            go[1][1] = {2, 1};
    } else {
        dp[1][1][0] = N - N / 2;
        dp[1][1][1] = N / 2;

        if (N % 2)
            go[1][1] = {2, 1};
        else
            go[1][1] = {1, 2};
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (i == 1 && j == 1)
                continue;
            K = dp[i][j - 1][1] + dp[i - 1][j][0];
            if (arr[i][j]) {
                dp[i][j][0] = K / 2;
                dp[i][j][1] = K - K / 2;

                if (K % 2)
                    go[i][j] = {i, j + 1};
                else
                    go[i][j] = {i + 1, j};
            } else {
                dp[i][j][0] = K - K / 2;
                dp[i][j][1] = K / 2;

                if (K % 2)
                    go[i][j] = {i + 1, j};
                else
                    go[i][j] = {i, j + 1};
            }
        }
    }

    while (dp[X][Y][0] + dp[X][Y][1] > 0) {
        pr K = go[X][Y];
        X = K.first;
        Y = K.second;
    }

    cout << X << ' ' << Y;

    return 0;
}