#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dp[131072][17], N, P, arr[16][16];

int dfs(int vst, int num)
{
    if (dp[vst][num] != -2)
        return dp[vst][num];

    int res = 1000000000;
    if (num >= P)
        return dp[vst][num] = 0;

    for (int i = 0; i < N; i++)
    {
        if (vst & (1 << i))
            continue;

        int mn = 1000000000;
        for (int j = 0; j < N; j++)
        {
            if (vst & (1 << j))
                mn = min(mn, arr[j][i]);
        }

        int val = dfs(vst + (1 << i), num + 1);
        if (val != -1)
            res = min(res, val + mn);
    }

    if (res == 1000000000)
        return dp[vst][num] = -1;
    else
        return dp[vst][num] = res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 131072; i++)
    {
        for (int j = 0; j < 17; j++)
            dp[i][j] = -2;
    }

    int vst = 0, num = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    }

    string input;
    cin >> input;

    for (int i = 0; i < N; i++)
    {
        vst += (1 << i) * (int)(input[i] == 'Y');
        num += (int)(input[i] == 'Y');
    }
    cin >> P;

    if (num >= P)
        dp[vst][num] = 0;
    else if (!num)
        dp[vst][num] = -1;
    else
        dfs(vst, num);

    cout << dp[vst][num];
}