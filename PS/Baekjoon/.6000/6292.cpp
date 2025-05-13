#include <bits/stdc++.h>
using namespace std;

const int MAX = 4001;
typedef array<int, 2> pr;

int A[MAX][MAX], V[MAX][MAX];
pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    int H, W, ans = 0, DX, DY;
    pr X;

    string S;

    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        cin >> S;
        for (int j = 0; j < W; j++) {
            if (S[j] == '.')
                A[i][j] = 0;
            else if (S[j] == 'F')
                A[i][j] = 1;
            else
                A[i][j] = 2;
        }
    }

    deque<pr> dq;
    dq.push_back({0, 0}), V[0][0] = 1;

    while (!dq.empty()) {
        X = dq.front(), dq.pop_front();
        ans = max(ans, V[X[0]][X[1]]);

        for (pr i : go) {
            DX = X[0] + i[0], DY = X[1] + i[1];
            if (DX < 0 || DX >= H || DY < 0 || DY >= W || A[DX][DY] == 0 || V[DX][DY])
                continue;

            if (A[DX][DY] != A[X[0]][X[1]])
                dq.push_back({DX, DY}), V[DX][DY] = V[X[0]][X[1]] + 1;
            else
                dq.push_front({DX, DY}), V[DX][DY] = V[X[0]][X[1]];
        }
    }

    cout << ans << '\n';

    return 0;
}