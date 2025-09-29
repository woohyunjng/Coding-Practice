#include <bits/stdc++.h>
using namespace std;

const int MAX = 501;

int uf[MAX], sz[MAX], val[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X != Y) {
        if (X > Y)
            swap(X, Y);
        uf[Y] = X, sz[X] += sz[Y], val[X] += val[Y];
    }
    val[X]++;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 0, N, M, U, V, ans;

    while (true) {
        cin >> N >> M, T++, ans = 0;
        if (N == 0 && M == 0)
            break;

        for (int i = 1; i <= N; i++)
            uf[i] = i, sz[i] = 1, val[i] = 0;

        while (M--)
            cin >> U >> V, uni(U, V);

        for (int i = 1; i <= N; i++) {
            if (find(i) != i || val[i] + 1 != sz[i])
                continue;
            ans++;
        }

        cout << "Case " << T << ": ";
        if (ans == 0)
            cout << "No trees.\n";
        else if (ans == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << ans << " trees.\n";
    }

    return 0;
}