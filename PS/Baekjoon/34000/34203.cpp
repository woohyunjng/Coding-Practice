#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 501;
const int MAX_M = 300000;
const int INF = 2e9;

int D[MAX][MAX], U[MAX_M], V[MAX_M], ans[MAX_M], uf[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    if (X > Y)
        swap(X, Y);
    uf[Y] = X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        uf[i] = i;
        for (int j = 1; j <= N; j++)
            D[i][j] = i == j ? 0 : INF;
    }

    for (int i = 1; i <= M; i++) {
        cin >> U[i] >> V[i];
        D[U[i]][V[i]] = D[V[i]][U[i]] = 1;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                D[j][k] = min(D[j][k], D[j][i] + D[i][k]);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            ans[M] += D[i][j];

    for (int i = M; i > 1; i--) {
        ans[i - 1] = ans[i];
        if (find(U[i]) == find(V[i]))
            continue;
        uni(find(U[i]), find(V[i])), D[U[i]][V[i]] = D[V[i]][U[i]] = 0, ans[i - 1] = 0;
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                D[j][k] = min({D[j][k], D[j][U[i]] + D[V[i]][k], D[j][V[i]] + D[U[i]][k]});
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                ans[i - 1] += D[j][k];
    }

    for (int i = 1; i <= M; i++)
        cout << ans[i] << '\n';

    return 0;
}