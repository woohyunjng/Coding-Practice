#include <bits/stdc++.h>
using namespace std;

const int MAX = 301;
const int INF = 1e9;

int B[MAX];
bool dp1[2][MAX * MAX];
bitset<MAX * MAX> dp2[2][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, ans = INF, L, SA = 0, SB = 0;
    vector<int> arr;

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> X, SA += X;
        if (X < K) {
            cout << "Impossible" << '\n';
            return 0;
        }
    }
    for (int i = 1; i <= M; i++)
        cin >> B[i], SB += B[i];
    sort(B + 1, B + M + 1), L = M + 1;

    for (int i = 1; i <= M; i++)
        if (B[i] >= N) {
            L = i;
            break;
        }

    dp1[0][0] = 1;
    for (int i = 1; i < L; i++)
        for (int j = 0; j <= SB; j++) {
            dp1[i & 1][j] = dp1[i & 1 ^ 1][j];
            if (j >= B[i])
                dp1[i & 1][j] |= dp1[i & 1 ^ 1][j - B[i]];
        }
    for (int i = 0; i <= SB; i++)
        if (dp1[(L - 1) & 1][i])
            arr.push_back(i);

    dp2[(L - 1) & 1][0][0] = 1;
    for (int i = L; i <= M; i++) {
        for (int j = 0; j <= i - L; j++)
            dp2[i & 1][j] = dp2[i & 1 ^ 1][j];
        for (int j = 1; j <= i - L + 1; j++)
            dp2[i & 1][j] |= dp2[i & 1 ^ 1][j - 1] << B[i];
    }

    for (int i = 0; i <= M - L + 1; i++)
        for (int j = 0; j <= SB; j++) {
            if (!dp2[M & 1][i][j])
                continue;
            X = max({0, N * K - i * N, SA - j});
            X = lower_bound(arr.begin(), arr.end(), X) - arr.begin();
            if (X < arr.size())
                ans = min(ans, arr[X] + j - SA);
        }

    if (ans == INF)
        cout << "Impossible" << '\n';
    else
        cout << ans << '\n';

    return 0;
}