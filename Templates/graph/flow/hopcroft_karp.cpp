// O(Esqrt(V)) Hopcroft-Karp

vector<int> adj[MAX];
int dis[MAX], assignA[MAX], assignB[MAX];

bool dfs(int node) {
    for (int i : adj[node]) {
        if (!assignB[i] || (dis[assignB[i]] == dis[node] + 1 && dfs(assignB[i]))) {
            assignA[node] = i, assignB[i] = node;
            return true;
        }
    }
    dis[node] = -1;
    return false;
}

void init() {
    int X, res = 0;
    queue<int> q;

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
        res += X;
    }
}