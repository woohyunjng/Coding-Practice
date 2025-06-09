#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 4001;

int dis[MAX][MAX], state[MAX][MAX];
pr go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, X, Y, A, B;
    pr K;
    string S;

    queue<pr> q;

    cin >> H >> W;

    for (int i = 1; i <= H; i++) {
        cin >> S;
        for (int j = 1; j <= W; j++) {
            if (S[j - 1] == '#')
                state[i][j] = -1;
            else if (S[j - 1] == '.')
                state[i][j] = 1;
            else if (S[j - 1] == 'S')
                q.push({i, j}), dis[i][j] = 1;
            else
                state[i][j] = 1, X = i, Y = j;
        }
    }

    while (!q.empty()) {
        K = q.front(), q.pop();
        for (pr i : go) {
            A = K[0] + i[0], B = K[1] + i[1];
            if (A <= 0 || A > H || B <= 0 || B > W || state[A][B] == -1 || dis[A][B] != 0)
                continue;
            dis[A][B] = dis[K[0]][K[1]] + 1, q.push({A, B});
        }
    }

    cout << dis[X][Y] - 1 << '\n';
}