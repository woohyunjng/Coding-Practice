#include <bits/stdc++.h>
#define int long long

#define MAX_N 60
#define MAX_T 100010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX_N][MAX_T];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T;
    cin >> N >> T;

    vector<tp> arr(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i][0];
    for (int i = 0; i < N; i++)
        cin >> arr[i][1];
    for (int i = 0; i < N; i++)
        cin >> arr[i][2];

    sort(arr.begin(), arr.end(), [](tp a, tp b) {
        return a[2] * b[1] < b[2] * a[1];
    });

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= T; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (j >= arr[i - 1][2])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i - 1][2]] + arr[i - 1][0] - j * arr[i - 1][1]);
        }
    }

    cout << dp[N][T];

    return 0;
}