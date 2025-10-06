#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5001;

int N, M, tree[MAX][MAX];

void update(int x, int y, int v) {
    for (int i = x; i <= N; i += i & -i)
        for (int j = y; j <= M; j += j & -j)
            tree[i][j] += v;
}

int query(int x, int y) {
    int res = 0;
    for (int i = x; i; i -= i & -i)
        for (int j = y; j; j -= j & -j)
            res += tree[i][j];
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, T, X[2], Y[2], D;

    cin >> N >> M >> Q;
    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> X[0] >> Y[0] >> X[1] >> Y[1] >> D;
            update(X[0], Y[0], D), update(X[0], Y[1] + 1, -D), update(X[1] + 1, Y[0], -D), update(X[1] + 1, Y[1] + 1, D);
        } else {
            cin >> X[0] >> Y[0];
            cout << query(X[0], Y[0]) << '\n';
        }
    }

    return 0;
}