#include <bits/stdc++.h>
using namespace std;

const int N = 9;

int A[N][N];

bool dfs(int x, int y) {
    if (y == N)
        return dfs(x + 1, 0);
    if (x == N)
        return true;

    if (A[x][y] != 0)
        return dfs(x, y + 1);

    bool flag;

    for (int i = 1; i <= 9; i++) {
        A[x][y] = i, flag = true;

        for (int j = 0; j < N; j++)
            flag &= j == y || A[x][j] != i;
        for (int j = 0; j < N; j++)
            flag &= j == x || A[j][y] != i;
        for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++)
            for (int k = (y / 3) * 3; k < (y / 3) * 3 + 3; k++)
                flag &= (j == x && k == y) || A[j][k] != i;

        if (flag && dfs(x, y + 1))
            return true;
        A[x][y] = 0;
    }

    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    dfs(0, 0);

    for (int i = 0; i < N; i++, cout << '\n')
        for (int j = 0; j < N; j++)
            cout << A[i][j] << ' ';

    return 0;
}