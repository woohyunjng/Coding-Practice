#include <bits/stdc++.h>
using namespace std;

const int MAX = 2001;

int A[MAX][MAX], S[2][MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, ans;
    string _S;

    cin >> N >> M >> K, ans = N * M;

    for (int i = 1; i <= N; i++) {
        cin >> _S;
        for (int j = 1; j <= M; j++)
            A[i][j] = (_S[j - 1] == 'B');
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            for (int k = 0; k < 2; k++) {
                S[k][i][j] = S[k][i - 1][j] + S[k][i][j - 1] - S[k][i - 1][j - 1];
                S[k][i][j] += A[i][j] ^ ((i + j) % 2 != k);
            }

    for (int i = K; i <= N; i++)
        for (int j = K; j <= M; j++)
            for (int k = 0; k < 2; k++)
                ans = min(ans, S[k][i][j] - S[k][i - K][j] - S[k][i][j - K] + S[k][i - K][j - K]);

    cout << ans << '\n';

    return 0;
}