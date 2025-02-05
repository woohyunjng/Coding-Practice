#include <bits/stdc++.h>
#define int long long

#define MAX 2000
using namespace std;
typedef array<int, 2> pr;

int val[MAX][MAX];
pr go[8] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, N, S, X, Y;
    pr K;

    queue<pr> q;
    set<int> st;

    while (true) {
        cin >> M >> N >> S;
        if (M == 0 && N == 0 && S == 0)
            break;

        st.clear();
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                val[i][j] = 0;

        while (S--) {
            cin >> X >> Y;
            val[X][Y] = 1, q.push({X, Y});
        }

        while (!q.empty()) {
            K = q.front(), q.pop();
            X = K[0], Y = K[1];

            for (pr i : go) {
                if (X + i[0] >= 1 && X + i[0] <= M && Y + i[1] >= 1 && Y + i[1] <= N) {
                    if (val[X + i[0]][Y + i[1]] == 0) {
                        val[X + i[0]][Y + i[1]] = val[X][Y] + 1;
                        q.push({X + i[0], Y + i[1]});
                    }
                }
            }
        }

        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                st.insert(val[i][j]);

        cout << st.size() << '\n';
    }

    return 0;
}