#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX];
int A[MAX], dis[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, U, V, B;
    cin >> N >> M;

    fill(dis, dis + N + 1, LLONG_MAX);

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    while (M--) {
        cin >> U >> V >> B;
        arr[U].push_back({B, V});
        arr[V].push_back({B, U});
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({A[1], 1});
    dis[1] = A[1];

    while (pq.size()) {
        pr p = pq.top();
        pq.pop();

        if (dis[p.second] != p.first)
            continue;

        for (pr i : arr[p.second]) {
            if (A[i.second] + i.first + p.first < dis[i.second]) {
                dis[i.second] = A[i.second] + i.first + p.first;
                pq.push({dis[i.second], i.second});
            }
        }
    }

    for (int i = 2; i <= N; i++)
        cout << dis[i] << ' ';

    return 0;
}