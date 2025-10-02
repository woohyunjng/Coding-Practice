#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 2002;

int A[MAX][MAX], S[MAX][MAX], uf[MAX * MAX];
pr go[2] = {{1, 0}, {0, 1}};

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X != Y)
        uf[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string _S;
    int N, M, Q, R[2], C[2], V, X, Y, PX, PY;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> _S;
        for (int j = 1; j <= M; j++) {
            A[i][j] = _S[j - 1] - '0';
            uf[(i - 1) * M + j] = (i - 1) * M + j;
        }
    }

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
            for (pr k : go) {
                X = i + k[0], Y = j + k[1];
                if (A[i][j] != 0 || A[X][Y] != 0)
                    continue;
                if (i <= 0 || i > N || j <= 0 || j > M)
                    PX = 0;
                else
                    PX = (i - 1) * M + j;

                if (X <= 0 || X > N || Y <= 0 || Y > M)
                    PY = 0;
                else
                    PY = (X - 1) * M + Y;

                uni(PX, PY);
            }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (A[i][j] == 0 && find((i - 1) * M + j) != 0)
                A[i][j] = 1;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i][j];

    cin >> Q;
    while (Q--) {
        cin >> R[0] >> C[0] >> R[1] >> C[1];
        V = S[R[1]][C[1]] - S[R[0] - 1][C[1]] - S[R[1]][C[0] - 1] + S[R[0] - 1][C[0] - 1];
        if (V == 0)
            cout << "Yes" << '\n';
        else
            cout << "No" << ' ' << V << '\n';
    }

    return 0;
}