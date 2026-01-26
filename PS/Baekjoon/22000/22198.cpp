#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<array<int, 5>, 5> val;

const int MAX = 50001;
const int INF = 1e15;

struct Node {
    val res;
    int r = 0;
    Node(int r = -1) : r(r) {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                res[i][j] = INF;
    }
};

int K;
val adj[MAX];
Node tree[MAX * 4];

Node merge(Node X, Node Y) {
    if (X.r == -1 || Y.r == -1)
        return X.r == -1 ? Y : X;
    Node res = Node(Y.r);
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            for (int x = 0; x < K; x++)
                for (int y = 0; y < K; y++)
                    res.res[i][j] = min(res.res[i][j], X.res[i][x] + adj[X.r][x][y] + Y.res[y][j]);
    return res;
}

void init(int n, int s, int e) {
    if (s == e) {
        tree[n] = Node(e);
        for (int i = 0; i < K; i++)
            tree[n].res[i][i] = 0;
    } else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

Node query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return Node(-1);
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, U, V, W, ans;

    cin >> K >> N >> M >> Q;
    for (int i = 0; i <= N / K; i++)
        for (int j = 0; j < K; j++)
            for (int k = 0; k < K; k++)
                adj[i][j][k] = INF;

    while (M--) {
        cin >> U >> V >> W;
        adj[U / K][U % K][V % K] = min(adj[U / K][U % K][V % K], W);
    }

    init(1, 0, N / K);

    while (Q--) {
        cin >> U >> V;
        ans = query(1, 0, N / K, U / K, V / K).res[U % K][V % K];
        cout << (ans == INF ? -1 : ans) << '\n';
    }

    return 0;
}