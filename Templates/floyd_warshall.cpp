#include <bits/stdc++.h>
#define int long long
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