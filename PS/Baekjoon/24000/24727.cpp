#include <bits/stdc++.h>
#define int long long

#define MAX 110
using namespace std;

int res[MAX][MAX];

bool chk(int X, int Y) {
    bool flag = res[X][Y] != 1;
    flag &= res[X + 1][Y] != 1 && res[X][Y + 1] != 1 && res[X - 1][Y] != 1 && res[X][Y - 1] != 1;
    return flag;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C, E;
    bool flag = true;

    cin >> N >> C >> E;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            if (C > 0)
                res[j][1 + i - j] = 1, C--;

    for (int i = 2; i <= N; i++)
        for (int j = i; j <= N; j++)
            if (C > 0)
                res[j][N - (j - i)] = 1, C--;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            if (E > 0) {
                flag &= chk(N - j + 1, N - i + j);
                res[N - j + 1][N - i + j] = 2, E--;
            }

    for (int i = 2; i <= N; i++)
        for (int j = i; j <= N; j++)
            if (E > 0) {
                flag &= chk(N - j + 1, j - i + 1);
                res[N + 1 - j][j - i + 1] = 2, E--;
            }

    if (!flag) {
        cout << -1 << '\n';
        return 0;
    }

    cout << 1 << '\n';
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cout << res[i][j];
        cout << '\n';
    }

    return 0;
}