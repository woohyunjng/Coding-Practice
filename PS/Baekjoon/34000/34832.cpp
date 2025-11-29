#include <bits/stdc++.h>
#define int long long
#define ll __int128_t

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 4> tp;

const int MAX = 501;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX][MAX], B[MAX][MAX], D[MAX][MAX][2];
tp par[MAX][MAX][2];
pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, R[2], C[2], X, Y, Z, DR;
    ll CS;
    string ans = "";

    cin >> N >> R[0] >> C[0] >> R[1] >> C[1];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> B[i][j];

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    tp K;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            D[i][j][0] = D[i][j][1] = INF;

    D[R[1]][C[1]][0] = D[R[1]][C[1]][1] = A[R[1]][C[1]];
    pq.push({A[R[1]][C[1]], R[1], C[1], 0}), pq.push({A[R[1]][C[1]], R[1], C[1], 1});

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (D[K[1]][K[2]][K[3]] < K[0])
            continue;

        for (pr i : go) {
            X = K[1] + i[0], Y = K[2] + i[1], Z = i[0] == 0 ? 1 : 0;
            if (X < 1 || X > N || Y < 1 || Y > N)
                continue;

            CS = (ll)(K[0] - A[K[1]][K[2]]) * (Z == K[3] ? 1 : B[K[1]][K[2]]) + (ll)A[X][Y] + (ll)A[K[1]][K[2]];
            if ((ll)D[X][Y][Z] > CS) {
                D[X][Y][Z] = CS, par[X][Y][Z] = {K[1], K[2], K[3], 0};
                pq.push({(int)CS, X, Y, Z});
            }
        }
    }

    DR = (D[R[0]][C[0]][0] < D[R[0]][C[0]][1]) ? 0 : 1;
    while (R[0] != R[1] || C[0] != C[1]) {
        X = par[R[0]][C[0]][DR][0], Y = par[R[0]][C[0]][DR][1];
        if (X == R[0])
            ans += Y == C[0] + 1 ? 'R' : 'L';
        else
            ans += X == R[0] + 1 ? 'D' : 'U';
        DR = par[R[0]][C[0]][DR][2], R[0] = X, C[0] = Y;
    }

    cout << ans.size() << '\n';
    cout << ans << '\n';

    return 0;
}