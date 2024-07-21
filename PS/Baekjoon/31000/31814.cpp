#include <bits/stdc++.h>
#define int long long
#define MAX 5010

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX], arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = N; i >= 1; i--) {
        for (int j = N; j >= 1; j--) {
            if (arr[i] <= arr[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;
            res += dp[i][j];
        }
    }

    cout << res;

    return 0;
}