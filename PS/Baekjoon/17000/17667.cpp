#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 801;

int U[MAX][MAX], V[1 << 4];
bool chk[MAX][MAX], vst[MAX][MAX];

pr go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dir_n(char C) { return C == 'N' ? 0 : C == 'S' ? 1
                                      : C == 'W'   ? 2
                                                   : 3; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, R, C, A, B, X, Y, Z, K, ans = MAX * MAX, ans_cnt = 0;
    bool flag;
    pr P;

    vector<pr> arr, his;
    queue<pr> q;

    string D;

    cin >> M >> R >> C >> D;
    D = D + D;

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> U[i][j];

    for (int i = 0; i < (1 << 4); i++) {
        X = 0;
        for (char c : D)
            X = (i & (1 << dir_n(c))) ? X + 1 : 0, V[i] = max(V[i], X);

        if (V[i] == 2 * M)
            V[i] = MAX * MAX;
    }

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            if (U[i][j] > 0)
                arr.push_back({i, j});

    random_shuffle(arr.begin(), arr.end());

    for (pr i : arr) {
        q.push(i), chk[i[0]][i[1]] = true, his.push_back(i), Z = 0;

        while (!q.empty()) {
            X = q.front()[0], Y = q.front()[1], q.pop(), Z++;
            flag = false;

            for (pr j : go) {
                A = X + j[0], B = Y + j[1], K = 0;
                if (A < 1 || A > R || B < 1 || B > C || chk[A][B] || U[A][B] == 0)
                    continue;

                for (int k = 0; k < 4; k++)
                    if (A + go[k][0] >= 1 && A + go[k][0] <= R && B + go[k][1] >= 1 && B + go[k][1] <= C)
                        K |= (chk[A + go[k][0]][B + go[k][1]] ? 1 : 0) << k;
                if (V[K] < U[A][B])
                    continue;
                flag |= vst[A][B], chk[A][B] = true, his.push_back({A, B}), q.push({A, B});
            }

            if (flag)
                break;
        }

        if (!flag) {
            if (Z < ans)
                ans = Z, ans_cnt = 1;
            else if (Z == ans)
                ans_cnt++;
        }

        vst[i[0]][i[1]] = true;
        for (pr j : his)
            chk[j[0]][j[1]] = false;
        his.clear();

        while (!q.empty())
            q.pop();
    }

    cout << ans << '\n'
         << ans_cnt * ans << '\n';

    return 0;
}