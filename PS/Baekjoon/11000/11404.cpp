#include <bits/stdc++.h>
#define int long long
#define MAX_COST 50000000000
#define MAX 510

using namespace std;

int V;
int dis[MAX][MAX];

void get_dis()
{
    for (int i = 1; i <= V; i++)
        dis[i][i] = 0;

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            for (int k = 1; k <= V; k++)
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, A, B, C;
    cin >> V >> M;

    fill(dis[0], dis[V + 2], MAX_COST);
    while (M--)
    {
        cin >> A >> B >> C;
        dis[A][B] = min(dis[A][B], C);
    }

    get_dis();

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cout << (dis[i][j] < MAX_COST ? dis[i][j] : 0) << ' ';
        }
        cout << '\n';
    }

    return 0;
}