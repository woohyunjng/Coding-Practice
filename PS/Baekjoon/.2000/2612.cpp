#include <bits/stdc++.h>
#define int long long

#define MAX 1010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arrA[MAX], arrB[MAX], dp[MAX][MAX];
pr track[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res = -1, res_N, res_M;
    string A, B, res_A, res_B;

    cin >> N;
    cin >> A;
    cin >> M;
    cin >> B;

    for (int i = 1; i <= N; i++)
        arrA[i] = A[i - 1] - 'A' + 1;
    for (int i = 1; i <= M; i++)
        arrB[i] = B[i - 1] - 'A' + 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (dp[i][j] < dp[i - 1][j - 1] + (arrA[i] == arrB[j] ? 3 : -2)) {
                dp[i][j] = dp[i - 1][j - 1] + (arrA[i] == arrB[j] ? 3 : -2);
                track[i][j] = {i - 1, j - 1};
            }
            if (dp[i][j] < dp[i - 1][j] - 2) {
                dp[i][j] = dp[i - 1][j] - 2;
                track[i][j] = {i - 1, j};
            }
            if (dp[i][j] < dp[i][j - 1] - 2) {
                dp[i][j] = dp[i][j - 1] - 2;
                track[i][j] = {i, j - 1};
            }
            if (dp[i][j] < 0) {
                dp[i][j] = 0;
                track[i][j] = {0, 0};
            }

            if (dp[i][j] > res) {
                res = dp[i][j];
                res_N = i, res_M = j;
            }
        }
    }

    cout << res << '\n';

    while (res_N != 0 || res_M != 0) {
        pr tmp = track[res_N][res_M];
        if (dp[res_N][res_M] == 0)
            break;
        if (tmp.first != res_N) {
            res_A += A[res_N - 1];
            res_N = tmp.first;
        }
        if (tmp.second != res_M) {
            res_B += B[res_M - 1];
            res_M = tmp.second;
        }
    }
    reverse(res_A.begin(), res_A.end());
    reverse(res_B.begin(), res_B.end());
    cout << res_A << '\n'
         << res_B << '\n';

    return 0;
}