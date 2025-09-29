#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 101;

pr go[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int A[MAX][MAX], uf[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X != Y)
        uf[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, U, V, C, ans = 0;
    vector<int> lst;
    vector<tp> arr;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> A[i][j], uf[(i - 1) * M + j] = (i - 1) * M + j;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            for (pr k : go) {
                X = i + k[0], Y = j + k[1];
                if (X < 1 || X > N || Y < 1 || Y > M)
                    continue;
                if (A[i][j] == 1 && A[X][Y] == 1)
                    uni((i - 1) * M + j, (X - 1) * M + Y);
            }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (A[i][j] == 1 && find((i - 1) * M + j) == (i - 1) * M + j)
                lst.push_back((i - 1) * M + j);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            if (A[i][j] == 0)
                continue;
            U = (i - 1) * M + j;
            for (pr k : go)
                for (int l = 1; l <= max(N, M); l++) {
                    X = i + k[0] * l, Y = j + k[1] * l;
                    if (X < 1 || X > N || Y < 1 || Y > M || find(U) == find((X - 1) * M + Y))
                        break;
                    if (A[X][Y] == 0)
                        continue;
                    if (l - 1 < 2)
                        break;
                    V = (X - 1) * M + Y, C = l - 1, arr.push_back({C, find(U), find(V)});
                    break;
                }
        }

    sort(arr.begin(), arr.end());
    for (tp i : arr) {
        if (find(i[1]) != find(i[2]))
            ans += i[0], uni(i[1], i[2]);
    }

    for (int i : lst)
        if (find(i) != find(lst[0]))
            ans = -1;

    cout << ans << '\n';

    return 0;
}