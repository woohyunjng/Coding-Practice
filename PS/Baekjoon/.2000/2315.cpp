#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 3000000000
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, M;
pr arr[MAX];
int sm[MAX], dp[MAX][MAX][2];

int get_sm(int A, int B) {
    B = min(B, N);
    if (A < 1)
        return sm[B];
    if (A > B)
        return 0;
    return sm[B] - sm[A - 1];
}

int get_dp(int A, int B, int mask) {
    if (dp[A][B][mask] != INF)
        return dp[A][B][mask];
    if (B > N || A < 1)
        return INF;

    int res = INF;
    if (mask == 0) {
        if (A > 1)
            res = min(res, get_dp(A - 1, B, 0) + (get_sm(1, A - 1) + get_sm(B + 1, N)) * (arr[A].first - arr[A - 1].first));
        if (B < N)
            res = min(res, get_dp(A, B + 1, 1) + (get_sm(1, A - 1) + get_sm(B + 1, N)) * (arr[B + 1].first - arr[A].first));
    } else {
        if (A > 1)
            res = min(res, get_dp(A - 1, B, 0) + (get_sm(1, A - 1) + get_sm(B + 1, N)) * (arr[B].first - arr[A - 1].first));
        if (B < N)
            res = min(res, get_dp(A, B + 1, 1) + (get_sm(1, A - 1) + get_sm(B + 1, N)) * (arr[B + 1].first - arr[B].first));
    }

    return dp[A][B][mask] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int res;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first >> arr[i].second;
        sm[i] = sm[i - 1] + arr[i].second;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            dp[i][j][0] = dp[i][j][1] = INF;
    }
    dp[1][N][0] = dp[1][N][1] = 0;

    res = min(get_dp(M, M, 0), get_dp(M, M, 1));

    cout << res;

    return 0;
}