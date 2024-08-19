#include <bits/stdc++.h>
#define int long long

#define MAX 400
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX];

int get_dp(int A, int B) {
    if (A >= B * 3)
        return get_dp(A - B, B) + 1;
    if (B >= A * 3)
        return get_dp(A, B - A) + 1;
    if (A == B)
        return 1;
    if (dp[A][B])
        return dp[A][B];

    int res = A * B;

    for (int i = 1; i < A; i++)
        res = min(res, get_dp(i, B) + get_dp(A - i, B));
    for (int i = 1; i < B; i++)
        res = min(res, get_dp(A, i) + get_dp(A, B - i));

    return dp[A][B] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    cout << get_dp(N, M);

    return 0;
}