#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200000;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<pr> adj[MAX];
int dis[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, A, B, C, ans = 0;
    pr K;
    cin >> H >> A >> B >> C, H--;

    for (int i = 0; i < A; i++) {
        adj[i].push_back({B, (i + B) % A});
        adj[i].push_back({C, (i + C) % A});
    }

    fill(dis, dis + A, INF);

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({0, 0}), dis[0] = 0;

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (dis[K[1]] < K[0])
            continue;

        for (pr i : adj[K[1]]) {
            if (dis[i[1]] <= K[0] + i[0])
                continue;
            dis[i[1]] = K[0] + i[0], pq.push({dis[i[1]], i[1]});
        }
    }

    for (int i = 0; i < A; i++) {
        if (dis[i] > H)
            continue;
        ans += (H - i) / A - (dis[i] - i) / A + 1;
    }

    cout << ans << '\n';

    return 0;
}