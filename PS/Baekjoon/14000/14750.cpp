#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 30001;

int flow[MAX], cap[MAX], par[MAX], G[MAX][2];
pr P[MAX], HL[MAX], MC[MAX];
vector<pr> adj[MAX];

int CCW(pr A, pr B, pr C) { // A-B-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (B[0] - A[0]) * (C[1] - A[1]) - (C[0] - A[0]) * (B[1] - A[1]);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

bool is_intersect(pr A, pr B, pr C, pr D) { // A-B C-D 교차판정
    int AtoC = CCW(A, B, C) * CCW(A, B, D);
    int CtoA = CCW(C, D, A) * CCW(C, D, B);

    if (AtoC == 0 && CtoA == 0) {
        if (A > B)
            swap(A, B);
        if (C > D)
            swap(C, D);
        return C <= B && A <= D;
    }

    return AtoC <= 0 && CtoA <= 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, H, M, U, V, S, E, ans = 0, cnt = 0;
    bool flag;
    queue<int> q;

    cin >> N >> K >> H >> M;
    S = 0, E = M + H + 1;

    for (int i = 0; i < N; i++)
        cin >> P[i][0] >> P[i][1];
    for (int i = 0; i < H; i++)
        cin >> HL[i][0] >> HL[i][1];
    for (int i = 0; i < M; i++)
        cin >> MC[i][0] >> MC[i][1];

    for (int i = 1; i <= M; i++) {
        adj[0].push_back({i, cnt << 1}), adj[i].push_back({0, cnt << 1 | 1});
        cap[cnt << 1] = 1, G[cnt][0] = 0, G[cnt][1] = i, cnt++;
    }

    for (int i = 1; i <= H; i++) {
        adj[M + i].push_back({E, cnt << 1}), adj[E].push_back({M + i, cnt << 1 | 1});
        cap[cnt << 1] = K, G[cnt][0] = M + i, G[cnt][1] = E, cnt++;
    }

    for (int i = 0; i < M; i++)
        for (int j = 0; j < H; j++) {
            V = 0;
            for (int k = 0; k < N; k++) {
                V += is_intersect(MC[i], HL[j], P[k], P[(k + 1) % N]);
                if (P[k][0] == HL[j][0] && P[k][1] == HL[j][1])
                    V--;
            }
            if (V != 1)
                continue;
            adj[i + 1].push_back({M + j + 1, cnt << 1}), adj[M + j + 1].push_back({i + 1, cnt << 1 | 1});
            cap[cnt << 1] = 1, G[cnt][0] = i + 1, G[cnt][1] = M + j + 1, cnt++;
        }

    while (true) {
        fill(par, par + E + 1, -1);

        q.push(S), par[S] = 0;
        while (!q.empty()) {
            V = q.front(), q.pop();
            for (pr i : adj[V]) {
                if (par[i[0]] != -1 || flow[i[1]] == cap[i[1]])
                    continue;
                q.push(i[0]), par[i[0]] = i[1];
            }
        }
        if (par[E] == -1)
            break;

        U = MAX;
        for (V = E; V != S; V = G[par[V] >> 1][par[V] & 1])
            U = min(U, cap[par[V]] - flow[par[V]]);
        for (V = E; V != S; V = G[par[V] >> 1][par[V] & 1])
            flow[par[V]] += U, flow[par[V] ^ 1] -= U;
        ans += U;
    }

    cout << (ans == M ? "Possible" : "Impossible") << '\n';

    return 0;
}