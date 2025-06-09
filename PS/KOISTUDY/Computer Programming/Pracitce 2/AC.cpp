#include <bits/stdc++.h>
using namespace std;
typedef array<int, 2> pr;

const int MAX = 1001;

int N, A[MAX][MAX], D[MAX][MAX];
bool vst[MAX][MAX];
pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int move(int X1, int Y1, int X2, int Y2) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            vst[i][j] = false, D[i][j] = 0;

    queue<pr> q;
    pr K;
    int DX, DY;

    q.push({X1, Y1}), vst[X1][Y1] = true;

    while (!q.empty()) {
        K = q.front(), q.pop();
        for (pr i : go) {
            DX = K[0] + i[0], DY = K[1] + i[1];
            if (DX < 0 || DX >= N || DY < 0 || DY >= N || A[DX][DY] == 0 || vst[DX][DY])
                continue;

            q.push({DX, DY}), vst[DX][DY] = true, D[DX][DY] = D[K[0]][K[1]] + 1;
        }
    }

    return D[X2][Y2];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X[3], Y[3], ans = 0;
    string S;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < N; j++) {
            A[i][j] = S[j] != '#';
            if (S[j] == 'S')
                X[0] = i, Y[0] = j;
            else if (S[j] == 'T')
                X[1] = i, Y[1] = j;
            else if (S[j] == 'G')
                X[2] = i, Y[2] = j;
        }
    }

    ans = move(X[0], Y[0], X[1], Y[1]) + move(X[1], Y[1], X[2], Y[2]);

    cout << ans << '\n';

    return 0;
}