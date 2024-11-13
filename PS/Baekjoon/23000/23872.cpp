#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int X[MAX], Y[MAX], K;

int get_min_res(vector<int> &x, vector<int> &y) {
    int N = x.size(), res = INF;

    if (N & 1) {
        for (int i = 0; i < N; i++) {
            if (i & 1) {
                if (i == N - 1)
                    res = min(res, y[i]);
                else {
                    if (x[i + 1] - x[i - 1] <= K)
                        res = min(res, y[i]);
                }
            } else
                res = min(res, y[i]);
        }
    } else
        res = 0;

    return res;
}

int get_max_res(vector<int> &x, vector<int> &y) {
    int N = x.size(), A;
    vector<int> dp[2] = {vector<int>(N + 1, 0), vector<int>(N + 1, 0)};

    dp[0][0] = 0, dp[1][0] = -INF;

    for (int i = 1; i <= N; i++) {
        A = lower_bound(x.begin(), x.end(), x[i - 1] - K) - x.begin();

        dp[0][i] = dp[0][i - 1], dp[1][i] = dp[1][i - 1];

        if (i == 1 || i == N || x[i] - x[i - 2] <= K || (i & 1) == 0)
            dp[0][i] = max(dp[0][i - 1], dp[1][A] + y[i - 1]);
        if (i == 1 || i == N || x[i] - x[i - 2] <= K || (i & 1))
            dp[1][i] = max(dp[1][i - 1], dp[0][A] + y[i - 1]);
    }

    return dp[N & 1][N];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, res = 0;
    vector<int> x, y;
    cin >> T >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i];

    for (int i = 1; i <= N;) {
        for (int j = X[i]; i <= N && X[i] <= j + K; i++)
            x.push_back(X[i]), y.push_back(Y[i]), j = X[i];

        res += T == 1 ? get_min_res(x, y) : get_max_res(x, y);
        x.clear(), y.clear();
    }

    cout << res << '\n';

    return 0;
}