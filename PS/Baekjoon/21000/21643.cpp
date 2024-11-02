#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int C[MAX], dis[MAX];
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, A, B;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        cin >> C[i];

    while (M--) {
        cin >> A >> B;
        adj[A].push_back({B, (C[B] - C[A] - 1 + K * 2) % K});
        adj[B].push_back({A, (C[A] - C[B] - 1 + K * 2) % K});
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    fill(dis, dis + N + 1, INF);

    dis[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [A, B] = pq.top();
        pq.pop();
        if (dis[B] < A)
            continue;

        for (pr i : adj[B]) {
            if (dis[i.first] > A + i.second) {
                dis[i.first] = A + i.second;
                pq.push({dis[i.first], i.first});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ((C[i] - dis[i] - 1) % K + K) % K + 1 << ' ';
    }

    return 0;
}