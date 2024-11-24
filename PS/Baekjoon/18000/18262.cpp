#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<tp> adj[MAX];
int dis[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, C, F, res = 0;
    tp K;
    cin >> N >> M;

    while (M--) {
        cin >> A >> B >> C >> F;
        adj[A].push_back({C, B, F});
        adj[B].push_back({C, A, F});
    }

    fill(&dis[0][0], &dis[MAX][0], INF);
    dis[1][1000] = 0;

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    pq.push({0, 1, 1000});

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (dis[K[1]][K[2]] < K[0])
            continue;

        for (tp i : adj[K[1]]) {
            if (dis[i[1]][min(i[2], K[2])] > K[0] + i[0]) {
                dis[i[1]][min(i[2], K[2])] = K[0] + i[0];
                pq.push({dis[i[1]][min(i[2], K[2])], i[1], min(i[2], K[2])});
            }
        }
    }

    for (int i = 1; i <= 1000; i++)
        res = max(res, 1000000 * i / dis[N][i]);

    cout << res << '\n';

    return 0;
}