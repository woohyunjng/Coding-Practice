#include <bits/stdc++.h>
#define int long long

#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

const int MAX = 600000;
const int MAX_S = 2000;

int X[MAX], A[MAX_S], V[MAX_S], cnt[MAX], _dp[MAX_S][MAX_S][2][2], sm[MAX], S;

int dp(int l, int r, int t, int x) {
    if (l == 0 || r == S + 1)
        return INF;
    if (l == 1 && r == S && t != x)
        return INF;
    if (_dp[l][r][t][x] != -1)
        return _dp[l][r][t][x];
    int res, K = sm[l - 1] + sm[S] - sm[r] + 1;

    if (t == 0) {
        res = min(
            dp(l - 1, r, 0, x) + K * (A[l] - A[l - 1]),
            dp(l, r + 1, 1, x) + K * (A[r + 1] - A[l]));
    } else {
        res = min(
            dp(l - 1, r, 0, x) + K * (A[r] - A[l - 1]),
            dp(l, r + 1, 1, x) + K * (A[r + 1] - A[r]));
    }

    return _dp[l][r][t][x] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, Q, B, G, T, K;
    bool ans;
    vector<int> arr;

    cin >> N >> L;
    for (int i = 1; i <= N; i++)
        cin >> X[i], arr.push_back(X[i]), cnt[X[i]]++;
    cin >> Q;

    sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end()), S = arr.size();
    if (S >= MAX_S) {
        while (Q--)
            cout << "No" << '\n';
        return 0;
    }

    for (int i = 1; i <= S; i++)
        A[i] = arr[i - 1], sm[i] = sm[i - 1] + cnt[A[i]];

    for (int i = 1; i <= S; i++)
        for (int j = 1; j <= S; j++)
            _dp[i][j][0][0] = _dp[i][j][0][1] = _dp[i][j][1][0] = _dp[i][j][1][1] = -1;

    _dp[1][S][0][0] = _dp[1][S][1][1] = 0;
    for (int i = 1; i <= S; i++)
        dp(i, i, 0, 0), dp(i, i, 0, 1);

    while (Q--) {
        cin >> B >> G >> T, ans = false, T -= N;
        K = lower_bound(arr.begin(), arr.end(), G) - arr.begin() + 1;
        for (int j = -1; j <= 0; j++) {
            if (K + j <= 0 || K + j > S)
                continue;
            ans |= T >= (abs(G - arr[K + j - 1]) * (N + 1) + min(dp(K + j, K + j, 0, 0) + abs(B - arr[0]), dp(K + j, K + j, 0, 1) + abs(B - arr[S - 1])));
        }
        cout << (ans ? "Yes" : "No") << '\n';
    }

    return 0;
}