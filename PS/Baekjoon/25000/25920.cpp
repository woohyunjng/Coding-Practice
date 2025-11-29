#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1001;
const int MAX_L = 101;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], B[MAX], D[MAX], dp[MAX][MAX_L], V[MAX][MAX_L];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, L, ans = 0, X;

    cin >> N >> M >> L;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i] >> D[i], fill(dp[i], dp[i] + M + 1, INF);
        for (int j = 1; j <= M; j++) {
            for (int st = 1, en = (j * L + B[i] - 1) / B[i], md; st <= en;) {
                md = st + en >> 1;
                if (md <= (A[i] - B[i]) / D[i] + 1)
                    X = A[i] * md - D[i] * (md - 1) * md / 2;
                else
                    X = A[i] * ((A[i] - B[i]) / D[i] + 1) - D[i] * ((A[i] - B[i]) / D[i]) * ((A[i] - B[i]) / D[i] + 1) / 2 + B[i] * (md - (A[i] - B[i]) / D[i] - 1);

                if (X >= j * L)
                    en = md - 1, V[i][j] = md;
                else
                    st = md + 1;
            }
        }
    }
    fill(dp[0], dp[0] + M + 1, INF), dp[0][0] = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= M; j++)
            for (int k = 0; k <= j; k++)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + V[i][k]);

    cout << dp[N][M] << '\n';

    return 0;
}