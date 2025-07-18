#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 300001;

int depth[MAX], parent[MAX], S;
vector<pr> diff[MAX];
vector<int> adj[MAX];

void dfs(int node, int par) {
    depth[node] = depth[par] + 1, parent[node] = par;
    S++;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (!depth[i])
            dfs(i, node);
        else if (depth[i] < depth[node])
            diff[depth[node] - depth[i]].push_back({node, i});
    }
}

void print_cycle(int X, int Y) {
    Y = parent[Y];
    while (X != Y)
        cout << X << ' ', X = parent[X];
    cout << '\n';
    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, R, K;

    cin >> N;
    for (int i = 1; i <= 2 * N - 3; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs(1, 0);
    if (S == N) {
        for (int i = 2; i < N; i++) {
            if (diff[i].size() >= 2) {
                cout << i + 1 << '\n';
                print_cycle(diff[i][0][0], diff[i][0][1]);
                print_cycle(diff[i][1][0], diff[i][1][1]);
                return 0;
            }
        }

        cout << N - 1 << '\n';
        print_cycle(diff[N - 2][0][0], diff[N - 2][0][1]);

        K = diff[N - 1][0][0];
        X = diff[2][0][0], Y = diff[2][0][1];
        while (K != 0) {
            cout << K << ' ';
            if (K == X)
                K = Y;
            else
                K = parent[K];
        }
        cout << '\n';
    } else {
        for (int i = 1; i <= N; i++) {
            if (depth[i])
                continue;
            dfs(i, 0);
        }

        for (int i = 2; i < N; i++) {
            if (diff[i].size() >= 2) {
                cout << i + 1 << '\n';
                print_cycle(diff[i][0][0], diff[i][0][1]);
                print_cycle(diff[i][1][0], diff[i][1][1]);
                return 0;
            }
        }
    }

    return 0;
}