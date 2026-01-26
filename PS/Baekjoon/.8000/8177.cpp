#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int val = -INF, sum = 0, lv = -INF, rv = -INF;
    Node() {}
    Node(int v) : val(v), sum(v), lv(v), rv(v) {}
};

Node tree[MAX * 4];

Node merge(Node X, Node Y) {
    if (X.val == -INF)
        return Y;
    if (Y.val == -INF)
        return X;
    Node res;
    res.sum = X.sum + Y.sum, res.val = max({X.val, Y.val, X.rv + Y.lv});
    res.lv = max(X.lv, X.sum + Y.lv), res.rv = max(Y.rv, X.rv + Y.sum);
    return res;
}

void init(int n, int s, int e, int k) {
    if (s == e)
        tree[n] = Node(-k);
    else {
        int m = s + e >> 1;
        init(n << 1, s, m, k), init(n << 1 | 1, m + 1, e, k);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = Node(tree[n].sum + v);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, K, D, X, Y;

    cin >> N >> Q >> K >> D;
    init(1, 1, N - D, K);

    while (Q--) {
        cin >> X >> Y, update(1, 1, N - D, X, Y);
        cout << (tree[1].val <= K * D ? "TAK" : "NIE") << '\n';
    }

    return 0;
}