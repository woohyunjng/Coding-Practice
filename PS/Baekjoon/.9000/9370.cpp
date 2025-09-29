#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 2001;

vector<pr> adj[MAX];
int N, dis[MAX][3];

void pth(int node, int t) {
    for (int i = 1; i <= N; i++)
        dis[i][t] = 1e9;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;
    pq.push({0, node}), dis[node][t] = 0;

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (dis[K[1]][t] < K[0])
            continue;
        for (pr i : adj[K[1]])
            if (dis[i[0]][t] > K[0] + i[1])
                pq.push({dis[i[0]][t] = K[0] + i[1], i[0]});
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, M, K, S, G, H, X, Y, Z, V;
    vector<int> arr, ans;

    cin >> T;
    while (T--) {
        cin >> N >> M >> K >> S >> G >> H;
        while (M--) {
            cin >> X >> Y >> Z;
            if (X == G && Y == H || X == H && Y == G)
                V = Z;
            adj[X].push_back({Y, Z}), adj[Y].push_back({X, Z});
        }

        while (K--)
            cin >> X, arr.push_back(X);

        pth(S, 0), pth(G, 1), pth(H, 2);

        for (int i : arr)
            if (dis[i][0] == dis[G][0] + V + dis[i][2] || dis[i][0] == dis[H][0] + V + dis[i][1])
                ans.push_back(i);

        sort(ans.begin(), ans.end());
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';

        arr.clear(), ans.clear();
        for (int i = 1; i <= N; i++)
            adj[i].clear();
    }

    return 0;
}