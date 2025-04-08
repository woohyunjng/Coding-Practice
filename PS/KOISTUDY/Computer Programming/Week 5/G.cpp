#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

int ans[1001][1001];
pr go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, X, Y;
    queue<pr> q;
    pr K;

    cin >> N >> M >> S;

    while (S--)
        cin >> X >> Y, q.push({X, Y}), ans[X][Y] = 1;

    while (!q.empty()) {
        K = q.front(), q.pop();
        for (pr i : go) {
            X = K[0] + i[0], Y = K[1] + i[1];
            if (X < 1 || X > N || Y < 1 || Y > M || ans[X][Y] != 0)
                continue;
            ans[X][Y] = ans[K[0]][K[1]] + 1, q.push({X, Y});
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}