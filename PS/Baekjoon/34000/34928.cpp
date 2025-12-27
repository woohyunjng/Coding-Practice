#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

bool dp[MAX][5];
int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    string S;

    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        if (S[i - 1] == 'P')
            A[i] = 1;
        else if (S[i - 1] == 'A')
            A[i] = 2;
        else if (S[i - 1] == 'U')
            A[i] = 3;
        else if (S[i - 1] == 'L')
            A[i] = 4;
    }

    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        if (i >= 2) {
            for (int j = 0; j <= 4; j++)
                dp[i][j] = dp[i - 2][j];
        }
        for (int j = 1; j <= 4; j++) {
            if (A[i] != j)
                continue;
            dp[i][j] |= dp[i - 1][j - 1];
        }
    }

    cout << (dp[N][4] ? "YES" : "NO") << '\n';

    return 0;
}