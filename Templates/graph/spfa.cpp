int N;
vector<pr> arr[MAX];
int dis[MAX], cnt[MAX];
bool checked[MAX];

void get_dis(int K) {
    int A;
    bool cycle;

    fill(dis, dis + N + 1, INF);
    dis[K] = 0;

    queue<int> q;
    q.push(K), checked[K] = true;

    while (!q.empty()) {
        A = q.front(), q.pop();
        checked[A] = false;

        if (++cnt[A] == N || dis[A] < -INF) {
            cycle = true;
            break;
        }

        for (pr i : arr[A]) {
            if (dis[A] + i.second < dis[i.first]) {
                dis[i.first] = dis[A] + i.second;
                if (!checked[i.first])
                    checked[i.first] = true, q.push(i.first);
            }
        }
    }
}

// 벨만 포드로 부등식 푸는 방법
// a[x] - a[y] <= C 는 y -> x로 가는 가중치 C의 간선을 만들어준다