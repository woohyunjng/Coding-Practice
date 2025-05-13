#include <bits/stdc++.h>

using namespace std;
typedef array<int, 2> pr;

const int MAX = 100;

vector<int> adj[MAX];
int dp[MAX], in[MAX], vst[MAX];
pr go[2][3] = {{{-1, 1}, {1, 0}, {0, 1}}, {{0, 1}, {1, 1}, {1, 0}}};

void dfs(int node) {
    vst[node] = 1;
    for (int i : adj[node])
        if (!vst[i])
            dfs(i);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, S[2], G[2], X, Y, ST, GT;

    cin >> W >> H;
    cin >> S[0] >> S[1] >> G[0] >> G[1], S[0]--, S[1]--, G[0]--, G[1]--;
    ST = S[0] * 10 + S[1], GT = G[0] * 10 + G[1];

    for (int i = 0; i < W; i++)
        for (int j = 0; j < H; j++) {
            for (pr k : go[j & 1]) {
                X = i + k[0], Y = j + k[1];
                if (X < 0 || X >= W - (Y & 1) || Y < 0 || Y >= H)
                    continue;
                adj[i * 10 + j].push_back(X * 10 + Y), in[X * 10 + Y]++;
            }
        }

    dfs(ST);

    for (int i = 0; i < 100; i++) {
        if (vst[i])
            continue;
        for (int j : adj[i])
            in[j]--;
    }

    queue<int> q;
    q.push(ST), dp[ST] = 1;

    while (!q.empty()) {
        X = q.front(), q.pop();

        for (int i : adj[X]) {
            dp[i] += dp[X];
            if (--in[i] == 0)
                q.push(i);
        }
    }

    cout << dp[GT] << '\n';

    return 0;
}