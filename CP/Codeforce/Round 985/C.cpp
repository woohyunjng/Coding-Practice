#include <bits/stdc++.h>
#define int long long

#define MAX 300100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], dp[MAX][3];

int delta(int X, int Y) { return X > Y ? 1 : (X == Y ? 0 : -1); }

void solve() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        dp[i][0] = dp[i][1] = dp[i][2] = -INF;
    }

    dp[0][0] = 0;
    dp[0][1] = dp[0][2] = -INF;

    for (int i = 1; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] + delta(A[i], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][2] = max(dp[i - 1][2] + delta(A[i], dp[i - 1][2]), dp[i - 1][1] + delta(A[i], dp[i - 1][1]));
    }

    cout << max({0ll, dp[N][2], dp[N][1]}) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}