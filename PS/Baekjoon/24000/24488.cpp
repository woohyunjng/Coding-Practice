#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MAX_HEIGHT 1010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int H[MAX], dp[MAX][MAX_HEIGHT], sm[MAX][MAX_HEIGHT];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, X;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> H[i];

    X = *min_element(H + 1, H + N + 1);
    if (!(N & 1))
        X = 0;

    dp[0][0] = 1;
    for (int i = 0; i <= 1000; i++)
        sm[0][i] = 1;

    for (int x = 0; x <= X; x++) {
        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= H[i] - x; j++) {
                dp[i][j] = sm[i - 1][H[i] - x - j];
                sm[i][j] = (dp[i][j] + (j ? sm[i][j - 1] : 0)) % MOD;
            }

            for (int j = H[i] - x + 1; j <= H[i + 1] - x; j++)
                sm[i][j] = sm[i][j - 1];
        }

        res = (res + sm[N - 1][H[N] - x]) % MOD;

        for (int i = 1; i < N; i++)
            for (int j = 0; j <= H[i + 1] - x; j++)
                dp[i][j] = sm[i][j] = 0;
    }

    cout << res << '\n';

    return 0;
}