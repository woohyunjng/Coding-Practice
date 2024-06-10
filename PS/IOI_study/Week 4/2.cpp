#include <bits/stdc++.h>
#define int long long
#define MAX 1010

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX];
int dis[MAX + 1][110], T[2 * MAX + 1][110];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, U, V, t, K, res = LLONG_MAX;
    cin >> N >> M >> A >> B;

    for (int i = 1; i <= M; i++)
    {
        cin >> U >> V >> t;
        arr[U].push_back({i, V});
        arr[V].push_back({i, U});
        T[i][0] = t;
    }

    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= M; j++)
            cin >> T[j][i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
            dis[i][j] = LLONG_MAX;
    }

    priority_queue<tp, vector<tp>, greater<tp>> pq;

    for (int i = 0; i <= K; i++)
    {
        pq.push({0, A, i});
        dis[A][i] = 0;
    }

    while (pq.size())
    {
        tp p = pq.top();
        pq.pop();

        if (dis[p[1]][p[2]] != p[0])
            continue;

        for (int k = p[2]; k <= K; k++)
        {
            for (pr i : arr[p[1]])
            {
                if (T[i.first][k] + p[0] < dis[i.second][k])
                {
                    dis[i.second][k] = T[i.first][k] + p[0];
                    pq.push({dis[i.second][k], i.second, k});
                }
            }
        }
    }

    for (int i = 0; i <= K; i++)
        res = min(res, dis[B][i]);
    cout << res;

    return 0;
}