#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 3000001;
const int MOD = 998244353;

int A[2][MAX], V[2][2], cnt[2][2], two[MAX];
bool chk[2][2][4], fr[2][4][MAX], bk[2][4][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int TC, N, X, Y, Z, ans;
    bool flag;

    string S, T;

    two[0] = 1;
    for (int i = 1; i < MAX; i++)
        two[i] = two[i - 1] * 2 % MOD;

    cin >> TC;
    while (TC--) {
        cin >> N >> S >> T, ans = 0;

        V[0][0] = V[0][1] = V[1][0] = V[1][1] = 0;
        cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = 0;

        memset(chk, 0, sizeof(chk));

        for (int i = 1; i <= N * 2 + 1; i++) {
            A[0][i] = S[i - 1] - 'A' + 1, A[1][i] = T[i - 1] - 'A' + 1;
            A[0][i] = max(0ll, A[0][i]), A[1][i] = max(0ll, A[1][i]);

            if (A[0][i])
                V[0][i & 1] = V[0][i & 1] == 0 ? A[0][i] : (V[0][i & 1] == A[0][i] ? A[0][i] : -1);
            if (A[1][i])
                V[1][i & 1] = V[1][i & 1] == 0 ? A[1][i] : (V[1][i & 1] == A[1][i] ? A[1][i] : -1);

            chk[0][i & 1][A[0][i]] = chk[1][i & 1][A[1][i]] = true;
            cnt[0][i & 1] += A[0][i] == 0, cnt[1][i & 1] += A[1][i] == 0;
        }

        for (int i = 0; i <= 3; i++)
            fr[0][i][0] = fr[1][i][0] = bk[0][i][0] = bk[1][i][0] = true;

        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= N + 1; j++)
                for (int k = 1; k <= 3; k++) {
                    fr[i][k][j] = fr[i][k][j - 1];
                    fr[i][k][j] &= (A[i][j * 2 - 1] == 0 || A[i][j * 2 - 1] == k);

                    bk[i][k][j] = bk[i][k][j - 1];
                    bk[i][k][j] &= (A[i][N * 2 + 3 - j * 2] == 0 || A[i][N * 2 + 3 - j * 2] == k);
                }

        for (int i = 0; i < 2; i++)
            for (X = 1; X <= 3; X++)
                for (Y = 1; Y <= 3; Y++) {
                    if (X == Y)
                        continue;
                    Z = 6 - X - Y;

                    if ((V[i][1] != 0 && V[i][1] != X) || (V[i][0] != 0 && V[i][0] != Y) || (V[i ^ 1][1] != 0 && V[i ^ 1][1] != Z) || chk[i ^ 1][0][Z])
                        continue;

                    ans = (ans + two[cnt[i ^ 1][0]]) % MOD;
                }

        for (X = 1; X <= 3; X++)
            for (Y = 1; Y <= 3; Y++) {
                if (X == Y)
                    continue;
                Z = 6 - X - Y;

                if ((V[0][0] != 0 && V[0][0] != X) || (V[1][0] != 0 && V[1][0] != X) || (V[0][1] != 0 && V[0][1] != Y) || (V[1][1] != 0 && V[1][1] != Z))
                    continue;

                ans = (ans - 1 + MOD) % MOD;
            }

        for (X = 1; X <= 3; X++) {
            if ((V[0][0] != 0 && V[0][0] != X) || (V[1][0] != 0 && V[1][0] != X) || chk[0][1][X] || chk[1][1][X])
                continue;

            for (Y = 1; Y <= 3; Y++) {
                if (X == Y)
                    continue;
                Z = 6 - X - Y;
                for (int i = 1; i <= N; i++)
                    if (fr[0][Y][i] && fr[1][Z][i] && bk[0][Z][N + 1 - i] && bk[1][Y][N + 1 - i])
                        ans = (ans + 1) % MOD;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}