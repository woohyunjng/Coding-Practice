#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 300001;
const int INF = 90'000'000'000;
const int REAL_INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], S[MAX];
pr dp[MAX][2];

pr max(pr X, pr Y) { return X[0] == Y[0] ? (X[1] > Y[1] ? X : Y) : (X[0] > Y[0] ? X : Y); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans, st, en, md;
    pr V;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i], S[i] = S[i - 1] + A[i];
    ans = REAL_INF;

    dp[0][1] = {-INF, 0};

    st = 0, en = INF;
    while (st <= en) {
        md = st + en >> 1;

        for (int i = 1; i <= N; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max({dp[i - 1][0][0] + A[i] - md, dp[i - 1][0][1] + 1}, {dp[i - 1][1][0] + A[i], dp[i - 1][1][1]});
        }

        V = max(dp[N][0], dp[N][1]), ans = min(ans, V[0] + md * K);

        if (V[1] <= K)
            en = md - 1;
        else
            st = md + 1;
    }

    cout << ans << '\n';

    return 0;
}