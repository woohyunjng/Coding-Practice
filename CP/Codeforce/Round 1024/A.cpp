#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 501;

int ans[MAX][MAX];
pr go[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve() {
    int N, X = 1, Y = 0, D = 0;

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            ans[i][j] = -1;

    for (int i = N * N - 1; i >= 0; i--) {
        while (X + go[D][0] > N || X + go[D][0] <= 0 || Y + go[D][1] > N || Y + go[D][1] <= 0 || ans[X + go[D][0]][Y + go[D][1]] != -1)
            D = (D + 1) % 4;
        X += go[D][0], Y += go[D][1], ans[X][Y] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}