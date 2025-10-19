#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<array<int, 2>, 2> Node;

const int MAX = 40001;

Node tree[MAX * 4];
int A[MAX];

Node merge(Node X, Node Y) {
    Node res = Node{{{0, 0}, {0, 0}}};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            if (X[i][0] > 0 && Y[1][j] > 0)
                res[i][j] = max(res[i][j], X[i][0] + Y[1][j]);
            if (X[i][1] > 0 && Y[0][j] > 0)
                res[i][j] = max(res[i][j], X[i][1] + Y[0][j]);
            if (X[i][0] > 0 && Y[0][j] > 0)
                res[i][j] = max(res[i][j], X[i][0] + Y[0][j]);
        }
    for (int i = 0; i < 2; i++) {
        res[i][0] = max({res[i][0], X[i][0], X[i][1]});
        res[0][i] = max({res[0][i], Y[0][i], Y[1][i]});
    }
    return res;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = Node{{{0, 0}, {0, A[s]}}};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = Node{{{0, 0}, {0, v}}};
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, D, X, Y, ans = 0;

    cin >> N >> D;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    init(1, 1, N);

    while (D--) {
        cin >> X >> Y;
        update(1, 1, N, X, Y), X = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                X = max(X, tree[1][i][j]);
        ans += X;
    }

    cout << ans << '\n';

    return 0;
}