#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 100001
using namespace std;

int N, dp[MAX][20];
vector<int> tree[MAX];
bool checked[MAX] = {};

int dfs(int A, int color)
{
    if (!dp[A][color])
    {
        checked[A] = true;
        int res = 0;
        for (int i : tree[A])
        {
            if (checked[i])
                continue;
            int mn = 2147483647;
            for (int j = 1; j <= 19; j++)
            {
                if (j == color)
                    continue;
                mn = min(mn, dfs(i, j));
            }
            res += mn;
        }
        checked[A] = false;
        dp[A][color] = res + color;
    }
    return dp[A][color];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, 0, sizeof(dp));

    int N, A, B, res = 2147483647;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    for (int i = 1; i <= 19; i++)
        res = min(res, dfs(1, i));
    cout << res;
}
