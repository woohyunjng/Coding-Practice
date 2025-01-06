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
pr dist[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, T, A, B, C;
    pr K;
    cin >> N >> M >> S >> T;

    while (M--) {
        cin >> A >> B >> C;
        arr[A].push_back({C, B});
        arr[B].push_back({C, A});
    }

    fill(dist, dist + N + 1, pr(INF, INF));

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    dist[S] = {0, INF};
    pq.push({0, S});

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        for (pr i : arr[K.second]) {
            if (dist[i.second].first > K.first + i.first) {
                dist[i.second].second = dist[i.second].first;
                dist[i.second].first = K.first + i.first;
                pq.push({dist[i.second].first, i.second});
            } else if (dist[i.second].first < K.first + i.first && dist[i.second].second > K.first + i.first) {
                dist[i.second].second = K.first + i.first;
                pq.push({dist[i.second].second, i.second});
            }
        }
    }

    cout << dist[T].second;

    return 0;
}