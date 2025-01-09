#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 10007

using namespace std;

int dp[MAX], A[MAX], bef[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    string S;

    cin >> S, N = S.size();
    for (int i = 1; i <= N; i++)
        A[i] = S[i - 1] - 'a';

    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i] = (dp[i - 1] * 2 - (bef[A[i]] ? dp[bef[A[i]] - 1] : 0) + MOD) % MOD;
        bef[A[i]] = i;
    }

    cout << dp[N] - 1 << '\n';

    return 0;
}