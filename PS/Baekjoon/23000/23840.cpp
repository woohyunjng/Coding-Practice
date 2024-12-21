#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MAX_P 22
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> adj[MAX];
int P, dist[MAX_P][MAX], pair_dis[MAX_P][MAX_P], num[MAX_P], _dp[MAX_P][1 << MAX_P];

int dp(int K, int mask) {
    if (_dp[K][mask] != -1)
        return _dp[K][mask];

    int res = INF, cnt = 0;
    for (int i = 2; i < P; i++) {
        if (mask & (1 << i))
            continue;
        cnt++;
        res = min(res, dp(i, mask | (1 << i)) + pair_dis[K][i]);
    }
    if (!cnt)
        res = pair_dis[K][1];
    return _dp[K][mask] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, W;
    pr K;

    cin >> N >> M;

    while (M--) {
        cin >> U >> V >> W;
        adj[U].push_back({W, V}), adj[V].push_back({W, U});
    }

    cin >> num[0] >> num[1] >> P;
    for (int i = 0; i < P; i++)
        cin >> num[i + 2];
    P += 2;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < P; i++) {
        pq.push({0, num[i]});
        dist[i][num[i]] = 0;

        while (!pq.empty()) {
            K = pq.top(), pq.pop();
            if (dist[i][K.second] < K.first)
                continue;

            for (pr j : adj[K.second]) {
                if (dist[i][K.second] + j.first < dist[i][j.second] || dist[i][j.second] == -1) {
                    dist[i][j.second] = dist[i][K.second] + j.first;
                    pq.push({dist[i][j.second], j.second});
                }
            }
        }

        for (int j = 0; j < P; j++)
            pair_dis[i][j] = dist[i][num[j]] == -1 ? INF : dist[i][num[j]];
    }

    memset(_dp, -1, sizeof(_dp));
    W = dp(0, 1);
    cout << (W >= INF ? -1 : W) << '\n';

    return 0;
}