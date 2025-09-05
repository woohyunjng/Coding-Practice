#include <bits/stdc++.h>
using namespace std;

typedef array<int, 4> pr;

const int MAX = 3001;
const int MAX_N = 51;

int N, D[MAX], A[MAX_N][MAX_N];
vector<int> adj[MAX];

pr go[6] = {{0, 1, 1, 0}, {0, -1, 1, 0}, {0, 1, -1, 0}, {0, -1, -1, 0}, {1, 0, -1, 0}, {0, 1, 0, -1}};
bool V[4][6];

int min_dis() {
    queue<int> q;
    int X;

    fill(D, D + N * N + 1, 0);
    if (V[3][A[1][1]])
        D[1] = 1, q.push(1);

    while (!q.empty()) {
        X = q.front(), q.pop();
        for (int i : adj[X]) {
            if (D[i] != 0)
                continue;
            D[i] = D[X] + 1, q.push(i);
        }
    }

    if (!V[1][A[N][N]])
        D[N * N] = 0;
    if (D[N * N] == 0)
        return MAX;
    return D[N * N];
}

void gen_graph() {
    for (int i = 1; i <= N * N; i++)
        adj[i].clear();

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (V[1][A[i][j]] && V[3][A[i][j + 1]] && j + 1 <= N) {
                adj[(i - 1) * N + j].push_back((i - 1) * N + (j + 1));
                adj[(i - 1) * N + (j + 1)].push_back((i - 1) * N + j);
            }

            if (V[2][A[i][j]] && V[0][A[i + 1][j]] && i + 1 <= N) {
                adj[(i - 1) * N + j].push_back(i * N + j);
                adj[i * N + j].push_back((i - 1) * N + j);
            }
        }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, ans = MAX;

    V[0][2] = V[0][3] = V[0][4] = true;
    V[1][0] = V[1][2] = V[1][5] = true;
    V[2][0] = V[2][1] = V[2][4] = true;
    V[3][1] = V[3][3] = V[3][5] = true;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];

    if (K) {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) {
                K = A[i][j];
                for (A[i][j] = 0; A[i][j] < 6; A[i][j]++) {
                    if (A[i][j] == K)
                        continue;
                    gen_graph(), ans = min(ans, min_dis());
                }
                A[i][j] = K;
            }
    } else
        gen_graph(), ans = min(ans, min_dis());

    cout << (ans == MAX ? -1 : ans) << '\n';

    return 0;
}