#include <bits/stdc++.h>
#define int long long
#define MAX 15
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, M, dp[MAX][MAX][1 << MAX], arr[MAX][MAX], price[5][5] = {{10, 8, 7, 5, 1}, {8, 6, 4, 3, 1}, {7, 4, 3, 2, 1}, {5, 3, 2, 2, 1}, {1, 1, 1, 1, 0}};

int get_dp(int X, int Y, int mask) {
    if (Y >= M)
        return get_dp(X + 1, Y - M, mask);
    if (X >= N || (X == N - 1 && Y >= M))
        return 0;
    if (dp[X][Y][mask] != -1)
        return dp[X][Y][mask];

    int res = get_dp(X, Y + 1, mask >> 1);
    if (!(mask & (1 << 0))) {
        if (Y < M - 1 && !(mask & 2))
            res = max(res, price[arr[X][Y]][arr[X][Y + 1]] + get_dp(X, Y + 2, mask >> 2));
        if (X < N - 1)
            res = max(res, price[arr[X][Y]][arr[X + 1][Y]] + get_dp(X, Y + 1, (mask >> 1) | (1 << (M - 1))));
    }

    return dp[X][Y][mask] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            arr[i][j] = str[j] - 'A';
            if (arr[i][j] == 5)
                arr[i][j] = 4;
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << get_dp(0, 0, 0) << '\n';

    return 0;
}