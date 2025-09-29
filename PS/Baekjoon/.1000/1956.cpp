#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 401;
const int INF = 2e9;

int D[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z, ans = INF;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            D[i][j] = (i == j ? 0 : INF);

    while (M--) {
        cin >> X >> Y >> Z;
        D[X][Y] = Z;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (i == j)
                continue;
            ans = min(ans, D[i][j] + D[j][i]);
        }

    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}