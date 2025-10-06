#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

vector<int> adj[MAX];
int dis[MAX], assignA[MAX], assignB[MAX];

bool dfs(int node) {
    for (int i : adj[node]) {
        if (!assignB[i] || (dis[assignB[i]] == dis[node] + 1 && dfs(assignB[i]))) {
            assignA[node] = i, assignB[i] = node;
            return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, ans = 0;
    queue<int> q;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> K;
        while (K--)
            cin >> X, adj[i].push_back(X);
    }

    while (true) {
        for (int i = 1; i <= N; i++) {
            if (!assignA[i])
                dis[i] = 0, q.push(i);
            else
                dis[i] = -1;
        }

        while (!q.empty()) {
            X = q.front(), q.pop();
            for (int i : adj[X])
                if (assignB[i] && dis[assignB[i]] == -1)
                    dis[assignB[i]] = dis[X] + 1, q.push(assignB[i]);
        }

        X = 0;
        for (int i = 1; i <= N; i++)
            if (!assignA[i] && dfs(i))
                X++;
        if (!X)
            break;
        ans += X;
    }

    cout << ans << '\n';

    return 0;
}