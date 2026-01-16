#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 100;
const int MAX_N = 10000;

int A[MAX][MAX], V[MAX][MAX], L[MAX_N], R[MAX_N];
bool chk[MAX_N];
vector<int> adj[MAX_N], rev[MAX_N];
pr go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool dfs(int node) {
    for (int i : adj[node]) {
        if (chk[i])
            continue;
        chk[i] = true;
        if (R[i] == -1 || dfs(R[i])) {
            R[i] = node, L[node] = i;
            return true;
        }
    }
    return false;
}

bool dfs2(int node) {
    for (int i : rev[node]) {
        if (chk[i])
            continue;
        chk[i] = true;
        if (L[i] == -1 || dfs2(L[i])) {
            L[i] = node, R[node] = i;
            return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, E, cntL, cntR, X, Y;
    bool flag;
    string S;

    while (true) {
        cin >> N >> E, cntL = cntR = 0;
        if (N == 0 && E == 0)
            break;

        for (int i = 0; i < N; i++) {
            cin >> S;
            for (int j = 0; j < E; j++)
                A[i][j] = S[j] == '.';
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < E; j++) {
                if (!A[i][j])
                    continue;
                if ((i + j) & 1)
                    V[i][j] = cntL++;
                else
                    V[i][j] = cntR++;
            }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < E; j++) {
                if (!A[i][j])
                    continue;
                for (pr k : go) {
                    X = i + k[0], Y = j + k[1];
                    if (X < 0 || X >= N || Y < 0 || Y >= E || !A[X][Y])
                        continue;
                    if ((i + j) & 1)
                        adj[V[i][j]].push_back(V[X][Y]);
                    else
                        rev[V[i][j]].push_back(V[X][Y]);
                }
            }

        fill(L, L + cntL, -1), fill(R, R + cntR, -1);
        for (int i = 0; i < cntL; i++)
            fill(chk, chk + cntR, false), dfs(i);

        for (int i = 0; i < N; i++, cout << '\n')
            for (int j = 0; j < E; j++) {
                if (!A[i][j]) {
                    cout << 'X';
                    continue;
                }
                fill(chk, chk + max(cntL, cntR), false);
                if ((i + j) & 1) {
                    if (L[V[i][j]] == -1 || dfs2(L[V[i][j]]))
                        cout << 'B', L[V[i][j]] = -1;
                    else
                        cout << 'A';
                } else {
                    if (R[V[i][j]] == -1 || dfs(R[V[i][j]]))
                        cout << 'B', R[V[i][j]] = -1;
                    else
                        cout << 'A';
                }
            }
        cout << '\n';

        for (int i = 0; i < max(cntL, cntR); i++)
            adj[i].clear(), rev[i].clear();
    }

    return 0;
}