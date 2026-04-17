#include <bits/stdc++.h>
#define int long long

#define MAX_LEV 110
#define MAX 10010
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;
typedef array<int, 3> tp;

int dp[MAX_LEV][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T, S, P, H;
    vector<tp> arr;
    arr.push_back({-1, 0, 0});

    cin >> N >> T;
    for (int i = 1; i <= N; i++) {
        cin >> S >> P >> H;
        arr.push_back({S + 1, P, H});
    }
    sort(arr.begin(), arr.end());

    fill(&dp[0][0], &dp[MAX_LEV][0], -INF);
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = T; j >= 0; j--) {
            if (j >= arr[i][1])
                dp[arr[i][0]][j] = max({dp[arr[i][0]][j],
                                        dp[arr[i][0]][j - arr[i][1]] + arr[i][2],
                                        dp[arr[i][0] - 1][j - arr[i][1]] + arr[i][2]});
        }
    }

    cout << *max_element(&dp[0][0], &dp[MAX_LEV][0]) << '\n';

    return 0;
}
