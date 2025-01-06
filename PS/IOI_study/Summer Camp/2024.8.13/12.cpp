#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
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

    int N;
    pr K;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        arr[i % N].push_back({1, (i + 1) % N});
        arr[i % N].push_back({0, (10 * i) % N});
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({0, 1});

    fill(dist, dist + N + 1, INF);
    dist[1] = 0;

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (dist[K.second] < K.first)
            continue;

        for (pr i : arr[K.second]) {
            if (dist[i.second] > K.first + i.first) {
                dist[i.second] = K.first + i.first;
                pq.push({dist[i.second], i.second});
            }
        }
    }

    cout << dist[0] + 1;

    return 0;
}