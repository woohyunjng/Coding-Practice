#include <bits/stdc++.h>
#define int long long

#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;

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
                flow[K][x] += val, flow[x][K] -= val;
                return val;
            }
        }
        return 0;
    }

  public:
    vector<vector<int>> arr, cap, flow;
    int N;

    MaximumFlow(int n) : N(n),
                         arr(n + 1), cap(n + 1, vector<int>(n + 1, 0)), flow(n + 1, vector<int>(n + 1, 0)),
                         level(n + 1), work(n + 1) {}

    void add_path(int A, int B, int cap_size, bool is_directed = true) {
        if (cap[A][B] == 0 && cap[B][A] == 0)
            arr[A].push_back(B), arr[B].push_back(A);
        if (is_directed)
            cap[A][B] += cap_size;
        else
            cap[A][B] += cap_size, cap[B][A] += cap_size;
        flow[A][B] = flow[B][A] = 0;
    }

    int run(int source, int sink) {
        int K, res = 0, val;
        queue<int> q;

        while (true) {
            fill(level.begin(), level.end(), -1), fill(work.begin(), work.end(), 0);
            q.push(source), level[source] = 0;

            while (!q.empty()) {
                K = q.front(), q.pop();

                for (int i : arr[K]) {
                    if (level[i] != -1 || cap[K][i] - flow[K][i] <= 0)
                        continue;
                    q.push(i), level[i] = level[K] + 1;
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

int char_to_int(char C) {
    if ('A' <= C && C <= 'Z')
        return C - 'A' + 1;
    return C - 'a' + 27;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, F;
    char A, B;

    cin >> N;

    MaximumFlow flow(60);

    while (N--) {
        cin >> A >> B >> F;
        flow.add_path(char_to_int(A), char_to_int(B), F, false);
    }

    cout << flow.run(char_to_int('A'), char_to_int('Z')) << '\n';

    return 0;
}