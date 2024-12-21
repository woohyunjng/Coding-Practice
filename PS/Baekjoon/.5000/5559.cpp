#include <bits/stdc++.h>
#define int long long

#define MAX 20
#define MAX_FIB 17712
#define MOD 100000
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int M, N, A[MAX][MAX], _dp[MAX][MAX][MAX_FIB][2], st[1 << MAX], bit[MAX_FIB];

int dp(int X, int Y, int mask, int cur) {
    if (X == M)
        return 1;
    else if (Y == N)
        return dp(X + 1, 0, mask, 0);
    else if (_dp[X][Y][st[mask]][cur] != -1)
        return _dp[X][Y][st[mask]][cur];

    int res = 0;
    if (A[X][Y] == 0)
        res = dp(X, Y + 1, mask >> 1, 1);
    else if (A[X][Y] == 1)
        res = dp(X, Y + 1, mask >> 1 | (cur ? (1 << N - 2) : 0), 0);
    else if (A[X][Y] == 2) {
        if ((mask & 1) == 0)
            res = dp(X, Y + 1, mask >> 1, 0);
    } else {
        res = dp(X, Y + 1, mask >> 1, 1);
        res = (res + dp(X, Y + 1, mask >> 1 | (cur ? (1 << N - 2) : 0), 0)) % MOD;
        if ((mask & 1) == 0)
            res = (res + dp(X, Y + 1, mask >> 1, 0)) % MOD;
    }
    return _dp[X][Y][st[mask]][cur] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, cnt = 0, all = 1;
    bool flag;
    string S;

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        cin >> S;
        for (int j = 0; j < N; j++) {
            if (S[j] == 'J')
                A[i][j] = 0;
            else if (S[j] == 'O')
                A[i][j] = 1;
            else if (S[j] == 'I')
                A[i][j] = 2;
            else
                A[i][j] = -1, all = all * 3 % MOD;
        }
    }

    for (int i = 0; i < (1 << N); i++) {
        X = i, flag = true;
        while (X) {
            if ((X & 3) == 3)
                flag = false;
            X >>= 1;
        }
        if (flag)
            bit[cnt] = i, st[i] = cnt++;
    }

    memset(_dp, -1, sizeof(_dp));
    cout << (all - dp(0, 0, 0, 0) + MOD) % MOD << '\n';

    return 0;
}