#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dis[MAX][2];
vector<pr> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, E, T, A, B;
    tp K;
    cin >> N >> M;

    while (M--) {
        cin >> S >> E >> T;
        arr[S].push_back({T, E});
        arr[E].push_back({T, S});
    }

    cin >> A >> B;
    priority_queue<tp, vector<tp>, greater<tp>> pq;
    pq.push({0, A, 0});

    fill(&dis[0][0], &dis[N + 1][2], INF);

    dis[A][0] = 0;
    dis[A][1] = 0;

    while (pq.size()) {
        K = pq.top(), pq.pop();

        if (dis[K[1]][K[2]] != K[0])
            continue;

        for (pr i : arr[K[1]]) {
            if (K[1] == A) {
                dis[i.second][i.first] = 0;
                pq.push({0, i.second, i.first});
                continue;
            }

            if (K[2] == i.first) {
                if (dis[i.second][i.first] > K[0]) {
                    dis[i.second][i.first] = K[0];
                    pq.push({dis[i.second][i.first], i.second, i.first});
                }
            } else {
                if (dis[i.second][i.first] > K[0] + 1) {
                    dis[i.second][i.first] = K[0] + 1;
                    pq.push({dis[i.second][i.first], i.second, i.first});
                }
            }
        }
    }

    cout << min(dis[B][0], dis[B][1]);

    return 0;
}