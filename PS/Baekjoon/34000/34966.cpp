#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;

const int MAX = 1001;
const int INF = 2000000;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

int A[MAX][MAX], D[MAX][MAX], T[MAX][MAX];
pr ST[3], go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, ans = INF, X, Y, cnt = 0;
    tp K;

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    string S;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= N; j++) {
            if (S[j - 1] == '.')
                A[i][j] = 0;
            else if (S[j - 1] == 'a')
                A[i][j] = 1, cnt++;
            else if (S[j - 1] == 'b')
                A[i][j] = 2, cnt++;
            else if (S[j - 1] == 'A')
                A[i][j] = -1, ST[-A[i][j]] = (pr){i, j};
            else if (S[j - 1] == 'B')
                A[i][j] = -2, ST[-A[i][j]] = (pr){i, j};
        }
    }

    if (cnt == 0) {
        cout << 0 << '\n';
        return 0;
    }

    for (int t = 0; t < M; t++) {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                D[i][j] = INF, T[i][j] = 0;

        D[ST[t + 1][0]][ST[t + 1][1]] = 1, T[ST[t + 1][0]][ST[t + 1][1]] = abs(A[ST[t + 1][0]][ST[t + 1][1]]);
        pq.push({1, ST[t + 1][0], ST[t + 1][1]});

        while (!pq.empty()) {
            K = pq.top(), pq.pop();
            if (K[0] != D[K[1]][K[2]])
                continue;

            for (pr i : go) {
                X = K[1] + i[0], Y = K[2] + i[1];
                if (X <= 0 || X > N || Y <= 0 || Y > N)
                    continue;
                if (T[K[1]][K[2]] + A[X][Y] == 3) {
                    if (D[X][Y] > K[0] + 1) {
                        D[X][Y] = K[0] + 1, T[X][Y] = 3 - T[K[1]][K[2]];
                        pq.push({D[X][Y], X, Y});
                    }
                } else {
                    if (D[X][Y] > K[0]) {
                        D[X][Y] = K[0], T[X][Y] = T[K[1]][K[2]];
                        pq.push({D[X][Y], X, Y});
                    }
                }
            }
        }

        if (M == 2 && D[ST[2 - t][0]][ST[2 - t][1]] != 1)
            continue;

        X = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                X = max(X, D[i][j]);
        ans = min(ans, X);
    }

    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}