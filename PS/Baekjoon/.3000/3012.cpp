#include <bits/stdc++.h>
#define int long long

#define MAX 210
#define MOD 100000
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool one_of(char A, char B) {
    if (A == '?' && B != '?')
        if (B == ')' || B == ']' || B == '}')
            return true;
    if (A != '?' && B == '?')
        if (A == '(' || A == '[' || A == '{')
            return true;
    return false;
}

bool match(char A, char B) {
    if (A == '(' && B == ')')
        return true;
    else if (A == '[' && B == ']')
        return true;
    else if (A == '{' && B == '}')
        return true;
    return false;
}

int dp[MAX][MAX][2];
bool dp_upper[MAX][MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S, ans;
    int N;

    cin >> N;
    cin >> S;

    for (int i = 2; i <= N; i += 2) {
        for (int j = 0; j + i - 1 < N; j++) {
            if (i == 2) {
                if (S[j] == '?' && S[j + 1] == '?')
                    dp[j][j + i - 1][0] = dp[j][j + i - 1][1] = 3;
                else if (one_of(S[j], S[j + 1]))
                    dp[j][j + i - 1][0] = dp[j][j + i - 1][1] = 1;
                else if (match(S[j], S[j + 1]))
                    dp[j][j + i - 1][0] = dp[j][j + i - 1][1] = 1;
                else
                    dp[j][j + i - 1][0] = dp[j][j + i - 1][1] = 0;
                continue;
            }

            if (S[j] == '?' && S[j + i - 1] == '?') {
                dp[j][j + i - 1][1] = 3 * dp[j + 1][j + i - 2][0];
                dp[j][j + i - 1][0] = 3 * dp[j + 1][j + i - 2][0];

                dp_upper[j][j + i - 1][0] = dp_upper[j + 1][j + i - 2][0];
                dp_upper[j][j + i - 1][1] = dp_upper[j + 1][j + i - 2][0];

                if (dp[j][j + i - 1][1] >= MOD) {
                    dp[j][j + i - 1][1] %= MOD;
                    dp_upper[j][j + i - 1][1] = true;
                }
                if (dp[j][j + i - 1][0] >= MOD) {
                    dp[j][j + i - 1][0] %= MOD;
                    dp_upper[j][j + i - 1][0] = true;
                }
            } else if (one_of(S[j], S[j + i - 1])) {
                dp[j][j + i - 1][1] = dp[j + 1][j + i - 2][0];
                dp[j][j + i - 1][0] = dp[j + 1][j + i - 2][0];

                dp_upper[j][j + i - 1][0] = dp_upper[j + 1][j + i - 2][0];
                dp_upper[j][j + i - 1][1] = dp_upper[j + 1][j + i - 2][0];

                if (dp[j][j + i - 1][1] >= MOD) {
                    dp[j][j + i - 1][1] %= MOD;
                    dp_upper[j][j + i - 1][1] = true;
                }
                if (dp[j][j + i - 1][0] >= MOD) {
                    dp[j][j + i - 1][0] %= MOD;
                    dp_upper[j][j + i - 1][0] = true;
                }
            } else if (match(S[j], S[j + i - 1])) {
                dp[j][j + i - 1][1] = dp[j + 1][j + i - 2][0];
                dp[j][j + i - 1][0] = dp[j + 1][j + i - 2][0];

                dp_upper[j][j + i - 1][0] = dp_upper[j + 1][j + i - 2][0];
                dp_upper[j][j + i - 1][1] = dp_upper[j + 1][j + i - 2][0];

                if (dp[j][j + i - 1][1] >= MOD) {
                    dp[j][j + i - 1][1] %= MOD;
                    dp_upper[j][j + i - 1][1] = true;
                }
                if (dp[j][j + i - 1][0] >= MOD) {
                    dp[j][j + i - 1][0] %= MOD;
                    dp_upper[j][j + i - 1][0] = true;
                }
            }

            for (int k = j + 1; k + 1 < j + i - 1; k += 2) {
                dp[j][j + i - 1][0] = dp[j][j + i - 1][0] + dp[j][k][1] * dp[k + 1][j + i - 1][0];
                dp_upper[j][j + i - 1][0] = dp_upper[j][j + i - 1][0] || dp_upper[j][k][1] || dp_upper[k + 1][j + i - 1][0];
                if (dp[j][j + i - 1][0] >= MOD) {
                    dp[j][j + i - 1][0] %= MOD;
                    dp_upper[j][j + i - 1][0] = true;
                }
            }
        }
    }

    if (dp_upper[0][N - 1][1])
        cout << setw(5) << setfill('0') << dp[0][N - 1][0];
    else
        cout << dp[0][N - 1][0];
    return 0;
}