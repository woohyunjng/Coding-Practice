#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#define MAX 1000000000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V, E, K, u, v, w;
    cin >> V >> E;

    cin >> K;

    vector<pair<int, int>> arr[V + 1];
    int dis[V + 1];
    for (int i = 1; i <= V; i++)
        dis[i] = MAX;

    while (E--)
    {
        cin >> u >> v >> w;
        arr[u].push_back({w, v});
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, K});
    dis[K] = 0;

    while (pq.size())
    {
        pair<int, int> p = pq.top();
        pq.pop();

        if (dis[p.second] != p.first)
            continue;

        for (pair<int, int> i : arr[p.second])
        {
            if (i.first + p.first < dis[i.second])
            {
                dis[i.second] = i.first + p.first;
                pq.push({dis[i.second], i.second});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dis[i] < MAX)
            cout << dis[i] << '\n';
        else
            cout << "INF\n";
    }
}