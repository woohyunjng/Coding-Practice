#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

// n : 1 a : 2 r : 3 e : 4 k : 5

pr arr[MAX][5];
int dp[MAX][5];
map<char, int> mp = {{'n', 0}, {'a', 1}, {'r', 2}, {'e', 3}, {'k', 4}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, X, res, A, B;
    string S;

    cin >> T;

    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            cin >> S;
            for (int j = 0; j < 5; j++) {
                arr[i][j] = {0, 0};
                X = j;
                for (char k : S) {
                    if (mp.find(k) == mp.end())
                        continue;
                    arr[i][j].second++;

                    if (mp[k] == X) {
                        arr[i][j].first++;
                        X = (X + 1) % 5;
                    }
                }
            }
        }

        res = 0;
        dp[N + 1][0] = -INF, dp[N + 1][1] = -INF, dp[N + 1][2] = -INF, dp[N + 1][3] = -INF, dp[N + 1][4] = -INF;
        for (int i = N; i >= 1; i--) {
            for (int j = 0; j < 5; j++) {
                dp[i][j] = dp[i + 1][j];
                if (arr[i][j].first < 5 - j) {
                    A = 0;
                    dp[i][j] = max(dp[i][j], -INF);
                    X = (j + arr[i][j].first) % 5;
                } else {
                    if (j != 0)
                        A = 5 + ((arr[i][j].first - (5 - j)) / 5) * 5, B = arr[i][j].second - (arr[i][j].first - (arr[i][j].first - (5 - j)) % 5);
                    else
                        A = (arr[i][j].first / 5) * 5, B = arr[i][j].second - (arr[i][j].first / 5) * 5;
                    dp[i][j] = max(dp[i][j], A - B);
                    X = (j + arr[i][j].first) % 5;
                }
                B = arr[i][j].second - arr[i][j].first;

                dp[i][j] = max(dp[i][j], dp[i + 1][X] + A - B);

                if (j == 0)
                    res = max(res, dp[i][j]);
            }
        }

        cout << res << '\n';
    }

    return 0;
}