#include <bits/stdc++.h>
#define int long long
#define MAX 100100
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, D, res = -INF;
    cin >> N >> D;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    priority_queue<pr> pq;
    for (int i = N; i >= 1; i--) {
        while (!pq.empty() && pq.top().second > i + D)
            pq.pop();
        if (!pq.empty())
            dp[i] = max(dp[i], pq.top().first);
        dp[i] += arr[i];
        pq.push({dp[i], i});

        res = max(res, dp[i]);
    }

    cout << res;

    return 0;
}