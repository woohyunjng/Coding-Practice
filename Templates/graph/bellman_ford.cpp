vector<pr> adj[MAX];
int dis[MAX];

void init() {
    bool cycle = false, flag;

    fill(dis, dis + N + 1, INF), dis[S] = 0;

    for (int i = 0; i < N; i++) {
        flag = false;
        for (int j = 1; j <= N; j++) {
            if (dis[j] == INF)
                continue;
            for (pr k : adj[j]) {
                if (dis[j] + k[1] < dis[k[0]])
                    dis[k[0]] = dis[j] + k[1], flag = true;
            }
        }

        if (i == N - 1 && flag)
            cycle = true;
    }
}

// 벨만 포드로 부등식 푸는 방법
// a[x] - a[y] <= C 는 y -> x로 가는 가중치 C의 간선을 만들어준다