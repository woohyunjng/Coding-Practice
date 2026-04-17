#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 600;
const int MAX_K = 200000;

int sm[MAX][MAX], zero[MAX][MAX], val[MAX_K], D[MAX_K];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, Y, ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> X, sm[i][j] = X, zero[i][j] = X == 0;
            sm[i][j] += sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1];
            zero[i][j] += zero[i - 1][j] + zero[i][j - 1] - zero[i - 1][j - 1];
        }

    cin >> K;
    for (int i = 1; i <= K; i++)
        cin >> D[i];

    sort(D + 1, D + K + 1, greater<int>());
    for (int i = 1; i <= K; i++)
        val[i] = val[i - 1] + D[i];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            X = min(N - i + 1, N - j + 1);
            for (int k = 1; k <= X; k++) {
                Y = zero[i + k - 1][j + k - 1] - zero[i - 1][j + k - 1] - zero[i + k - 1][j - 1] + zero[i - 1][j - 1];
                if (Y > K)
                    continue;
                ans = max(ans, (sm[i + k - 1][j + k - 1] - sm[i - 1][j + k - 1] - sm[i + k - 1][j - 1] + sm[i - 1][j - 1]) + val[Y]);
            }
        }

    cout << ans << '\n';

    return 0;
}