#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 1001;

int dis[MAX][MAX];
pr go[8] = {{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    pr K;

    queue<pr> q;

    cin >> N >> M >> X >> Y;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            dis[i][j] = -1;

    q.push({X, Y}), dis[X][Y] = 0;

    while (!q.empty()) {
        K = q.front(), q.pop();
        for (pr i : go) {
            X = K[0] + i[0], Y = K[1] + i[1];
            if (X < 1 || X > N || Y < 1 || Y > M || dis[X][Y] != -1)
                continue;
            dis[X][Y] = dis[K[0]][K[1]] + 1, q.push({X, Y});
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            cout << dis[i][j] << ' ';
        cout << '\n';
    }
}