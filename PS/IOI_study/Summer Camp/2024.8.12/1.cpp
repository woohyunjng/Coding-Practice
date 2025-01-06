#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX], arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, res;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        res = -INF;
        for (int i = 1; i <= N; i++) {
            dp[i] = arr[i] + max(dp[i - 1], 0ll);
            res = max(res, dp[i]);
        }

        cout << max(res, 0ll) << '\n';
    }

    return 0;
}