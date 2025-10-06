#include <bits/stdc++.h>
using namespace std;

const int MAX = 20001;

vector<int> adj[MAX];
int dis[MAX], assignA[MAX], assignB[MAX];

bool dfs(int node) {
    for (int i : adj[node]) {
        if (assignB[i] == -1 || (dis[assignB[i]] == dis[node] + 1 && dfs(assignB[i]))) {
            assignA[node] = i, assignB[i] = node;
            return true;
        }
    }
    dis[node] = -1;
    return false;
}

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    int N, K, X, ans;
    string S;

    queue<int> q;

    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            cin >> S, cin >> S, K = 0;
            for (int j = 1; j + 1 < S.size(); j++)
                K = K * 10 + (S[j] - '0');
            while (K--)
                cin >> X, adj[i].push_back(X);
        }

        fill(assignA, assignA + (N << 1) + 1, -1), fill(assignB, assignB + (N << 1) + 1, -1);

        ans = 0;
        while (true) {
            for (int i = 0; i < N; i++) {
                if (assignA[i] == -1)
                    dis[i] = 0, q.push(i);
                else
                    dis[i] = -1;
            }

            while (!q.empty()) {
                X = q.front(), q.pop();
                for (int i : adj[X])
                    if (assignB[i] != -1 && dis[assignB[i]] == -1)
                        dis[assignB[i]] = dis[X] + 1, q.push(assignB[i]);
            }

            X = 0;
            for (int i = 0; i < N; i++)
                if (assignA[i] == -1 && dfs(i))
                    X++;
            if (!X)
                break;
            ans += X;
        }

        cout << ans << '\n';

        for (int i = 0; i <= N << 1; i++)
            adj[i].clear(), dis[i] = assignA[i] = assignB[i] = 0;
    }

    return 0;
}