#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 250001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int D[MAX], L[MAX];
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, E = 0, X, Y, A, B, C;

    cin >> N >> M >> X >> Y;
    S = (X - 1) * M + Y;

    cin >> A >> B >> C;

    function<void(int, int)> connect = [&](int U, int V) {
        if (abs(L[U] - L[V]) > C)
            return;
        if (L[U] == L[V]) {
            adj[U].push_back({V, 1}), adj[V].push_back({U, 1});
            return;
        }
        if (L[U] >= L[V])
            swap(U, V);
        adj[U].push_back({V, (L[V] - L[U]) * A});
        adj[V].push_back({U, (L[V] - L[U]) * B});
    };

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            cin >> L[(i - 1) * M + j], D[(i - 1) * M + j] = INF;
            if (L[(i - 1) * M + j] > L[E])
                E = (i - 1) * M + j;
            if (i > 1)
                connect((i - 2) * M + j, (i - 1) * M + j);
            if (j > 1)
                connect((i - 1) * M + j - 1, (i - 1) * M + j);
        }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    pq.push({0, S}), D[S] = 0;

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (D[K[1]] < K[0])
            continue;
        for (pr i : adj[K[1]])
            if (D[i[0]] > D[K[1]] + i[1])
                pq.push({D[i[0]] = D[K[1]] + i[1], i[0]});
    }

    D[E] = (D[E] == INF ? -1 : D[E]);
    cout << D[E] << '\n';

    return 0;
}