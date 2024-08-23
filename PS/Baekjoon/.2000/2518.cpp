#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, dp[MAX][MAX][MAX][4], arr[MAX][4], A[4];

int get_rotate(int A, int B) { return min(abs(A - B), N - abs(A - B)); }
int change_type(int A, int X, int Y) {
    A = A + N / 3 * ((Y - X) % 3);
    return (A - 1 + N) % N + 1;
}

int get_dp(int A, int B, int C, int type) {
    if (A == 0 && B == 0 && C == 0)
        return 0;
    if (dp[A][B][C][type])
        return dp[A][B][C][type];

    int res = INF;
    if (type == 1 && A) {
        res = min({res,
                   get_dp(A - 1, B, C, 1) + get_rotate(change_type(arr[A - 1][1], 1, 1), arr[A][1]),
                   get_dp(A - 1, B, C, 2) + get_rotate(change_type(arr[B][2], 2, 1), arr[A][1]),
                   get_dp(A - 1, B, C, 3) + get_rotate(change_type(arr[C][3], 3, 1), arr[A][1])});
    }
    if (type == 2 && B) {
        res = min({res,
                   get_dp(A, B - 1, C, 1) + get_rotate(change_type(arr[A][1], 1, 2), arr[B][2]),
                   get_dp(A, B - 1, C, 2) + get_rotate(change_type(arr[B - 1][2], 2, 2), arr[B][2]),
                   get_dp(A, B - 1, C, 3) + get_rotate(change_type(arr[C][3], 3, 2), arr[B][2])});
    }
    if (type == 3 && C) {
        res = min({res,
                   get_dp(A, B, C - 1, 1) + get_rotate(change_type(arr[A][1], 1, 3), arr[C][3]),
                   get_dp(A, B, C - 1, 2) + get_rotate(change_type(arr[B][2], 2, 3), arr[C][3]),
                   get_dp(A, B, C - 1, 3) + get_rotate(change_type(arr[C - 1][3], 3, 3), arr[C][3])});
    }

    return dp[A][B][C][type] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i <= 3; i++) {
        cin >> A[i];
        for (int j = 1; j <= A[i]; j++) {
            cin >> arr[j][i];
        }
    }
    arr[0][1] = 1, arr[0][2] = N / 3 + 1, arr[0][3] = N / 3 * 2 + 1;

    cout << min({get_dp(A[1], A[2], A[3], 1),
                 get_dp(A[1], A[2], A[3], 2),
                 get_dp(A[1], A[2], A[3], 3)});

    return 0;
}