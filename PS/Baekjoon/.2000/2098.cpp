#include <iostream>
#include <cmath>
using namespace std;

int dp[16][131072] = {}, W[16][16], N;

bool check_vst(int vst, int i)
{
    int arr[17] = {}, j = 0;
    while (vst)
    {
        arr[j++] = vst % 2;
        vst = (int)(vst / 2);
    }
    return (bool)arr[i];
}

void dfs(int i, int vst)
{
    int res = 2147483646;
    vst += (int)pow(2, i);

    if (vst == pow(2, N) - 1)
    {
        if (W[i][0])
            dp[i][vst] = W[i][0];
        else
            dp[i][vst] = -1;
        return;
    }

    for (int j = 0; j < N; j++)
    {
        if (check_vst(vst, j) || !W[i][j])
            continue;

        if (!dp[j][vst + (int)pow(2, j)])
        {
            dfs(j, vst);
        }
        if (dp[j][vst + (int)pow(2, j)] >= 0)
            res = min(dp[j][vst + (int)pow(2, j)] + W[i][j], res);
    }

    if (res == 2147483646)
        dp[i][vst] = -1;
    else
        dp[i][vst] = res;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> W[i][j];
        }
    }

    dfs(0, 0);
    cout << dp[0][1];
}
