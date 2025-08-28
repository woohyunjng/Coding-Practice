#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 501;
const int INF = 0x3f3f3f3f3f3f3f;

int D[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, C, ans_v = -1, ans = 0;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            D[i][j] = INF;
    for (int i = 1; i <= N; i++)
        D[i][i] = 0;

    while (M--) {
        cin >> U >> V >> C;
        D[U][V] = min(D[U][V], C), D[V][U] = min(D[V][U], C);
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                D[j][k] = min(D[j][k], D[j][i] + D[i][k]);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (D[i][j] >= ans)
                ans = D[i][j], ans_v = i;
        }
    }

    for (int i = 1; i <= N; i++)
        cout << D[ans_v][i] << ' ';
    cout << '\n';

    return 0;
}