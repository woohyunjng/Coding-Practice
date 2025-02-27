int N;
vector<pr> arr[MAX];
int dis[MAX];

void get_dis(int K) {
    int A;
    bool cycle, change;

    fill(dis, dis + N + 1, INF), dis[K] = 0;

    for (int i = 0; i < N; i++) {
        change = false;
        for (int j = 1; j <= N; j++) {
            if (dis[j] == INF)
                continue;
            for (pr k : arr[j]) {
                if (dis[j] + k.second < dis[k.first])
                    dis[k.first] = dis[j] + k.second, change = true;
            }
        }

        if (i == N - 1 && change)
            cycle = true;
    }
}

// 벨만 포드로 부등식 푸는 방법
// a[x] - a[y] <= C 는 y -> x로 가는 가중치 C의 간선을 만들어준다