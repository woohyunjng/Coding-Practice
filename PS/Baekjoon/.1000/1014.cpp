#include <bits/stdc++.h>
#define int long long
#define MAX 11
#define MAX_MASK (1 << 11)

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX_MASK];
bool arr[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, C, res = 0;
    string S;
    bool val;

    cin >> C;
    while (C--) {
        cin >> N >> M;

        for (int i = 1; i <= N; i++) {
            cin >> S;
            for (int j = 0; j < M; j++) {
                if (S[j] == '.')
                    arr[i][j] = true;
                else
                    arr[i][j] = false;
            }
        }

        res = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < (1 << M); j++) {
                dp[i][j] = 0;

                val = true;
                for (int k = 0; k < M; k++) {
                    if ((j & (1 << k)) && !arr[i][k]) {
                        val = false;
                        break;
                    }
                }
                for (int k = 0; k < M - 1; k++) {
                    if ((j & (1 << k)) && (j & (1 << (k + 1)))) {
                        val = false;
                        break;
                    }
                }

                if (!val)
                    continue;

                for (int k = 0; k < (1 << M); k++) {
                    if (i >= 2 && !dp[i - 1][k])
                        continue;
                    if ((k & 1) && (j & 2))
                        continue;
                    if ((k & (1 << (M - 1))) && (j & (1 << (M - 2))))
                        continue;

                    val = true;
                    for (int l = 1; l < M - 1; l++) {
                        if (!(k & (1 << l)))
                            continue;
                        if ((j & (1 << (l - 1))) || (j & (1 << (l + 1)))) {
                            val = false;
                            break;
                        }
                    }

                    if (val)
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + __builtin_popcount(j));
                }
                res = max(res, dp[i][j]);
            }
        }

        cout << res << '\n';
    }

    return 0;
}