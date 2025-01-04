#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define INF 0x3f3f3f3f

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][MAX], dis[MAX][MAX][2], go[2] = {1, -1};
bool chk[MAX][MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W;
    pr S, G;
    tp K;
    string T;

    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        cin >> T;
        for (int j = 1; j <= W; j++) {
            if (T[j - 1] == 'S')
                S = {i, j};
            else if (T[j - 1] == 'G')
                G = {i, j};
            arr[i][j] = T[j - 1] != '#';
        }
    }

    queue<tp> q;
    fill(&dis[0][0][0], &dis[H + 1][0][0], INF);
    dis[S.first][S.second][0] = dis[S.first][S.second][1] = 0;
    q.push({S.first, S.second, 0}), chk[S.first][S.second][0] = true;
    q.push({S.first, S.second, 1}), chk[S.first][S.second][1] = true;

    while (!q.empty()) {
        K = q.front(), q.pop();
        if (K[2] == 0) {
            for (int i : go) {
                if (K[1] + i <= 0 || K[1] + i > W || arr[K[0]][K[1]] == 0 || chk[K[0]][K[1] + i][1])
                    continue;
                q.push({K[0], K[1] + i, 1}), chk[K[0]][K[1] + i][1] = true, dis[K[0]][K[1] + i][1] = dis[K[0]][K[1]][0] + 1;
            }
        } else {
            for (int i : go) {
                if (K[0] + i <= 0 || K[0] + i > H || arr[K[0]][K[1]] == 0 || chk[K[0] + i][K[1]][0])
                    continue;
                q.push({K[0] + i, K[1], 0}), chk[K[0] + i][K[1]][0] = true, dis[K[0] + i][K[1]][0] = dis[K[0]][K[1]][1] + 1;
            }
        }
    }

    if (chk[G.first][G.second][0] || chk[G.first][G.second][1])
        cout << min(dis[G.first][G.second][0], dis[G.first][G.second][1]) << '\n';
    else
        cout << -1 << '\n';

    return 0;
}