#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 50001;
const int BUCKET = 300;
const int INF = 1e12;

vector<int> adj[MAX];
int T[MAX], C[MAX], ans[MAX], D[MAX][2],
    DF[MAX], DLT[MAX], MN[MAX],
    F[MAX][BUCKET], NS[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, U, V, W, S, CT;
    string _S;

    cin >> N >> M >> K;
    while (M--) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    cin >> _S, M = 0;
    for (int i = 1; i <= N; i++)
        T[i] = _S[i - 1] == '1', M += T[i];
    for (int i = 1; i <= N; i++) {
        ans[i] = D[i][0] = D[i][1] = MN[i] = INF;
        if (T[i] == 0)
            continue;
        for (int j : adj[i])
            if (T[j] >= 1)
                T[i] = 2;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++)
        if (T[i] >= 1) {
            for (int j : adj[i]) {
                if (D[j][0] == INF)
                    q.push(j), D[j][0] = 1;
            }
        }

    while (!q.empty()) {
        U = q.front(), q.pop();
        for (int i : adj[U]) {
            if (D[U][0] + 1 >= D[i][0])
                continue;
            q.push(i), D[i][0] = D[U][0] + 1;
        }
    }

    deque<int> dq;

    for (int i = 1; i <= N; i++)
        if (T[i] == 2)
            dq.push_back(i), D[i][1] = 0;

    while (!dq.empty()) {
        U = dq.front(), dq.pop_front();
        for (int i : adj[U]) {
            W = (T[U] == 0 ? 1 : 0) + D[U][1];
            if (W >= D[i][1])
                continue;
            if (W == D[U][1])
                dq.push_front(i);
            else
                dq.push_back(i);
            D[i][1] = W;
        }
    }

    cin >> S, K--;
    for (int i = 1; i <= K; i++)
        cin >> U, C[U]++;

    for (int i = 1; i <= N; i++) {
        D[i][0] -= 2;
        DF[1] += D[i][0] * C[i], DLT[1] += C[i];
        if (D[i][1] - D[i][0] < M) {
            DF[D[i][1] - D[i][0] + 1] += (D[i][1] - D[i][0]) * C[i];
            DLT[D[i][1] - D[i][0] + 1] -= C[i] * (D[i][1] - D[i][0] + 1);
            DLT[D[i][1] - D[i][0] + 2] += C[i] * (D[i][1] - D[i][0]);
        }
    }

    for (int i = 1; i <= M; i++)
        DF[i] += DF[i - 1], DLT[i] += DLT[i - 1];
    for (int i = 1; i <= M; i++)
        DLT[i] += DLT[i - 1], DF[i] += DLT[i] + i * K;

    dq.push_back(S), MN[S] = 0;
    while (!dq.empty()) {
        U = dq.front(), dq.pop_front();
        for (int i : adj[U]) {
            W = ((T[U] == 0 || U == S) ? 0 : 1) + MN[U];
            if (W >= MN[i])
                continue;
            if (W == MN[U])
                dq.push_front(i);
            else
                dq.push_back(i);
            MN[i] = W;
        }
    }

    for (int i = 1; i <= N; i++)
        NS[i] = INF;

    vector<int> start;

    q.push(S), NS[S] = 0;
    while (!q.empty()) {
        U = q.front(), q.pop();
        if (U != S && T[U] >= 1) {
            start.push_back(U);
            continue;
        }
        for (int i : adj[U]) {
            if (NS[U] + 1 >= NS[i])
                continue;
            q.push(i), NS[i] = NS[U] + 1;
        }
    }

    for (int i = 1; i <= N; i++)
        ans[i] = min(ans[i], NS[i]);

    CT = N / K + 100;
    if (CT < BUCKET) {
        for (int i = 1; i <= N; i++)
            for (int j = 0; j <= CT; j++)
                F[i][j] = INF;

        queue<pr> rq;
        pr P;

        rq.push({S, 0}), F[S][0] = 0;

        while (!rq.empty()) {
            P = rq.front(), rq.pop();

            for (int i : adj[P[0]]) {
                U = i, V = MN[P[0]] + P[1] + (!(P[0] == S && P[1] == 0) && T[P[0]] >= 1) - MN[U];
                if (V > CT || F[P[0]][P[1]] + 1 >= F[U][V])
                    continue;
                rq.push({U, V}), F[U][V] = F[P[0]][P[1]] + 1;
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= min(CT, M - MN[i]); j++)
                ans[i] = min(ans[i], F[i][j] + DF[MN[i] + j]);
        }
    } else {
        vector<pr> comp;
        for (int i = 1; i + 1 <= M; i++)
            comp.push_back({DF[i + 1] - DF[i], DF[i] - (DF[i + 1] - DF[i]) * (i - 1)});
        if (M == 1)
            comp.push_back({0, DF[1]});
        sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
        assert(comp.size() <= K * 2);

        priority_queue<tp, vector<tp>, greater<tp>> pq;
        tp Q;

        for (pr i : comp) {
            for (int j = 1; j <= N; j++)
                D[j][0] = D[j][1] = INF;

            pq.push({0, S, 0}), D[S][0] = 0;

            while (!pq.empty()) {
                Q = pq.top(), pq.pop();
                if (Q[0] != D[Q[1]][Q[2]])
                    continue;
                for (int j : adj[Q[1]]) {
                    V = ((T[Q[1]] >= 1 && Q[1] != S) ? (Q[2] == 0 ? 1 : Q[2]) : Q[2]);
                    W = ((T[Q[1]] >= 1 && Q[1] != S) ? (Q[2] == 0 ? i[1] : i[0]) : 0) + Q[0] + 1;
                    if (W >= D[j][V])
                        continue;
                    pq.push({W, j, V}), D[j][V] = W;
                }
            }

            for (int j = 1; j <= N; j++)
                ans[j] = min({ans[j], D[j][0], D[j][1]});
        }
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';

    return 0;
}