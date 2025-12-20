#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 4> tp;

const int MAX = 3001;
const int INF = 1e9;

int A[MAX][MAX], D[MAX][MAX][2];
bool chk[MAX][MAX];
pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, ans;
    pr E, J;
    tp X, Y;

    vector<pr> arr;
    string S;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= M; j++) {
            A[i][j] = S[j - 1] == '#';
            D[i][j][0] = D[i][j][1] = INF;

            if (S[j - 1] == 'S')
                E = {i, j};
            else if (S[j - 1] == 'J')
                J = {i, j};
            else if (S[j - 1] == 'T')
                chk[i][j] = true;
        }
    }

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    D[J[0]][J[1]][0] = 0, pq.push({0, J[0], J[1], 0});

    while (!pq.empty()) {
        X = pq.top(), pq.pop();
        if (D[X[1]][X[2]][X[3]] < X[0])
            continue;

        for (pr i : go) {
            Y = {X[0] + 2 - X[3], X[1] + i[0], X[2] + i[1], X[3]};
            if (Y[1] < 1 || Y[1] > N || Y[2] < 1 || Y[2] > M || A[Y[1]][Y[2]])
                continue;
            Y[3] |= chk[Y[1]][Y[2]];
            if (D[Y[1]][Y[2]][Y[3]] > Y[0])
                D[Y[1]][Y[2]][Y[3]] = Y[0], pq.push(Y);
        }
    }

    ans = min(D[E[0]][E[1]][0], D[E[0]][E[1]][1]);
    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}