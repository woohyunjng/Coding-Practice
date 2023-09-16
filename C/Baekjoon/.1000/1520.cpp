#include <iostream>
#include <algorithm>
using namespace std;

int H[500][500], dp[500][500] = {}, checked[500][500] = {}, M, N;

void dfs(int x, int y)
{
    int res = 0;
    checked[x][y] = 1;

    int go[4][2] = {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
    for (int i = 0; i < 4; i++)
    {
        if (go[i][0] < 0 || go[i][0] >= M || go[i][1] < 0 || go[i][1] >= N || checked[go[i][0]][go[i][1]])
            continue;
        if (H[go[i][0]][go[i][1]] >= H[x][y] || dp[go[i][0]][go[i][1]] == -1)
            continue;

        if (!dp[go[i][0]][go[i][1]])
            dfs(go[i][0], go[i][1]);
        if (dp[go[i][0]][go[i][1]] > 0)
            res += dp[go[i][0]][go[i][1]];
    }

    checked[x][y] = 0;
    if (res)
        dp[x][y] = res;
    else
        dp[x][y] = -1;
}

int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> H[i][j];
        }
    }
    dp[M - 1][N - 1] = 1;

    dfs(0, 0);
    cout << max(dp[0][0], 0);
}
