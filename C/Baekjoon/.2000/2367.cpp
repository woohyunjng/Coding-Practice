#include <bits/stdc++.h>
#define int long long
#define MAX 400

using namespace std;

class MaximumFlow
{
public:
    vector<int> arr[MAX];
    int source, sink, cap[MAX][MAX], flow[MAX][MAX], level[MAX], work[MAX];

    MaximumFlow(int _source, int _sink) : source(_source), sink(_sink) {}

    void add_path(int A, int B, int cap_size)
    {
        arr[A].push_back(B);
        arr[B].push_back(A);

        cap[A][B] = cap_size;
        cap[B][A] = 0;

        flow[A][B] = 0;
        flow[B][A] = 0;
    }

    int run()
    {
        int K, res = 0, val;
        queue<int> q;

        while (true)
        {
            fill(level, level + sink + 1, -1);
            fill(work, work + sink + 1, 0);

            level[source] = 0;
            q.push(source);

            while (!q.empty())
            {
                K = q.front();
                q.pop();

                for (int i : arr[K])
                {
                    if (level[i] != -1 || cap[K][i] - flow[K][i] <= 0)
                        continue;
                    level[i] = level[K] + 1;
                    q.push(i);
                }
            }
            if (level[sink] == -1)
                return res;

            while (true)
            {
                val = dinic_dfs(source, LLONG_MAX, sink);
                if (!val)
                    break;
                res += val;
            }
        }
    }

private:
    int dinic_dfs(int K, int F, int end)
    {
        int x, val;
        if (K == end)
            return F;

        for (int &i = work[K]; i < arr[K].size(); i++)
        {
            x = arr[K][i];
            if (level[x] != level[K] + 1 || cap[K][x] - flow[K][x] <= 0)
                continue;
            val = dinic_dfs(x, min(cap[K][x] - flow[K][x], F), end);
            if (val > 0)
            {
                flow[K][x] += val;
                flow[x][K] -= val;
                return val;
            }
        }
        return 0;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, D, cap_size, Z, go;
    cin >> N >> K >> D;

    MaximumFlow flow(0, N + D + 1);

    for (int i = 1; i <= D; i++)
    {
        cin >> cap_size;
        flow.add_path(N + i, N + D + 1, cap_size);
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> Z;
        flow.add_path(0, i, K);
        while (Z--)
        {
            cin >> go;
            flow.add_path(i, N + go, 1);
        }
    }

    cout << flow.run();

    return 0;
}