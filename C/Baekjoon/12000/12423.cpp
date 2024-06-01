#include <bits/stdc++.h>
#define int long long
#define MAX 100

using namespace std;
typedef pair<int, int> pr;

vector<int> arr[MAX];
int cap[MAX][MAX], flow[MAX][MAX], cost[MAX][MAX], dp[MAX], parent[MAX], P[10][10], A[10];
bool checked[MAX];

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

    int T, N, start = 0, end = 7;
    pr res;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> N;
        for (int i = 1; i <= 6; i++)
            cin >> A[i];
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 4; j <= 6; j++)
                cin >> P[i][j];
        }

        for (int i = start; i <= end; i++)
            arr[i].clear();

        for (int i = 1; i <= 3; i++)
            add_path(start, i, 0, A[i]);
        for (int i = 4; i <= 6; i++)
            add_path(i, end, 0, A[i]);
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 4; j <= 6; j++)
                add_path(i, j, -P[i][j], min(A[i], A[j]));
        }

        res = minimum_cost_maximum_flow(start, end);
        cout << "Case #" << t << ": " << -res.second << '\n';
    }
}