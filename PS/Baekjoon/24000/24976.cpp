#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int L[MAX], R[MAX], dp[MAX][2], res[MAX];
vector<int> child[MAX];

void dfs(int K) {
    dp[K][0] = 0, dp[K][1] = INF;
    for (int i : child[K]) {
        dfs(i);
        res[K] = max(res[K], res[i]);
        dp[K][0] = max(dp[K][0], dp[i][0]), dp[K][1] = min(dp[K][1], dp[i][1]);
    }
    res[K] = max({res[K], dp[K][0] - R[K], L[K] - dp[K][1]});

    if (dp[K][0] >= dp[K][1]) {
        int md = dp[K][0] + dp[K][1] >> 1;

        if (L[K] <= md && md <= R[K])
            res[K] = max({res[K], dp[K][0] - md, md - dp[K][1]});
        if (md > R[K])
            res[K] = max(res[K], dp[K][0] - R[K]);
        else if (md < L[K])
            res[K] = max({res[K], L[K] - dp[K][1]});
    }

    dp[K][0] = max(dp[K][0], L[K]), dp[K][1] = min(dp[K][1], R[K]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T, B, X;
    cin >> T >> B;

    while (T--) {
        cin >> N;

        for (int i = 2; i <= N; i++) {
            cin >> X;
            child[X].push_back(i);
        }

        for (int i = 1; i <= N; i++)
            cin >> L[i] >> R[i];

        dfs(1);

        cout << res[1] << '\n';

        if (B) {
            for (int i = 1; i <= N; i++)
                cout << max(min((dp[1][0] + dp[1][1]) / 2, R[i]), L[i]) << ' ';
            cout << '\n';
        }

        for (int i = 1; i <= N; i++)
            child[i].clear(), res[i] = 0;
    }

    return 0;
}