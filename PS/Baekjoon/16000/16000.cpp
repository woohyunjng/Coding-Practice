#include <bits/stdc++.h>
#define MAX 2002

using namespace std;
typedef pair<int, int> pr;

int N, M, cnt = 0;
vector<int> parent, vst;
vector<bool> state, type;
vector<vector<int>> adj;
vector<vector<bool>> A;
pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<pr> q;

void bfs(int X, int Y, int num) {
    int P, Q;
    pr K;
    q.push({X, Y}), parent[(X - 1) * M + Y] = num;

    while (!q.empty()) {
        K = q.front(), q.pop();
        X = K.first, Y = K.second;

        for (pr i : go) {
            P = X + i.first, Q = Y + i.second;
            if (P < 1 || P > N || Q < 1 || Q > M)
                continue;
            if (A[P][Q] == A[X][Y] && parent[(P - 1) * M + Q] == 0)
                q.push({P, Q}), parent[(P - 1) * M + Q] = num;
            else if (A[P][Q] != A[X][Y] && parent[(P - 1) * M + Q]) {
                if (adj[num].empty() || adj[num].size() == 1 && adj[num][0] != parent[(P - 1) * M + Q])
                    adj[num].push_back(parent[(P - 1) * M + Q]), adj[parent[(P - 1) * M + Q]].push_back(num);
            }
        }
    }
}

void upd_dfs(int node, int par) {
    if (state[node])
        return;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        upd_dfs(i, node), state[i] = true;
    }
}

int dfs(int node, int par) {
    int res = ++cnt, X;
    bool flag = false;

    vst[node] = res;

    for (int i : adj[node]) {
        if (vst[i])
            res = min(res, vst[i]);
        else {
            X = dfs(i, node), res = min(res, X);
            if (X >= vst[node])
                flag = true;
        }
    }

    if (node != 1 && flag && type[node] == 1)
        upd_dfs(node, par);
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, Y, P, Q;
    string S;

    cin >> N >> M;

    A.assign(N + 1, vector<bool>(M + 1)), type.assign((N + 1) * (M + 1), false);
    parent.assign((N + 1) * (M + 1), 0), adj.resize((N + 1) * (M + 1));
    state.assign((N + 1) * (M + 1), false), vst.assign((N + 1) * (M + 1), 0);

    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= M; j++)
            A[i][j] = S[j - 1] == '#';
    }

    X = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            if (parent[(i - 1) * M + j])
                continue;
            bfs(i, j, ++X), type[X] = A[i][j];
        }

    dfs(1, -1);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            P = parent[(i - 1) * M + j];
            if (A[i][j] == 0)
                cout << '.';
            else if (state[P])
                cout << 'X';
            else
                cout << 'O';
        }
        cout << '\n';
    }

    return 0;
}