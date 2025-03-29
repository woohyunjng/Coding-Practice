#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 5001;
const int MAX_PORTAL = 1001;

vector<int> adj[MAX];
int dis[MAX_PORTAL][MAX];
bool portal[MAX_PORTAL][MAX], chk[MAX_PORTAL][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, O, S, E, M, P, Q, A, B, X, Y;

    cin >> N >> O >> S >> E;

    cin >> M;
    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    cin >> P;
    while (P--)
        cin >> X >> Y, portal[X][Y] = true;

    queue<pr> q;
    pr K;

    q.push({1, S}), chk[1][S] = true;

    while (!q.empty()) {
        K = q.front(), q.pop();
        X = K[0], Y = K[1];

        for (int i : adj[Y]) {
            if (chk[X][i])
                continue;
            chk[X][i] = true, dis[X][i] = dis[X][Y] + 1;
            q.push({X, i});
        }

        if (portal[X][Y] && !chk[X + 1][Y]) {
            chk[X + 1][Y] = true, dis[X + 1][Y] = dis[X][Y] + 1;
            q.push({X + 1, Y});
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> X >> Y;
        if (!chk[O][E])
            cout << -1 << '\n';
        else
            cout << X * (dis[O][E] - O + 1) + Y * (O - 1) << '\n';
    }

    return 0;
}