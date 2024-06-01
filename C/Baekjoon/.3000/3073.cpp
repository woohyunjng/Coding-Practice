#include <bits/stdc++.h>
#define int long long
#define MAX 300

using namespace std;
typedef pair<int, int> pr;

vector<int> arr[MAX];
int cap[MAX][MAX], flow[MAX][MAX], cost[MAX][MAX], dp[MAX], parent[MAX];
bool checked[MAX];

int dis(pr A, pr B) { return abs(A.first - B.first) + abs(A.second - B.second); }

void add_path(int A, int B, int cst, int cap_size)
{
    arr[A].push_back(B);
    arr[B].push_back(A);

    cost[A][B] = cst;
    cost[B][A] = -cst;

    cap[A][B] = cap_size;
    flow[A][B] = 0;
    flow[B][A] = 0;
}

pr minimum_cost_maximum_flow(int start, int end)
{
    queue<int> q;
    int val, money = 0, res = 0, A;

    while (true)
    {
        fill(checked, checked + end + 1, false);
        fill(dp, dp + end + 1, LLONG_MAX);
        fill(parent, parent + end + 1, -1);

        dp[start] = 0;
        checked[start] = true;
        q.push(start);

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

        if (parent[end] == -1)
            break;

        val = LLONG_MAX;
        for (int i = end; i != start; i = parent[i])
            val = min(val, cap[parent[i]][i] - flow[parent[i]][i]);

        for (int i = end; i != start; i = parent[i])
        {
            money += val * cost[parent[i]][i];
            flow[parent[i]][i] += val;
            flow[i][parent[i]] -= val;
        }
        res += val;
    }
    return {res, money};
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K = 0;
    char A;
    vector<pr> house, child;

    while (true)
    {
        cin >> N >> M;
        if (!N || !M)
            break;

        house.clear();
        child.clear();

        for (int i = 1; i <= 100; i++)
            arr[i].clear();

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                cin >> A;
                if (A == 'H')
                    house.push_back({i, j});
                else if (A == 'm')
                    child.push_back({i, j});
            }
        }

        K = house.size();
        for (int i = 1; i <= K; i++)
        {
            add_path(0, i, 0, 1);
            add_path(K + i, 2 * K + 1, 0, 1);
        }
        for (int i = 1; i <= K; i++)
        {
            for (int j = 1; j <= K; j++)
                add_path(i, K + j, dis(house[i - 1], child[j - 1]), 1);
        }

        pr res = minimum_cost_maximum_flow(0, 2 * K + 1);
        cout << res.second << '\n';
    }
    return 0;
}