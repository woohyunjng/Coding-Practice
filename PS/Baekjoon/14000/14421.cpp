#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;

typedef array<int, 2> pr;

const int MAX = 2002;
const int INF = 1000000001;

int A[MAX][MAX], C[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, ans = INF, X = 0, Y = 0, MN, MX;
    bool flag;

    vector<pr> val;

    cin >> H >> W;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++) {
            cin >> A[i][j];
            if (A[i][j] > A[X][Y])
                X = i, Y = j;
        }

    C[0][0] = W, C[0][1] = H;
    val.reserve(max(H, W));

    for (int t1 = 0; t1 < 2; t1++) {
        for (int t2 = 0; t2 < 2; t2++) {
            for (int st = 0, en = INF, md; st <= en;) {
                md = st + en >> 1, flag = true, val.clear();
                for (int i = 1; i <= H; i++)
                    C[i][0] = W;
                for (int i = 1; i <= W; i++)
                    C[i][1] = H;

                for (int i = 1; i <= H; i++) {
                    for (int j = 1; j <= W; j++)
                        if (A[i][j] < A[X][Y] - md) {
                            if (val.empty() || (val.back()[1] > j))
                                val.push_back({i, j}), C[i][0] = j - 1, C[j][1] = i - 1;
                            break;
                        }
                }
                for (int i = 1; i <= H; i++)
                    C[i][0] = min(C[i - 1][0], C[i][0]);
                for (int i = 1; i <= W; i++)
                    C[i][1] = min(C[i - 1][1], C[i][1]);
                flag &= Y <= C[X][0];

                MN = INF, MX = 0;
                for (int i = 1; i <= H; i++)
                    for (int j = C[i][0] + 1; j <= W; j++)
                        MN = min(MN, A[i][j]), MX = max(MX, A[i][j]);
                flag &= (MX - MN) <= md;

                if (flag)
                    en = md - 1, ans = min(ans, md);
                else
                    st = md + 1;
            }

            for (int i = 1; i <= W; i++)
                for (int j = 1; j <= (H + 1) / 2; j++)
                    swap(A[j][i], A[H + 1 - j][i]);
            X = H + 1 - X;
        }

        for (int i = 1; i <= H; i++)
            reverse(A[i] + 1, A[i] + W + 1);
        Y = W + 1 - Y;
    }

    cout << ans << '\n';

    return 0;
}