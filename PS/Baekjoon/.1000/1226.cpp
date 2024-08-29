#include <bits/stdc++.h>
#define int long long

#define MAX 310
#define MAX_VAL 100010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[2][MAX_VAL];
pr arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, sm = 0, res = 0, before = 0, K = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
        sm += arr[i].first;
    }
    sort(arr + 1, arr + N + 1, greater<pr>());

    dp[0][0] = -1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sm; j++)
            dp[i & 1][j] = dp[(i & 1) ^ 1][j];

        for (int j = 0; j <= sm; j++) {
            if (j < arr[i].first)
                continue;
            if ((j - arr[i].first) * 2 <= sm && dp[(i & 1) ^ 1][j - arr[i].first] != 0 && dp[i & 1][j] == 0) {
                dp[i & 1][j] = i;
                res = max(res, j);
            }
        }
    }

    vector<int> res_dang;
    K = N;

    while (res) {
        if (dp[K & 1][res] != before) {
            before = dp[K & 1][res];
            res -= arr[before].first;
            res_dang.push_back(arr[before].second);
        }
        K--;
    }

    cout << res_dang.size() << '\n';
    for (int i : res_dang)
        cout << i << ' ';

    return 0;
}