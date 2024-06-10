#include <bits/stdc++.h>
#define int long long
#define MAX 1000000

using namespace std;
typedef pair<int, int> pr;

class Dijkstra
{
public:
    int V;
    vector<pr> arr[MAX];

    Dijkstra(int v) : V(v) {}

    void add_path(int A, int B, int cst) { arr[A].push_back({cst, B}); }
    void add_two_path(int A, int B, int cst) { add_path(A, B, cst), add_path(B, A, cst); }

    int *get_dis(int K)
    {
        int dis[V + 1];
        fill(dis, dis + V + 1, LLONG_MAX);

        priority_queue<pr, vector<pr>, greater<pr>> pq;
        pq.push({0, K});
        dis[K] = 0;

        while (pq.size())
        {
            pr p = pq.top();
            pq.pop();

            if (dis[p.second] != p.first)
                continue;

            for (pr i : arr[p.second])
            {
                if (i.first + p.first < dis[i.second])
                {
                    dis[i.second] = i.first + p.first;
                    pq.push({dis[i.second], i.second});
                }
            }
        }

        return dis;
    }
};