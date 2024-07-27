#include <bits/stdc++.h>
#define int long long
#define MAX 100
#define MAX_VAL 10010

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

pr dp[MAX][MAX_VAL];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, A, B, res, mx = 0;
    cin >> N >> X >> Y;

    vector<pr> arr;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        arr.push_back({A, B});
    }
    sort(arr.begin(), arr.end());

    for (int i = 1; i <= N; i++) {
        A = arr[i - 1].first, B = arr[i - 1].second;
        for (int j = 1; j <= Y; j++) {
            if (B <= j && dp[i - 1][j - B].second + A <= X)
                dp[i][j] = {
                    dp[i - 1][j - B].first + 1,
                    dp[i - 1][j - B].second + A};
            if (dp[i - 1][j].first > dp[i][j].first || (dp[i - 1][j].first == dp[i][j].first && dp[i - 1][j].second < dp[i][j].second))
                dp[i][j] = dp[i - 1][j];
            mx = max(mx, dp[i][j].first);
        }
    }

    cout << (mx < N ? mx + 1 : mx);

    return 0;
}