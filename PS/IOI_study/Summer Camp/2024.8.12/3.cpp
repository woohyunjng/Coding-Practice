#include <bits/stdc++.h>
#define int long long

#define MAX 5000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string A, B, res;
    int N, M, X, Y;

    cin >> A;
    cin >> B;

    N = A.size(), M = B.size();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[N][M] << '\n';

    X = N, Y = M;
    while (X > 0 && Y > 0) {
        if (A[X - 1] == B[Y - 1]) {
            res += A[X - 1];
            X--, Y--;
        } else if (dp[X - 1][Y] > dp[X][Y - 1])
            X--;
        else
            Y--;
    }
    reverse(res.begin(), res.end());
    cout << res;

    return 0;
}