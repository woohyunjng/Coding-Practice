#include <bits/stdc++.h>
#define int long long
#define MAX 2540

using namespace std;
typedef pair<int, int> pr;

int board[MAX][MAX],
    value[5][5] = {{10, 8, 7, 5, 1}, {8, 6, 4, 3, 1}, {7, 4, 3, 2, 1}, {5, 3, 2, 2, 1}, {1, 1, 1, 1, 0}};
pr go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int convert(int A, int B, int K) { return (A - 1) * K + B; }

class MinimumCostMaximumFlow
{
private:
    int dp[MAX], parent[MAX];
    bool checked[MAX];

public:
    vector<int> arr[MAX];
    int source, sink, cap[MAX][MAX], flow[MAX][MAX], cost[MAX][MAX];

    MinimumCostMaximumFlow(int _source, int _sink) : source(_source), sink(_sink) {}

    void add_path(int A, int B, int cst, int cap_size)
    {
        arr[A].push_back(B);
        arr[B].push_back(A);

        cost[A][B] = cst;
        cost[B][A] = -cst;

        cap[A][B] = cap_size;
        cap[B][A] = 0;

        flow[A][B] = 0;
        flow[B][A] = 0;
    }

    // 최대 유량과 최소 비용 만
    pr run_cost_flow()
    {
        queue<int> q;
        int val, money = 0, res = 0, A;

        while (true)
        {
            fill(checked, checked + sink + 1, false);
            fill(dp, dp + sink + 1, LLONG_MAX);
            fill(parent, parent + sink + 1, -1);

            dp[source] = 0;
            checked[source] = true;
            q.push(source);

            while (!q.empty())
            {
                A = q.front();
                checked[A] = false;
                q.pop();

                for (int i : arr[A])
                {
                    if (cap[A][i] - flow[A][i] <= 0 || dp[A] + cost[A][i] >= dp[i])
                        continue;
                    dp[i] = dp[A] + cost[A][i];
                    parent[i] = A;
                    if (!checked[i])
                    {
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

            for (int i = sink; i != source; i = parent[i])
            {
                money += val * cost[parent[i]][i];
                flow[parent[i]][i] += val;
                flow[i][parent[i]] -= val;
            }
            res += val;
        }
        return {res, money};
    }

    // 최소 비용만
    int run_cost()
    {
        queue<int> q;
        int val, res = LLONG_MAX, money = 0, A;

        while (true)
        {
            fill(checked, checked + sink + 1, false);
            fill(dp, dp + sink + 1, LLONG_MAX);
            fill(parent, parent + sink + 1, -1);

            dp[source] = 0;
            checked[source] = true;
            q.push(source);

            while (!q.empty())
            {
                A = q.front();
                checked[A] = false;
                q.pop();

                for (int i : arr[A])
                {
                    if (cap[A][i] - flow[A][i] <= 0 || dp[A] + cost[A][i] >= dp[i])
                        continue;
                    dp[i] = dp[A] + cost[A][i];
                    parent[i] = A;
                    if (!checked[i])
                    {
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

            for (int i = sink; i != source; i = parent[i])
            {
                money += val * cost[parent[i]][i];
                flow[parent[i]][i] += val;
                flow[i][parent[i]] -= val;
            }
            res = min(res, money);
        }

        return res < LLONG_MAX ? res : 0;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    char A;

    cin >> N >> M;
    K = N * M + 1;

    MinimumCostMaximumFlow flow(0, K);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> A;
            board[i][j] = A - 'A';
            if (board[i][j] == 5)
                board[i][j] = 4;
            if ((i + j) & 1)
                flow.add_path(convert(i, j, M), K, 0, 1);
            else
                flow.add_path(0, convert(i, j, M), 0, 1);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if ((i + j) & 1)
                continue;
            for (pr k : go)
            {
                int x = i + k.first, y = j + k.second;
                if (x <= 0 || x > N || y <= 0 || y > M)
                    continue;
                flow.add_path(convert(i, j, M), convert(x, y, M), -value[board[i][j]][board[x][y]], 1);
            }
        }
    }

    int res = flow.run_cost();
    cout << -res;

    return 0;
}