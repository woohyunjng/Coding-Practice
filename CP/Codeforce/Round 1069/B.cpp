#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MAX_K = 400;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], dp[2][MAX_K][MAX_K], M[2][MAX_K][MAX_K], B[MAX], V[MAX], S[MAX];

void solve() {
    int N, K, ans = 0, X = 1;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    B[1] = A[1], V[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (B[X] >= A[i])
            V[X]++;
        else
            B[++X] = A[i], V[X] = 1;
    }
    for (int i = 1; i <= X; i++)
        S[i] = S[i - 1] + V[i];

    for (int j = 0; j <= K; j++)
        for (int k = 0; k <= K; k++)
            dp[0][j][k] = M[0][j][k] = 0;

    for (int i = 1; i <= X; i++) {
        for (int j = 0; j <= K; j++)
            for (int k = 0; k <= K; k++)
                dp[i & 1][j][k] = M[i & 1][j][k] = 0;

        for (int j = 1; j <= K; j++) {
            for (int k = 1; k <= min(B[i], j); k++) {
                dp[i & 1][j][k] = max(M[i & 1 ^ 1][j - k][k], B[i - 1] >= k ? dp[i & 1 ^ 1][j][k] : -INF) + V[i] * k;
                M[i & 1][j][k] = max(M[i & 1][j][k - 1], dp[i & 1][j][k]);
                ans = max(ans, dp[i & 1][j][k]);
            }
            for (int k = min(B[i], j) + 1; k <= K; k++)
                M[i & 1][j][k] = M[i & 1][j][k - 1];
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}