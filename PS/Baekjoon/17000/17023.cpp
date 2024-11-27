#include <bits/stdc++.h>
#define int long long

#define MAX 10100
#define INF 500000000

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> adj[MAX];
vector<int> child[MAX];
pr dis[MAX];
int C[MAX], dp[MAX], T;

int dfs(int K) {
    int res = 0;
    for (int i : child[K])
        res = max(res, dfs(i)), C[K] += C[i];
    if (K != 1 && (dis[K].first - dis[dis[K].second].first) >= T)
        res = max(res, C[K] * (dis[K].first - T));
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z, res = 0;
    pr K;
    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++)
        cin >> C[i];

    while (M--) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Z, Y}), adj[Y].push_back({Z, X});
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    fill(dis, dis + N + 1, (pr){INF, N + 1});
    pq.push({0, 1}), dis[1] = {0, 0};

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (K.first > dis[K.second].first)
            continue;

        for (pr i : adj[K.second]) {
            if (dis[i.second].first > dis[K.second].first + i.first || (dis[i.second].first == dis[K.second].first + i.first && dis[i.second].second > K.second)) {
                dis[i.second] = {dis[K.second].first + i.first, K.second};
                pq.push({dis[i.second].first, i.second});
            }
        }
    }

    for (int i = 1; i <= N; i++)
        child[dis[i].second].push_back(i);

    cout << dfs(1) << '\n';

    return 0;
}