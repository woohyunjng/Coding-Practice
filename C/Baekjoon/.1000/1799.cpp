#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, arr[11][11], board[11][11];

int dfs(int x, int y)
{
    if (y > N)
    {
        if (N % 2)
            return dfs(x + 1, y % N);
        else
            return dfs(x + 1, 3 - y % N);
    }

    if (x > N)
        return 0;

    int mx = 0;
    bool checked = true;

    if (arr[x][y])
    {
        for (int i = x - 1, j = y - 1; i > 0 && j > 0; i--, j--)
        {
            if (board[i][j])
            {
                checked = false;
                break;
            }
        }
        for (int i = x - 1, j = y + 1; i > 0 && j <= N; i--, j++)
        {
            if (board[i][j])
            {
                checked = false;
                break;
            }
        }

        board[x][y] = 1;
        if (checked)
            mx = max(mx, dfs(x, y + 2) + 1);
        board[x][y] = 0;
    }
    mx = max(mx, dfs(x, y + 2));
    return mx;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cin >> arr[i][j];
    }

    cout << dfs(1, 1) + dfs(1, 2);
}