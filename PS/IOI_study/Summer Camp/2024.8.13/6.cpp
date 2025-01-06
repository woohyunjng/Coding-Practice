#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX];
int dist[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, C, S;
    pr X;
    cin >> N >> M;

    cin >> S;

    while (M--) {
        cin >> A >> B >> C;
        arr[A].push_back({C, B});
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    fill(dist, dist + N + 1, INF);

    pq.push({0, S});
    dist[S] = 0;

    while (!pq.empty()) {
        X = pq.top(), pq.pop();
        if (dist[X.second] < X.first)
            continue;

        for (pr i : arr[X.second]) {
            if (dist[i.second] > X.first + i.first) {
                dist[i.second] = X.first + i.first;
                pq.push({dist[i.second], i.second});
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << (dist[i] == INF ? -1 : dist[i]) << '\n';

    return 0;
}