#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1002;
const int MOD = 998244353;

int A[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans = 1;
    string S;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= N; j++) {
            if (S[j - 1] == '#')
                A[i][j] = 1;
            else if (S[j - 1] == '.')
                A[i][j] = 0;
            else
                A[i][j] = -1;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i][j] != -1)
                continue;
            X = j;
            while (j + 1 <= N && A[i][j + 1] == -1)
                j++;
            Y = j++;

            if (A[i][X - 1] == 1 && A[i][Y + 1] == 1)
                ans = 0;
            else if (A[i][X - 1] == 0 && A[i][Y + 1] == 0)
                ans = ans * (Y - X + 2) % MOD;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[j][i] != -1)
                continue;
            X = j;
            while (j + 1 <= N && A[j + 1][i] == -1)
                j++;
            Y = j++;

            if (A[X - 1][i] == 1 && A[Y + 1][i] == 1)
                ans = 0;
            else if (A[X - 1][i] == 0 && A[Y + 1][i] == 0)
                ans = ans * (Y - X + 2) % MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}