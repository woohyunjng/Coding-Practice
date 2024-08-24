#include <bits/stdc++.h>
#define int long long
#define MAX 10000000000

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

struct Point {
    int x, y;

    int dis(Point A) { return abs(x - A.x) + abs(y - A.y); };
};

Point arr[2000];
int dp[2000][2000];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, W, A, B, mn = MAX;
    cin >> N;
    cin >> W;

    for (int i = 1; i <= W; i++)
        cin >> arr[i].x >> arr[i].y;

    for (int i = 1; i <= W; i++) {
        dp[0][i] = dp[0][i - 1] + arr[i].dis(i != 1 ? arr[i - 1] : (Point){N, N});
        dp[i][0] = dp[i - 1][0] + arr[i].dis(i != 1 ? arr[i - 1] : (Point){1, 1});
        dp[i][i] = MAX;
    }

    for (int i = 1; i <= W; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = MAX;
            dp[j][i] = MAX;
            if (i == j + 1) {
                for (int k = 0; k < j; k++) {
                    A = dp[k][j] + arr[i].dis(k ? arr[k] : (Point){1, 1}), B = dp[j][k] + arr[i].dis(k ? arr[k] : (Point){N, N});
                    if (A < dp[i][j])
                        dp[i][j] = A;
                    if (B < dp[j][i])
                        dp[j][i] = B;
                }
            } else {
                dp[i][j] = dp[i - 1][j] + arr[i].dis(arr[i - 1]);
                dp[j][i] = dp[j][i - 1] + arr[i].dis(arr[i - 1]);
            }
        }
    }

    for (int i = 0; i < W; i++) {
        if (dp[i][W] < mn) {
            mn = dp[i][W];
            A = i, B = W;
        }

        if (dp[W][i] < mn) {
            mn = dp[W][i];
            A = W, B = i;
        }
    }
    cout << mn << '\n';
    return 0;
}