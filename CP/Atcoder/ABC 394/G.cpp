#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 600;
const int MAX_Q = 300000;
const int MAX_L = 1500000;

int F[MAX][MAX], A[MAX_Q], B[MAX_Q], Y[MAX_Q], C[MAX_Q], D[MAX_Q], Z[MAX_Q], L[MAX_Q], R[MAX_Q], ans[MAX_Q], parent[MAX * MAX];
vector<int> lst[MAX_L];
vector<pr> val[MAX_L];

pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int find(int X) { return parent[X] == X ? X : parent[X] = find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    parent[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, x, y;
    bool flag;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            cin >> F[i][j];
            val[F[i][j]].push_back({i, j});
        }

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> A[i] >> B[i] >> Y[i] >> C[i] >> D[i] >> Z[i];
        L[i] = 1, R[i] = min(Y[i], Z[i]);
    }

    while (true) {
        flag = false;
        for (int i = 1; i <= N * M; i++)
            parent[i] = i;
        for (int i = 1; i <= Q; i++) {
            if (L[i] <= R[i])
                flag = true, lst[L[i] + R[i] >> 1].push_back(i);
        }
        if (!flag)
            break;

        for (int i = 1000000; i >= 1; i--) {
            for (pr j : val[i]) {
                x = j[0], y = j[1];
                for (pr k : go) {
                    if (x + k[0] < 1 || x + k[0] > N || y + k[1] < 1 || y + k[1] > M)
                        continue;
                    if (F[x][y] <= F[x + k[0]][y + k[1]])
                        uni((x - 1) * M + y, (x + k[0] - 1) * M + y + k[1]);
                }
            }

            for (int j : lst[i]) {
                if (find((A[j] - 1) * M + B[j]) == find((C[j] - 1) * M + D[j]))
                    ans[j] = i, L[j] = i + 1;
                else
                    R[j] = i - 1;
            }
            lst[i].clear();
        }
    }

    for (int i = 1; i <= Q; i++)
        cout << Y[i] + Z[i] - 2 * ans[i] << '\n';

    return 0;
}