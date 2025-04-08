#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;

typedef array<int, 2> pr;

int A[MAX][MAX], val[MAX][MAX];
pr go[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, X, Y, ans = 0;
    string S;

    queue<pr> q;
    pr K;

    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        cin >> S;
        for (int j = 1; j <= W; j++) {
            if (S[j - 1] != '.')
                A[i][j] = S[j - 1] - '0';
            else
                q.push({i, j});
        }
    }

    while (!q.empty()) {
        K = q.front(), q.pop();
        for (pr i : go) {
            X = K[0] + i[0], Y = K[1] + i[1];
            if (X < 1 || X > H || Y < 1 || Y > W || A[X][Y] == 0)
                continue;
            val[X][Y] = max(val[X][Y], val[K[0]][K[1]]);
            if (--A[X][Y] == 0)
                val[X][Y]++, q.push({X, Y});
        }
    }

    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            ans = max(ans, val[i][j]);

    cout << ans << '\n';
}