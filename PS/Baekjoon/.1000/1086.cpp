#include <bits/stdc++.h>
#define int unsigned long long
#define MAX 15

using namespace std;

int dp[1 << MAX][51], arr[MAX], len[MAX], N, K, mod[751];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int dfs(int vst, int rem, int ln)
{
    if (vst == (1 << N) - 1)
    {
        dp[vst][rem] = !rem ? 1 : 0;
        return dp[vst][rem];
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        if (vst & (1 << i))
            continue;

        int k = dp[vst | 1 << i][(rem + arr[i] * mod[ln]) % K];
        if (k == -1)
            res += dfs(vst | 1 << i, (rem + arr[i] * mod[ln]) % K, ln + len[i]);
        else
            res += k;
    }

    dp[vst][rem] = res;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int res = 0, base = 1, g;
    string str, str_arr[MAX];

    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str_arr[i];
        len[i] = str_arr[i].size();
    }
    cin >> K;

    mod[0] = 1 % K;
    for (int i = 1; i <= 750; i++)
        mod[i] = mod[i - 1] * 10 % K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < len[i]; j++)
            arr[i] = (arr[i] * 10 + str_arr[i][j] - '0') % K;
    }

    for (int i = 0; i < N; i++)
        res += dfs(1 << i, arr[i], len[i]);

    for (int i = 2; i <= N; i++)
        base *= i;

    g = gcd(base, res);
    if (!res)
        cout << "0/1";
    else
        cout << res / g << '/' << base / g;

    return 0;
}