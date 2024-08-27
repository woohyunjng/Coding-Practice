#include <bits/stdc++.h>
#define int long long

#define MAX 51
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX][MAX][MAX];

int get_dp(int H_1, int W_1, int H_2, int W_2) {
    if (H_1 == 0 || W_1 == 0)
        return 0;
    if (dp[H_1][W_1][H_2][W_2])
        return dp[H_1][W_1][H_2][W_2];
    if (H_2 == 0 && W_2 == 0 && H_1 == W_1)
        return dp[H_1][W_1][H_2][W_2] = 1;

    int res = INF;

    for (int i = 1; i < W_1 - W_2; i++)
        res = min(res, get_dp(H_1, i, 0, 0) + get_dp(H_1, W_1 - i, H_2, W_2));
    for (int i = 1; i < W_2; i++)
        res = min(res, get_dp(H_1, W_1 - W_2 + i, H_2, i) + get_dp(H_1 - H_2, W_2 - i, 0, 0));
    if (W_2)
        res = min(res, get_dp(H_1, W_1 - W_2, 0, 0) + get_dp(H_1 - H_2, W_2, 0, 0));

    for (int i = 1; i < H_1 - H_2; i++)
        res = min(res, get_dp(i, W_1, 0, 0) + get_dp(H_1 - i, W_1, H_2, W_2));
    for (int i = 1; i < H_2; i++)
        res = min(res, get_dp(H_1 - H_2 + i, W_1, i, W_2) + get_dp(H_2 - i, W_1 - W_2, 0, 0));
    if (H_2)
        res = min(res, get_dp(H_1 - H_2, W_1, 0, 0) + get_dp(H_2, W_1 - W_2, 0, 0));

    return dp[H_1][W_1][H_2][W_2] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H_1, W_1, H_2, W_2;
    cin >> H_1 >> W_1 >> H_2 >> W_2;

    cout << get_dp(H_1, W_1, H_2, W_2) << '\n';

    return 0;
}