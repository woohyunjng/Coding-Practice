#include <bits/stdc++.h>
#define int long long
#define MAX 3000

using namespace std;
typedef pair<int, int> pr;

vector<int> arr[MAX];
int cap[MAX][MAX], flow[MAX][MAX], level[MAX], work[MAX], board[MAX][MAX];
pr go[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int convert(int A, int B, int K) { return (A - 1) * K + B; }

void add_path(int A, int B, int cap_size)
{
    arr[A].push_back(B);
    arr[B].push_back(A);

    cap[A][B] = cap_size;
    cap[B][A] = 0;

    flow[A][B] = 0;
    flow[B][A] = 0;
}

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

int maximum_flow(int start, int end)
{
    int K, res = 0, val;
    queue<int> q;

    while (true)
    {
        fill(level, level + end + 1, -1);
        fill(work, work + end + 1, 0);

        level[start] = 0;
        q.push(start);

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
        if (level[end] == -1)
            return res;

        while (true)
        {
            val = dinic_dfs(start, LLONG_MAX, end);
            if (!val)
                break;
            res += val;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, M, K, res, sm, x, y;
    cin >> T;

    while (T--)
    {
        cin >> N >> M;
        K = N * M + 1;
        for (int i = 0; i <= K; i++)
            arr[i].clear();

        sm = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                cin >> board[i][j];
                sm += board[i][j];

                if ((i + j) & 1)
                    add_path(convert(i, j, M), K, board[i][j]);
                else
                {
                    add_path(0, convert(i, j, M), board[i][j]);
                    for (pr k : go)
                    {
                        x = i + k.first, y = j + k.second;
                        if (x <= 0 || x > N || y <= 0 || y > M)
                            continue;
                        add_path(convert(i, j, M), convert(x, y, M), board[i][j]);
                    }
                }
            }
        }

        res = maximum_flow(0, K);
        cout << sm - res << '\n';
    }

    return 0;
}