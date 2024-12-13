#include <bits/stdc++.h>
#define int long long

#define MAX 20
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[1 << MAX], T[MAX];
vector<int> st[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, C, X, res = 21;
    cin >> N >> L;

    fill(dp, dp + (1 << N), -1);

    for (int i = 0; i < N; i++) {
        cin >> T[i] >> C;
        while (C--) {
            cin >> X;
            st[i].push_back(X);
        }
        if (!st[i].empty() && st[i][0] == 0)
            dp[1 << i] = T[i];
    }

    for (int i = 1; i < (1 << N); i++) {
        if (dp[i] == -1)
            continue;
        if (dp[i] >= L)
            res = min(res, (int)__builtin_popcount(i));

        for (int j = 0; j < N; j++) {
            if (i & (1 << j))
                continue;
            C = upper_bound(st[j].begin(), st[j].end(), dp[i]) - st[j].begin() - 1;
            if (C >= 0)
                dp[i | (1 << j)] = max(dp[i | (1 << j)], st[j][C] + T[j]);
        }
    }

    cout << (res == 21 ? -1 : res) << '\n';

    return 0;
}