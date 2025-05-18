#include <bits/stdc++.h>

using namespace std;
typedef array<int, 2> pr;

const int MAX = 30;

int A[MAX][MAX], par[MAX * MAX], D[MAX][MAX];
pr go[4] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int find(int X) { return X == par[X] ? X : par[X] = find(par[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    par[max(X, Y)] = min(X, Y);
}

int G(int X, int Y) { return (X / 2 + Y / 2) % 2; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, V[4] = {0, 0, 0, 0}, SX, SY, GX, GY, X;
    bool chk, flag;

    string S;

    vector<pr> st, ans;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < N; j++) {
            if (S[j] == '.' || S[j] == '_')
                A[i][j] = 0;
            else if (S[j] == 'W')
                A[i][j] = 1, V[i % 2]++, V[j % 2 + 2]++;
            else
                A[i][j] = 2, st.push_back({i, j});
        }
    }

    chk = V[0] * V[1] == 0 && V[2] * V[3] == 0;

    for (pr p : st) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                par[i * N + j] = i * N + j, D[i][j] = 0;

        A[p[0]][p[1]] = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (A[i][j] != 1)
                    continue;
                for (pr k : go) {
                    SX = i + k[0], SY = j + k[1];
                    GX = i - k[0], GY = j - k[1];

                    if (SX < 0 || SX >= N || SY < 0 || SY >= N || GX < 0 || GX >= N ||
                        GY < 0 || GY >= N || A[SX][SY] != 0 || A[GX][GY] != 0 || G(SX, SY) != G(p[0], p[1]))
                        continue;

                    uni(i * N + j, SX * N + SY), uni(i * N + j, GX * N + GY);
                    D[SX][SY]++;
                }
            }

        X = find(p[0] * N + p[1]), flag = true;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (A[i][j] != 1)
                    continue;
                flag &= find(i * N + j) == X;
            }

        A[p[0]][p[1]] = 2;

        X = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                X += D[i][j] % 2;
        flag &= X == 0 || (X == 2 && D[p[0]][p[1]] % 2 == 1);
        if (!flag)
            continue;
        ans.push_back(p);
    }

    chk &= !ans.empty();

    if (!chk)
        cout << "None\n";
    else if (ans.size() > 1)
        cout << "Multiple\n";
    else
        cout << (char)('a' + ans[0][1]) << N - ans[0][0] << '\n';

    return 0;
}