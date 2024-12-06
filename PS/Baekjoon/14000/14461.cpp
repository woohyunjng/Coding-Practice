#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 4> tp;

int dis[MAX][MAX][4], A[MAX][MAX];
pr go[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T, X, Y;
    tp K;

    cin >> N >> T;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    fill(&dis[0][0][0], &dis[MAX][0][0], INF);
    pq.push({0, 1, 1, 0}), dis[1][1][0] = 0;

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (K[0] > dis[K[1]][K[2]][K[3]])
            continue;

        for (pr i : go) {
            X = K[1] + i.first, Y = K[2] + i.second;
            if (X < 1 || X > N || Y < 1 || Y > N)
                continue;

            if (K[3] < 2 && dis[X][Y][K[3] + 1] > K[0] + T) {
                dis[X][Y][K[3] + 1] = K[0] + T;
                pq.push({dis[X][Y][K[3] + 1], X, Y, K[3] + 1});
            }

            if (K[3] == 2 && dis[X][Y][0] > K[0] + T + A[X][Y]) {
                dis[X][Y][0] = K[0] + T + A[X][Y];
                pq.push({dis[X][Y][0], X, Y, 0});
            }
        }
    }

    cout << min({dis[N][N][0], dis[N][N][1], dis[N][N][2]}) << '\n';

    return 0;
}