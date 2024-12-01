#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    fill(&dp[0][0], &dp[MAX][0], INF);
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            X = 0;
            for (int k = j; k <= N; k++) {
                X += A[k] != (k - j);
                dp[k][i] = min(dp[k][i], dp[j - 1][i - 1] + X);
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << dp[N][i] << '\n';

    return 0;
}