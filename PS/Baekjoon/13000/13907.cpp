#include <bits/stdc++.h>
#define int long long
#define MAX 1010
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX];
int dis[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, A, B, C, res, S, D;
    cin >> N >> M >> K;
    cin >> S >> D;

    while (M--) {
        cin >> A >> B >> C;
        arr[A].push_back({C, B});
        arr[B].push_back({C, A});
    }

    fill(dis[0], dis[N + 1], INF);
    priority_queue<tp, vector<tp>, greater<tp>> pq;

    pq.push({0, 0, S});
    dis[S][0] = 0;

    while (pq.size()) {
        tp X = pq.top();
        pq.pop();

        if (dis[X[2]][X[1]] != X[0])
            continue;

        for (pr i : arr[X[2]]) {
            if (X[1] + 1 < N && dis[i.second][X[1] + 1] > X[0] + i.first) {
                dis[i.second][X[1] + 1] = X[0] + i.first;
                pq.push({dis[i.second][X[1] + 1], X[1] + 1, i.second});
            }
        }
    }

    res = INF;
    for (int i = 1; i <= N; i++)
        res = min(res, dis[D][i]);
    cout << res << '\n';

    B = 0;
    while (K--) {
        cin >> A;
        B += A;

        res = INF;
        for (int i = 1; i <= N; i++)
            res = min(res, dis[D][i] + i * B);
        cout << res << '\n';
    }

    return 0;
}