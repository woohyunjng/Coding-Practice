#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<pr, 2> dpr;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], B[MAX];

vector<dpr> dnc(int l, int r) {
    vector<dpr> res(r - l + 2, (dpr){(pr){-INF, -INF}, (pr){-INF, -INF}}), lval, rval;
    res[0][0][0] = 0;

    if (l == r) {
        res[1][1][1] = A[l];
        return res;
    }

    int m = l + r >> 1, X, Y, px, py;
    lval = dnc(l, m), rval = dnc(m + 1, r);

    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++) {
            for (int i = 0; i < (int)lval.size(); i++)
                res[i][x][0] = max(res[i][x][0], lval[i][x][y]);
            for (int i = 0; i < (int)rval.size(); i++)
                res[i][0][y] = max(res[i][0][y], rval[i][x][y]);

            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    for (int w = 0; w < 2; w++)
                        for (int z = 0; z < 2; z++) {
                            X = w, Y = z;
                            px = (i == 1 && j == 1 && lval.size() == 2) ? 0 : x, py = (i == 1 && j == 1 && rval.size() == 2) ? 0 : y;
                            for (int k = w + z;; k += 2) {
                                res[k][x][y] = max(res[k][x][y], lval[X][x][i] + rval[Y][j][y]);
                                if (i == 1 && j == 1)
                                    res[k][px][py] = max(res[k][px][py], lval[X][x][i] + rval[Y][j][y] + B[m]);

                                if (X + 2 >= (int)lval.size() && Y + 2 >= (int)rval.size())
                                    break;
                                if (X + 2 >= (int)lval.size() || (Y + 2 < (int)rval.size() && lval[X][x][i] + rval[Y + 2][j][y] > lval[X + 2][x][i] + rval[Y][j][y]))
                                    Y += 2;
                                else
                                    X += 2;
                            }
                        }
        }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i < N; i++)
        cin >> B[i];

    vector<dpr> ans = dnc(1, N);
    for (int i = 1; i <= N; i++)
        cout << max({ans[i][0][0], ans[i][1][0], ans[i][0][1], ans[i][1][1]}) << '\n';

    return 0;
}