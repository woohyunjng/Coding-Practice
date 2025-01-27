#include <bits/stdc++.h>
#define ll long long

#define MAX 1 << 23
#define MOD 1000000007

using namespace std;

typedef array<int, 2> pr;

pr dp[MAX][3]; // 0 -> 자신 사용 X / 1 -> 자신 사용 / 2 -> 두 경우 모두
int child_cnt[MAX], child[MAX];

void dfs(int node) {
    int X = child_cnt[node], K = child[node];
    ll T;
    pr V;

    if (!X) {
        dp[node][0] = dp[node][1] = dp[node][2] = {0, 1};
        return;
    }

    if (K == -1) {
        dp[node][0] = {0, 1};
        dp[node][1] = dp[node][2] = {1, X};
        return;
    }

    dfs(K);

    dp[node][0] = dp[K][2];
    dp[node][1] = {dp[K][0][0] + 1, dp[K][0][1]};

    if (X > 1) {
        T = (ll)dp[K][2][1] * (X - 1) % MOD;
        V = {dp[K][2][0] + 1, T};
        if (V[0] > dp[node][1][0])
            dp[node][1] = V;
        else
            dp[node][1][1] = (dp[node][1][1] + V[1]) % MOD;
    }

    if (dp[node][0][0] > dp[node][1][0])
        dp[node][2] = dp[node][0];
    else if (dp[node][0][0] < dp[node][1][0])
        dp[node][2] = dp[node][1];
    else
        dp[node][2] = {dp[node][0][0], (dp[node][0][1] + dp[node][1][1]) % MOD};
}

pr roadwork(string S) {
    pr ans = {0, 0};
    int N = S.size() / 2 + 1, X = 0, Y = N;

    for (int i = 0; i < N * 2; i++)
        child[i] = -1, child_cnt[i] = 0;

    child[0] = N, child_cnt[0]++;
    for (char i : S) {
        if (i == 'A')
            child[X] = ++Y, child_cnt[X]++;
        else
            child[Y] = ++X, child_cnt[Y]++;
    }

    dfs(0);
    ans[0] = dp[0][2][0], ans[1] = dp[0][2][1];

    return ans;
}