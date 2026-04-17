#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 100001;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<pr> dadj[2][MAX], adj[MAX];
int U[2][MAX], V[2][MAX], L[2][MAX], D[2][MAX], vst[MAX], dp[MAX], in[MAX];

bool chk(int node) {
    if (vst[node])
        return vst[node] == -1;
    vst[node] = -1;
    for (pr j : adj[node])
        if (chk(j[0]))
            return true;
    vst[node] = 1;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M[2], S, T, X;

    cin >> N >> S >> T;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    for (int i = 0; i < 2; i++) {
        cin >> M[i];
        for (int j = 1; j <= M[i]; j++) {
            cin >> U[i][j] >> V[i][j] >> L[i][j];
            dadj[i][U[i][j]].push_back({V[i][j], L[i][j]});
            dadj[i][V[i][j]].push_back({U[i][j], L[i][j]});
        }

        fill(D[i] + 1, D[i] + N + 1, INF);
        pq.push({0, T}), D[i][T] = 0;

        while (!pq.empty()) {
            K = pq.top(), pq.pop();
            for (pr j : dadj[i][K[1]])
                if (D[i][j[0]] > K[0] + j[1])
                    D[i][j[0]] = K[0] + j[1], pq.push({D[i][j[0]], j[0]});
        }

        for (int j = 1; j <= M[i]; j++) {
            if (D[i][U[i][j]] < D[i][V[i][j]])
                adj[V[i][j] * 2 - i].push_back({U[i][j] * 2 - (i ^ 1), L[i][j]}), in[U[i][j] * 2 - (i ^ 1)]++;
            else if (D[i][U[i][j]] > D[i][V[i][j]])
                adj[U[i][j] * 2 - i].push_back({V[i][j] * 2 - (i ^ 1), L[i][j]}), in[V[i][j] * 2 - (i ^ 1)]++;
        }
    }

    if (chk(S * 2)) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 1; i <= N * 2; i++) {
        if (vst[i])
            continue;
        for (pr j : adj[i])
            in[j[0]]--;
    }

    queue<int> q;
    q.push(S * 2);

    while (!q.empty()) {
        X = q.front(), q.pop();
        for (pr j : adj[X]) {
            dp[j[0]] = max(dp[j[0]], dp[X] + j[1]);
            if (--in[j[0]] == 0)
                q.push(j[0]);
        }
    }

    cout << max(dp[T * 2], dp[T * 2 - 1]) << '\n';

    return 0;
}