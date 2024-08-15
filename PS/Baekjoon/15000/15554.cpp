#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

pr arr[MAX];
int dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, val = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= N; i++) {
        dp[i] = arr[i].second + max(0ll, dp[i - 1] + arr[i - 1].first - arr[i].first);
        res = max(res, dp[i]);
    }

    cout << res;

    return 0;
}