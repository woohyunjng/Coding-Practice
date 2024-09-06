#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 3000000000
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, L;
int dp[MAX][MAX][2];
vector<int> arr;

int get_dp(int A, int B, int mask) {
    if (B > N || A < 0)
        return INF;
    if (dp[A][B][mask] != INF)
        return dp[A][B][mask];

    int res = INF;
    if (mask == 0) {
        if (A > 0)
            res = min(res, get_dp(A - 1, B, 0) + (A + N - B) * (arr[A] - arr[A - 1]));
        if (B < N)
            res = min(res, get_dp(A, B + 1, 1) + (A + N - B) * (arr[B + 1] - arr[A]));
    } else {
        if (A > 0)
            res = min(res, get_dp(A - 1, B, 0) + (A + N - B) * (arr[B] - arr[A - 1]));
        if (B < N)
            res = min(res, get_dp(A, B + 1, 1) + (A + N - B) * (arr[B + 1] - arr[B]));
    }

    return dp[A][B][mask] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int res, A;
    cin >> N >> L;

    for (int i = 1; i <= N; i++) {
        cin >> A;
        arr.push_back(A);
    }
    arr.push_back(L);

    sort(arr.begin(), arr.end());

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++)
            dp[i][j][0] = dp[i][j][1] = INF;
    }
    dp[0][N][0] = dp[0][N][1] = 0;

    A = lower_bound(arr.begin(), arr.end(), L) - arr.begin();

    res = min(get_dp(A, A, 0), get_dp(A, A, 1));

    cout << res;

    return 0;
}