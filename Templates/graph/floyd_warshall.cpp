int dis[MAX][MAX];

void init() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dis[i][j] = i == j ? 0 : INF;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
}