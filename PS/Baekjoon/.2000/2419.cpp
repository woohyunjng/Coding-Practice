#include <bits/stdc++.h>
#define int long long

#define MAX 310
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, M, arr[MAX], dp[MAX][MAX][2];

int get_dp(int A, int B, int mask, int cnt) {
    if (B > N || A <= 0)
        return INF;
    if (B - A == cnt)
        return 0;
    if (dp[A][B][mask] != -1)
        return dp[A][B][mask];

    int res = INF;

    if (mask == 0) {
        res = min(res, get_dp(A - 1, B, 0, cnt) + (cnt - (B - A)) * (arr[A] - arr[A - 1]));
        res = min(res, get_dp(A, B + 1, 1, cnt) + (cnt - (B - A)) * (arr[B + 1] - arr[A]));
    } else {
        res = min(res, get_dp(A - 1, B, 0, cnt) + (cnt - (B - A)) * (arr[B] - arr[A - 1]));
        res = min(res, get_dp(A, B + 1, 1, cnt) + (cnt - (B - A)) * (arr[B + 1] - arr[B]));
    }

    return dp[A][B][mask] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int res = 0, st;
    bool check = false;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        check = check || (arr[i] == 0);
    }
    if (!check)
        arr[++N] = 0;
    sort(arr + 1, arr + N + 1);

    st = lower_bound(arr + 1, arr + N + 1, 0) - arr;

    for (int i = 1; i < N; i++) {
        fill(&dp[0][0][0], &dp[N][N][2], -1);
        res = max(res, M * i + (check ? M : 0) - min(get_dp(st, st, 0, i), get_dp(st, st, 1, i)));
    }

    cout << res;

    return 0;
}