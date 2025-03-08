#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;
const int MAX_W = 20;

int A[MAX], dp[MAX_W][1 << MAX_W];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, X, ans;
    string S;

    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> S;
        for (int j = 0; j < W; j++)
            A[i] |= (S[j] == '1') << j;
        dp[0][A[i]]++;
    }

    for (int i = 1; i <= W; i++)
        for (int j = 0; j < (1 << W); j++) {
            X = i == 1 ? 0 : (i - 2 - W) * dp[i - 2][j];
            for (int k = 0; k < W; k++)
                X += dp[i - 1][j ^ (1 << k)];
            dp[i][j] = X / i;
        }

    ans = H * W;

    for (int i = 0; i < (1 << W); i++) {
        X = 0;
        for (int j = 0; j <= W; j++)
            X += min(j, W - j) * dp[j][i];
        ans = min(ans, X);
    }

    cout << ans << '\n';

    return 0;
}