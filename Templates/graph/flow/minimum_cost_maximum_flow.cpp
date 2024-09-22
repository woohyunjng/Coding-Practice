class MinimumCostMaximumFlow {
  private:
    vector<int> dp, parent;
    vector<bool> checked;

  public:
    vector<vector<int>> arr, cap, flow, cost;
    int N;

    MinimumCostMaximumFlow(int N) : N(N),
                                    arr(N + 1), cap(N + 1, vector<int>(N + 1, 0)), flow(N + 1, vector<int>(N + 1, 0)),
                                    cost(N + 1, vector<int>(N + 1, 0)), dp(N + 1), parent(N + 1), checked(N + 1) {}

    void add_path(int A, int B, int cst, int cap_size) {
        arr[A].push_back(B);
        arr[B].push_back(A);

        cost[A][B] = cst;
        cost[B][A] = -cst;

        cap[A][B] = cap_size;
        cap[B][A] = 0;

        flow[A][B] = 0;
        flow[B][A] = 0;
    }

    pr run_cost_flow(int source, int sink) {
        queue<int> q;
        int val, money = 0, res = 0, A;

        while (true) {
            fill(dp.begin(), dp.end(), INF);
            fill(parent.begin(), parent.end(), -1);
            fill(checked.begin(), checked.end(), false);

            dp[source] = 0;
            checked[source] = true;
            q.push(source);

            while (!q.empty()) {
                A = q.front();
                checked[A] = false;
                q.pop();

                for (int i : arr[A]) {
                    if (cap[A][i] - flow[A][i] <= 0 || dp[A] + cost[A][i] >= dp[i])
                        continue;
                    dp[i] = dp[A] + cost[A][i];
                    parent[i] = A;
                    if (!checked[i]) {
                        checked[i] = true;
                        q.push(i);
                    }
                }
            }

            if (parent[sink] == -1)
                break;

            val = LLONG_MAX;
            for (int i = sink; i != source; i = parent[i])
                val = min(val, cap[parent[i]][i] - flow[parent[i]][i]);

            for (int i = sink; i != source; i = parent[i]) {
                money += val * cost[parent[i]][i];
                flow[parent[i]][i] += val;
                flow[i][parent[i]] -= val;
            }
            res += val;
        }
        return {res, money};
    }
};