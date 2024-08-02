#include <bits/stdc++.h>
#define int long long
#define MAX 1010

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][MAX], dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res = 0;
    string S;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= M; j++)
            arr[i][j] = S[j - 1] - '0';
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!arr[i][j]) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            res = max(res, dp[i][j]);
        }
    }

    cout << res * res;

    return 0;
}