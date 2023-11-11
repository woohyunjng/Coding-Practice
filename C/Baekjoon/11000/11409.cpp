#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 801

using namespace std;
typedef tuple<int, int, int> tp;

int mx[MAX + 1][MAX + 1], flow[MAX + 1][MAX + 1];
vector<tp> arr[MAX + 1];

void add_line(int A, int B, int money)
{
    arr[A].push_back({A, B, money});
    arr[B].push_back({B, A, -money});
    mx[A][B] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C, max_point;
    cin >> N >> M;

    int res = 0, val = 0, money = 0;
    pair<int, int> parent[N + M + 2];
    bool checked[N + M + 2][N + M + 2];
    memset(mx, 0, sizeof(mx));
    memset(flow, 0, sizeof(flow));

    for (int i = 1; i <= N; i++)
    {
        add_line(0, i, 0);
        cin >> A;
        for (int j = 0; j < A; j++)
        {
            cin >> B >> C;
            add_line(i, N + B, -C);
        }
    }

    for (int i = 1; i <= M; i++)
        add_line(N + i, N + M + 1, 0);

    while (true)
    {
        memset(checked, false, sizeof(checked));

        val = 2;
        for (int i = 0; i < N + M + 2; i++)
            parent[i] = {-1, 0};

        queue<tp> q;
        long long dp[N + M + 2];
        for (int i = 0; i <= N + M + 1; i++)
            dp[i] = 9223372036854775807;
        dp[0] = 0;

        for (tp i : arr[0])
        {
            q.push(i);
            checked[get<0>(i)][get<1>(i)] = true;
        }

        for (int i = 0; i <= N + M + 1; i++)
        {
            A = q.size();
            while (A--)
            {
                tp X = q.front();
                q.pop();
                checked[get<0>(X)][get<1>(X)] = false;

                if (get<2>(X) + dp[get<0>(X)] >= dp[get<1>(X)] || flow[get<0>(X)][get<1>(X)] >= mx[get<0>(X)][get<1>(X)])
                    continue;

                dp[get<1>(X)] = get<2>(X) + dp[get<0>(X)];
                parent[get<1>(X)] = {get<0>(X), get<2>(X)};
                for (tp i : arr[get<1>(X)])
                {
                    if (!checked[get<0>(i)][get<1>(i)])
                    {
                        q.push(i);
                        checked[get<0>(i)][get<1>(i)] = true;
                    }
                }
            }
        }

        if (parent[N + M + 1].first == -1)
            break;

        A = N + M + 1;
        while (parent[A].first != -1)
        {
            val = min(val, mx[parent[A].first][A] - flow[parent[A].first][A]);
            flow[parent[A].first][A] = mx[parent[A].first][A];
            flow[A][parent[A].first] = -mx[parent[A].first][A];
            A = parent[A].first;
            money += parent[A].second;
        }
        res += val;

        while (!q.empty())
            q.pop();
    }

    cout << res << '\n'
         << -money;
}