#include <bits/stdc++.h>
#define int long long

#define MAX 50100
#define MOD 1000000007
#define INF 5000000000
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX];
int dis[MAX][2], P[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, Y, Z;
    tp A;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        P[i] = -INF;

    while (M--) {
        cin >> X >> Y >> Z;
        arr[X].push_back({Z, Y}), arr[Y].push_back({Z, X});
    }

    while (K--) {
        cin >> X >> Y;
        P[X] = max(P[X], Y);
    }

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    fill(&dis[0][0], &dis[N][2], INF);
    pq.push({0, N, 0}), dis[N][0] = 0;

    while (!pq.empty()) {
        A = pq.top(), pq.pop();
        if (dis[A[1]][A[2]] < A[0])
            continue;

        for (pr i : arr[A[1]]) {
            if (dis[i.second][A[2]] > A[0] + i.first) {
                dis[i.second][A[2]] = A[0] + i.first;
                pq.push({dis[i.second][A[2]], i.second, A[2]});
            }

            if (A[2] == 0 && dis[i.second][1] > A[0] + i.first - P[i.second]) {
                dis[i.second][1] = A[0] + i.first - P[i.second];
                pq.push({dis[i.second][1], i.second, 1});
            }
        }
    }

    for (int i = 1; i < N; i++)
        cout << (dis[i][0] >= dis[i][1]) << '\n';

    return 0;
}