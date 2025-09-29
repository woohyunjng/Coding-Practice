#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
const int INF = 1e9;

int D[MAX][MAX], P[MAX][MAX];
vector<int> ans;

void prt(int s, int e) {
    if (P[s][e] == s) {
        ans.push_back(s);
        return;
    }
    prt(s, P[s][e]), prt(P[s][e], e);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            D[i][j] = (i == j ? 0 : INF), P[i][j] = i;

    while (M--) {
        cin >> X >> Y >> Z;
        D[X][Y] = min(D[X][Y], Z);
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) {
                if (D[i][k] + D[k][j] < D[i][j])
                    P[i][j] = k, D[i][j] = D[i][k] + D[k][j];
            }

    for (int i = 1; i <= N; i++, cout << '\n')
        for (int j = 1; j <= N; j++)
            cout << (D[i][j] == INF ? 0 : D[i][j]) << ' ';

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (i == j || D[i][j] == INF) {
                cout << 0 << '\n';
                continue;
            }

            prt(i, j), ans.push_back(j);

            cout << ans.size() << ' ';
            for (int i : ans)
                cout << i << ' ';
            cout << '\n', ans.clear();
        }

    return 0;
}