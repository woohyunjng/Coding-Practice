#include <bits/stdc++.h>
using namespace std;

const int MAX = 501;
const int INF = 10000000;

int L[MAX], R[MAX], dp[MAX][MAX], ML[MAX][MAX], MR[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K;
    vector<int> arr;

    cin >> T;
    while (T--) {
        cin >> N >> K, arr.clear();
        for (int i = 1; i <= N; i++)
            cin >> L[i] >> R[i], arr.push_back(i);

        sort(arr.begin(), arr.end(), [&](int x, int y) { return L[x] == L[y] ? R[x] < R[y] : L[x] < L[y]; });

        for (int i = 1; i <= N; i++) {
            ML[i][i] = L[arr[i - 1]], MR[i][i] = R[arr[i - 1]];
            for (int j = i + 1; j <= N; j++) {
                ML[i][j] = max(ML[i][j - 1], L[arr[j - 1]]);
                MR[i][j] = min(MR[i][j - 1], R[arr[j - 1]]);
            }
        }

        for (int i = 1; i <= N; i++)
            for (int j = 0; j <= K; j++)
                dp[i][j] = INF;

        for (int i = 1; i <= K; i++)
            for (int j = 1; j <= N; j++) {
                dp[j][i] = dp[j][i - 1];
                for (int k = j - 1; k >= 0 && ML[k + 1][j] <= MR[k + 1][j]; k--)
                    dp[j][i] = min(dp[j][i], dp[k][i - 1] + (j - k) * ML[k + 1][j]);
            }

        cout << dp[N][K] << '\n';
    }

    return 0;
}