#include <bits/stdc++.h>
#define int long long
#define MAX 10010
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int start_arr[MAX], end_arr[MAX], dp[MAX][10];
pr track[MAX][10];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, res = INF;
    string X, Y;

    cin >> N;
    cin >> X;
    cin >> Y;

    for (int i = 1; i <= N; i++)
        start_arr[i] = X[i - 1] - '0';
    for (int i = 1; i <= N; i++)
        end_arr[i] = Y[i - 1] - '0';

    fill(&dp[0][0], &dp[N + 1][10], INF);

    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (dp[i - 1][j] == INF)
                continue;
            A = (start_arr[i] + j) % 10;

            B = 0;
            if (A > end_arr[i])
                B = 10;
            B += end_arr[i] - A;

            if (dp[i][(j + B) % 10] > dp[i - 1][j] + B) {
                dp[i][(j + B) % 10] = dp[i - 1][j] + B;
                track[i][(j + B) % 10] = {j, B};
            }

            B = 0;
            if (A < end_arr[i])
                B = 10;
            B += A - end_arr[i];

            if (dp[i][j] > dp[i - 1][j] + B) {
                dp[i][j] = dp[i - 1][j] + B;
                track[i][j] = {j, -B};
            }
        }
    }

    for (int i = 0; i <= 9; i++) {
        if (dp[N][i] < res) {
            res = dp[N][i];
            A = i;
        }
    }

    cout << res << '\n';

    stack<pr> st;

    for (int i = N; i >= 1; i--) {
        st.push({i, track[i][A].second});
        A = track[i][A].first;
    }

    while (!st.empty()) {
        pr K = st.top();
        st.pop();
        cout << K.first << ' ' << K.second << '\n';
    }

    return 0;
}