#include <bits/stdc++.h>
#define int long long

#define MAX 250100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], B[MAX], C[MAX], D[MAX], E[MAX], W[MAX], tree[MAX * 6], dis[MAX];
vector<pr> adj[MAX * 6];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, A, B, C, D, E, X;
    cin >> N >> M >> K;

    for (int i = 1; i < N; i++) {
        adj[i].push_back({0, i << 1}), adj[i].push_back({0, i << 1 | 1});
        adj[(i << 1) + (N << 1)].push_back({0, i + (N << 1)}), adj[(i << 1 | 1) + (N << 1)].push_back({0, i + (N << 1)});
    }
    for (int i = N; i < N << 1; i++)
        adj[i].push_back({0, i + (N << 1)});
    X = N << 2;

    for (int i = 1; i <= M; i++) {
        cin >> A >> B >> C >> D >> E;
        for (B += N - 1, C += N; B < C; B >>= 1, C >>= 1) {
            if (B & 1)
                adj[B++ + (N << 1)].push_back({A, X});
            if (C & 1)
                adj[--C + (N << 1)].push_back({A, X});
        }
        for (D += N - 1, E += N; D < E; D >>= 1, E >>= 1) {
            if (D & 1)
                adj[X].push_back({0, D++});
            if (E & 1)
                adj[X].push_back({0, --E});
        }
        X++;
    }

    fill(W, W + X, INF);
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr P;
    pq.push({0, K + N - 1}), W[K + N - 1] = 0;

    while (!pq.empty()) {
        P = pq.top(), pq.pop();
        if (W[P.second] < P.first)
            continue;

        for (pr i : adj[P.second]) {
            if (W[i.second] > P.first + i.first) {
                W[i.second] = P.first + i.first;
                pq.push({W[i.second], i.second});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (W[i + N - 1] == INF)
            W[i + N - 1] = -1;
        cout << W[i + N - 1] << ' ';
    }
    cout << '\n';

    return 0;
}