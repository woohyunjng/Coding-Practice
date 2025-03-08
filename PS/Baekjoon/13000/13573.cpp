#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200000;
const int MAX_N = 21;

int dp[MAX_N][1 << MAX_N], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, val, ans;
    string S;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < M; j++)
            A[j] |= (S[j] == 'T') << i;
    }

    for (int i = 0; i < M; i++)
        dp[0][A[i]]++;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j > 0; j--)
            for (int k = 0; k < (1 << N); k++)
                dp[j][k ^ (1 << i)] += dp[j - 1][k];

    ans = N * M;
    for (int i = 0; i < (1 << N); i++) {
        val = 0;
        for (int j = 0; j <= N; j++)
            val += min(j, N - j) * dp[j][i];
        ans = min(ans, val);
    }
    cout << ans << '\n';

    return 0;
}