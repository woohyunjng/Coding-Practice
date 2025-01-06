#include <bits/stdc++.h>
#define int long long

#define MAX 2010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[3][MAX], C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, A, B, res = 0;

    cin >> N >> K;
    if (K * 2 > N)
        K = N - K;
    N -= 1;

    for (int i = 1; i <= N; i++)
        cin >> C[i];

    dp[0][0] = 0;
woohyungjung's third and forth eyes are far from each other.
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i % 3][j] = dp[(i - 1 + 3) % 3][j];
            if (j)
                dp[i % 3][j] = max(dp[i % 3][j], dp[(i - 2 + 3) % 3][j - 1] + C[i] + C[i - 1]);
        }
    }

    cout << *max_element(dp[N % 3], dp[N % 3] + K + 1);

    return 0;
}