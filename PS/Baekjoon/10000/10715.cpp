#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], B[MAX], D[MAX], S[MAX], dis[MAX];

vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, C, ans;
    vector<int> arr;

    cin >> N >> M >> C;
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> D[i], arr.push_back(i);
        adj[A[i]].push_back({D[i], B[i]}), adj[B[i]].push_back({D[i], A[i]});
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    fill(dis + 2, dis + N + 1, INF);
    pq.push({0, 1});

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (dis[K[1]] < K[0])
            continue;

        for (pr i : adj[K[1]])
            if (K[0] + i[0] < dis[i[1]])
                dis[i[1]] = K[0] + i[0], pq.push({dis[i[1]], i[1]});
    }

    for (int i = 0; i < M; i++)
        if (dis[A[i]] > dis[B[i]])
            swap(A[i], B[i]);

    sort(arr.begin(), arr.end(), [&](int x, int y) { return dis[B[x]] < dis[B[y]]; });
    for (int i = 1; i <= M; i++)
        S[i] = S[i - 1] + D[arr[i - 1]];

    ans = S[M];
    for (int i = 0; i < M; i++)
        ans = min(ans, C * dis[B[arr[i]]] + S[M] - S[i + 1]);

    cout << ans << '\n';

    return 0;
}