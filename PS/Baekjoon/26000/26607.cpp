#include <bits/stdc++.h>
#define int long long

#define MAX 81

using namespace std;

int A[MAX], B[MAX];
bool dp[MAX][MAX * 200];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, res = 0;
    cin >> N >> K >> X;

    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i];

    dp[0][0] = true;
    for (int i = 1; i <= N; i++)
        for (int j = K; j >= 1; j--)
            for (int k = 0; k <= X * K; k++)
                if (k >= A[i] && dp[j - 1][k - A[i]])
                    dp[j][k] = true;

    for (int i = 0; i <= X * K; i++)
        if (dp[K][i])
            res = max(res, i * (X * K - i));

    cout << res << '\n';

    return 0;
}