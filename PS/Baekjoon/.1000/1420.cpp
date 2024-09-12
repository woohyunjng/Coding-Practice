#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000007
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
            if (level[x] != level[K] + 1 || cap[{K, x}] - flow[{K, x}] <= 0)
                continue;
            val = dinic_dfs(x, min(cap[{K, x}] - flow[{K, x}], F), end);
            if (val > 0) {
                flow[{K, x}] += val;
                flow[{x, K}] -= val;
                return val;
            }
        }
        return 0;
    }

  public:
    vector<vector<int>> arr;
    map<pr, int> cap, flow;
    int N, source, sink;

    MaximumFlow(int n) : N(n),
                         arr(n + 1),
                         level(n + 1), work(n + 1) {}

    void add_path(int A, int B, int cap_size, bool is_directed = true) {
        arr[A].push_back(B);
        arr[B].push_back(A);

        if (is_directed) {
            cap[{A, B}] = cap_size;
            cap[{B, A}] = 0;
        } else {
            cap[{A, B}] = cap_size;
            cap[{B, A}] = cap_size;
        }

        flow[{A, B}] = 0;
        flow[{B, A}] = 0;
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
                    if (level[i] != -1 || cap[{K, i}] - flow[{K, i}] <= 0)
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

vector<vector<int>> arr;
vector<vector<bool>> checked;
pr d[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    pr st, en, K, nxt;

    string S;
    cin >> N >> M;

    arr.resize(N + 1, vector<int>(M + 1, 0));
    checked.resize(N + 1, vector<bool>(M + 1, false));

    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= M; j++) {
            if (S[j - 1] == 'K')
                st = {i, j};
            else if (S[j - 1] == 'H')
                en = {i, j};
            else if (S[j - 1] == '#')
                arr[i][j] = -1;
        }
    }

    for (int i = 0; i < 4; i++) {
        nxt = {st.first + d[i].first, st.second + d[i].second};
        if (nxt == en) {
            cout << -1;
            return 0;
        }
    }

    MaximumFlow flow(N * M * 2);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == -1)
                continue;

            X = (i - 1) * M + j;
            flow.add_path(X * 2 - 1, X * 2, 1);

            if (j + 1 <= M && arr[i][j + 1] != -1) {
                Y = (i - 1) * M + j + 1;
                flow.add_path(X * 2, Y * 2 - 1, 1);
                flow.add_path(Y * 2, X * 2 - 1, 1);
            }
            if (i + 1 <= N && arr[i + 1][j] != -1) {
                Y = i * M + j;
                flow.add_path(X * 2, Y * 2 - 1, 1);
                flow.add_path(Y * 2, X * 2 - 1, 1);
            }
        }
    }

    X = (st.first - 1) * M + st.second, Y = (en.first - 1) * M + en.second;
    cout << flow.run(X * 2, Y * 2 - 1);

    return 0;
}