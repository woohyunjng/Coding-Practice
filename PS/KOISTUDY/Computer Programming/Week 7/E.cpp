#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 101;

int A[MAX][MAX], D[MAX][MAX];
bool vst[MAX][MAX];

pr go[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, ans = 0, X, Y;

    queue<pr> q;
    vector<pr> lst;
    pr K;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> A[i][j];

    q.push({1, 1}), vst[1][1] = true;

    while (true) {
        while (!q.empty()) {
            K = q.front(), q.pop();

            for (pr i : go) {
                X = K[0] + i[0], Y = K[1] + i[1];
                if (X < 1 || X > N || Y < 1 || Y > M || vst[X][Y])
                    continue;

                if (A[X][Y] == 0)
                    q.push({X, Y}), vst[X][Y] = true;
                else if (++D[X][Y] >= 2)
                    vst[X][Y] = true, lst.push_back({X, Y});
            }
        }

        if (lst.empty())
            break;
        ans++;

        for (pr i : lst)
            q.push(i);
        lst.clear();
    }

    cout << ans << '\n';

    return 0;
}