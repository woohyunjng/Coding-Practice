#include <bits/stdc++.h>
#define int long long

#define MAX 210
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class MaximumFlow {
  private:
    vector<int> level, work;

    int dinic_dfs(int K, int F, int end) {
        int x, val;
        if (K == end)
            return F;

        for (int &i = work[K]; i < arr[K].size(); i++) {
            x = arr[K][i];
            if (level[x] != level[K] + 1 || cap[K][x] - flow[K][x] <= 0)
                continue;
            val = dinic_dfs(x, min(cap[K][x] - flow[K][x], F), end);
            if (val > 0) {
                flow[K][x] += val;
                flow[x][K] -= val;
                return val;
            }
        }
        return 0;
    }

  public:
    vector<vector<int>> arr, cap, flow;
    int N, source, sink;

    MaximumFlow(int n) : N(n),
                         arr(n + 1), cap(n + 1, vector<int>(n + 1, 0)), flow(n + 1, vector<int>(n + 1, 0)),
                         level(n + 1), work(n + 1) {}

    void add_path(int A, int B, int cap_size, bool is_directed = true) {
        arr[A].push_back(B);
        arr[B].push_back(A);

        if (is_directed) {
            cap[A][B] = cap_size;
            cap[B][A] = 0;
        } else {
            cap[A][B] = cap_size;
            cap[B][A] = cap_size;
        }
    }

    int run(int source, int sink) {
        int K, res = 0, val;
        queue<int> q;

        fill(flow.begin(), flow.end(), vector<int>(N + 1, 0));

        while (true) {
            fill(level.begin(), level.end(), -1);
            fill(work.begin(), work.end(), 0);

            level[source] = 0;
            q.push(source);

            while (!q.empty()) {
                K = q.front();
                q.pop();

                for (int i : arr[K]) {
                    if (level[i] != -1 || cap[K][i] - flow[K][i] <= 0)
                        continue;
                    level[i] = level[K] + 1;
                    q.push(i);
                }
            }
            if (level[sink] == -1)
                return res;

            while (true) {
                val = dinic_dfs(source, INF, sink);
                if (!val)
                    break;
                res += val;
            }
        }
    }
};

int dis[MAX][MAX], cap[MAX], cur[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int F, P, val = 0, A, B, C, st, en, mid, res;
    vector<tp> edge;

    cin >> F >> P;

    for (int i = 1; i <= F; i++)
        cin >> cur[i] >> cap[i];

    fill(&dis[0][0], &dis[F + 1][0], INF);
    for (int i = 1; i <= F; i++)
        dis[i][i] = 0;

    while (P--) {
        cin >> A >> B >> C;
        dis[A][B] = min(dis[A][B], C);
        dis[B][A] = min(dis[B][A], C);
    }

    for (int i = 1; i <= F; i++)
        for (int j = 1; j <= F; j++)
            for (int k = 1; k <= F; k++)
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);

    st = 0, en = 1000000000000000000, res = -1;

    while (st <= en) {
        MaximumFlow flow(F * 2 + 1);

        mid = st + en >> 1;
        for (int i = 1; i <= F; i++) {
            for (int j = 1; j <= F; j++)
                if (dis[i][j] <= mid)
                    flow.add_path(i, j + F, INF);
        }

        val = 0;
        for (int i = 1; i <= F; i++) {
            flow.add_path(0, i, cur[i]);
            flow.add_path(i + F, F * 2 + 1, cap[i]);
            val += cur[i];
        }

        A = flow.run(0, F * 2 + 1);

        if (A == val) {
            res = mid;
            en = mid - 1;
        } else
            st = mid + 1;
    }

    cout << res;

    return 0;
}