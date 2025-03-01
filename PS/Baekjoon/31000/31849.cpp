#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 2000;
const int MAX_R = 600000;
const int INF = 0x3f3f3f3f3f3f3f3f;

int val[MAX][MAX], A[MAX_R], B[MAX_R], P[MAX_R];
bool chk[MAX][MAX];

pr go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, R, C, X, Y, ans = INF;

    queue<pr> q;
    pr K;

    cin >> N >> M >> R >> C;

    for (int i = 1; i <= R; i++)
        cin >> A[i] >> B[i] >> P[i];

    for (int i = 1; i <= C; i++) {
        cin >> X >> Y;
        q.push({X, Y}), chk[X][Y] = true;
    }

    while (!q.empty()) {
        K = q.front(), q.pop();
        for (pr i : go) {
            X = K[0] + i[0], Y = K[1] + i[1];
            if (X <= 0 || X > N || Y <= 0 || Y > M || chk[X][Y])
                continue;
            chk[X][Y] = true, val[X][Y] = val[K[0]][K[1]] + 1;
            q.push({X, Y});
        }
    }

    for (int i = 1; i <= R; i++)
        ans = min(ans, P[i] * val[A[i]][B[i]]);
    cout << ans << '\n';

    return 0;
}