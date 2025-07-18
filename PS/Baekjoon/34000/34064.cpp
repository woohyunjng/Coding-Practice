#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 501;

bool chk[MAX][MAX];
int V[MAX][MAX];
pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, A[4], B[4], C[2], X, Y, ans = 0;
    pr P;
    queue<pr> q;

    cin >> N >> M >> K;
    while (K--)
        cin >> X >> Y, chk[X][Y] = true;

    for (int i = 0; i < 4; i++)
        cin >> A[i] >> B[i];

    K = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            if (chk[i][j])
                continue;
            q.push({i, j}), ++K, chk[i][j] = true;
            C[0] = C[1] = 0;

            while (!q.empty()) {
                P = q.front(), q.pop(), V[P[0]][P[1]] = K;
                if (A[0] <= P[0] && P[0] <= A[1] && B[0] <= P[1] && P[1] <= B[1])
                    C[0]++;
                if (A[2] <= P[0] && P[0] <= A[3] && B[2] <= P[1] && P[1] <= B[3])
                    C[1]++;

                for (pr i : go) {
                    X = P[0] + i[0], Y = P[1] + i[1];
                    if (X < 1 || X > N || Y < 1 || Y > M || chk[X][Y])
                        continue;
                    q.push({X, Y}), chk[X][Y] = true;
                }
            }

            ans += C[0] * C[1];
        }

    cout << ans << '\n';

    return 0;
}