class MaximumFlow {
  private:
    int level[MAX], work[MAX];

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
    vector<int> arr[MAX];
    int source, sink, cap[MAX][MAX], flow[MAX][MAX];

    MaximumFlow(int _source, int _sink) : source(_source), sink(_sink) {}

    void add_path(int A, int B, int cap_size) {
        arr[A].push_back(B);
        arr[B].push_back(A);

        cap[A][B] = cap_size;
        cap[B][A] = 0;

        flow[A][B] = 0;
        flow[B][A] = 0;
    }

    int run() {
        int K, res = 0, val;
        queue<int> q;

        while (true) {
            fill(level, level + sink + 1, -1);
            fill(work, work + sink + 1, 0);

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
                val = dinic_dfs(source, LLONG_MAX, sink);
                if (!val)
                    break;
                res += val;
            }
        }
    }
};