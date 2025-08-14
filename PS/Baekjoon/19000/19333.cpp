#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 20> nd;

const int MAX = 200001;
const int MOD = 1'000'000'007;

int A[MAX], L[MAX], R[MAX], ans[MAX], dp[MAX][20], M;

void dnc(int l, int r, vector<int> queries) {
    int m = l + r >> 1;
    if (l == r) {
        for (int i : queries)
            ans[i]++, ans[i] += A[L[i]] % M == 0;
        return;
    }

    fill(dp[m], dp[m] + M, 0), dp[m][0]++, dp[m][A[m] % M]++;
    fill(dp[m + 1], dp[m + 1] + M, 0), dp[m + 1][0]++, dp[m + 1][A[m + 1] % M]++;

    for (int i = m - 1; i >= l; i--) {
        for (int j = 0; j < M; j++)
            dp[i][j] = dp[i + 1][j];
        for (int j = 0; j < M; j++)
            dp[i][(j + A[i]) % M] += dp[i + 1][j];
        for (int j = 0; j < M; j++)
            dp[i][j] %= MOD;
    }

    for (int i = m + 2; i <= r; i++) {
        for (int j = 0; j < M; j++)
            dp[i][j] = dp[i - 1][j];
        for (int j = 0; j < M; j++)
            dp[i][(j + A[i]) % M] += dp[i - 1][j];
        for (int j = 0; j < M; j++)
            dp[i][j] %= MOD;
    }

    vector<int> sl, sr;
    for (int i : queries) {
        if (R[i] <= m)
            sl.push_back(i);
        else if (m < L[i])
            sr.push_back(i);
        else {
            for (int j = 0; j < M; j++)
                ans[i] += dp[L[i]][j] * dp[R[i]][(M * 2 - j) % M], ans[i] %= MOD;
        }
    }

    dnc(l, m, sl), dnc(m + 1, r, sr);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q;
    vector<int> queries;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> L[i] >> R[i], queries.push_back(i);

    dnc(1, N, queries);

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}