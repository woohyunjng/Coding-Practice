#include <bits/stdc++.h>
#define int long long

#define INF 0x7f7f7f7f7f7f7f7f
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
                         level(n + 1, -1), work(n + 1, 0) {}

    void add_path(int A, int B, int cap_size) {
        arr[A].push_back(B);
        arr[B].push_back(A);

        cap[A][B] = cap_size;
        cap[B][A] = cap_size;

        flow[A][B] = 0;
        flow[B][A] = 0;
    }

    int run(int source, int sink) {
        int K, res = 0, val;
        queue<int> q;

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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, T, A, B, C;
    cin >> N >> M;

    MaximumFlow flow(N);

    while (M--) {
        cin >> A >> B >> C;
        flow.add_path(A, B, C);
    }

    cin >> S >> T;
    cout << flow.run(S, T);

    return 0;
}