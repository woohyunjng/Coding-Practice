#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int INF = 1e9;

int A[MAX], B[MAX], T[MAX], dp[MAX], pre[MAX][2];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, ans, X, Y, U, V;
    string ans_S, S;

    bool chkL = false, chkR = false, flag;

    cin >> N >> M, A[0] = B[0] = -INF, chk[0] = true;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= M; i++)
        cin >> B[i];

    if (N == 1) {
        for (int i = 1; i <= M; i++)
            chkL |= B[i]<A[1], chkR |= B[i]> A[1];
        if (chkL && chkR) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int st = 0, en = INF, md; st <= en;) {
        md = st + en >> 1, S = "";

        for (int i = 1; i <= N; i++) {
            pre[i][0] = pre[i][1] = -1;
            dp[i] = -INF, X = lower_bound(B + 1, B + M + 1, A[i] - md) - B - 1;
            if (dp[i - 1] >= 0 && A[i - 1] + dp[i - 1] >= B[X])
                dp[i] = max(0ll, A[i - 1] + dp[i - 1] - A[i]), pre[i][0] = (i - 1) << 1;
            if (chk[i - 1] && A[i - 1] + md >= B[X])
                dp[i] = max({0ll, dp[i], A[i - 1] + md - A[i]}), pre[i][0] = (i - 1) << 1 | 1;

            Y = lower_bound(A + 1, A + N + 1, A[i] - md) - A;
            if (Y < i - 1 && T[i - 2] - T[Y - 1] > 0)
                dp[i] = max({0ll, dp[i], A[i - 1] + md - A[i]}), pre[i][0] = -2;
            if (Y < i && chk[Y - 1] && A[Y - 1] + md >= B[X])
                dp[i] = max({0ll, dp[i], A[i - 1] + md - A[i]}), pre[i][0] = (Y - 1) << 1 | 1;
            if (Y < i && dp[Y - 1] >= 0 && A[Y - 1] + dp[Y - 1] >= B[X])
                dp[i] = max({0ll, dp[i], A[i - 1] + md - A[i]}), pre[i][0] = (Y - 1) << 1;

            chk[i] = false;
            X = lower_bound(B + 1, B + M + 1, A[i]) - B - 1;
            if (chk[i - 1] && A[i - 1] + md >= B[X])
                chk[i] = true, pre[i][1] = (i - 1) << 1 | 1;
            if (dp[i - 1] >= 0 && A[i - 1] + dp[i - 1] >= B[X])
                chk[i] = true, pre[i][1] = (i - 1) << 1;

            T[i] = T[i - 1] + (dp[i] >= 0);
        }

        if (dp[N] >= 0 && A[N] + dp[N] < B[M])
            dp[N] = -INF;
        if (chk[N] && A[N] + md < B[M])
            chk[N] = false;
        flag = chk[N] || dp[N] >= 0, U = N;

        if (flag) {
            U = N, V = chk[N] ? 1 : 0;
            while (U > 0) {
                S += V == 1 ? 'R' : 'L';
                if (V == 1)
                    V = pre[U][1] & 1, U = pre[U][1] >> 1;
                else {
                    if (pre[U][0] == -2) {
                        S += 'R', U -= 2, V = 0;
                        while (dp[U] < 0)
                            S += 'R', U--;
                    } else if ((pre[U][0] >> 1) == U - 1)
                        V = pre[U--][0] & 1;
                    else {
                        X = pre[U][0] >> 1, Y = pre[U--][0] & 1;
                        while (U > X)
                            S += 'R', U--;
                        V = Y;
                    }
                }
            }
            reverse(S.begin(), S.end());
            ans = md, ans_S = S, en = md - 1;
        } else
            st = md + 1;
    }

    cout << ans << '\n'
         << ans_S << '\n';

    return 0;
}