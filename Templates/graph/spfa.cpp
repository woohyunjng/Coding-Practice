vector<pr> adj[MAX];
int dis[MAX], cnt[MAX];
bool chk[MAX];

void get_dis(int K) {
    int A;
    bool cycle;

    fill(dis, dis + N + 1, INF);

    queue<int> q;
    q.push(K), dis[K] = 0, chk[K] = true;

    while (!q.empty()) {
        A = q.front(), q.pop();
        chk[A] = false;

        if (++cnt[A] == N || dis[A] < -INF) {
            cycle = true;
            break;
        }

        for (pr i : adj[A]) {
            if (dis[A] + i[1] < dis[i[0]]) {
                dis[i[0]] = dis[A] + i[1];
                if (!chk[i[0]])
                    chk[i[0]] = true, q.push(i[0]);
            }
        }
    }
}

// 벨만 포드로 부등식 푸는 방법
// a[x] - a[y] <= C 는 y -> x로 가는 가중치 C의 간선을 만들어준다