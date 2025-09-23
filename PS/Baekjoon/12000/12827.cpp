#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 400001;

struct Node {
    int mn = 0, mn_sm, val = 0, upd = 0, lazy = 0;
    bool fl = false, fr = false;

    Node(int len = 0) : mn_sm(len) {}
};

vector<int> queries[MAX], arr[MAX];
int X[MAX][2], Y[MAX][2], QX[MAX][2], QY[MAX][2],
    V[MAX], S[MAX], ans[MAX];
Node tree[MAX * 4];

Node merge(Node X, Node Y) {
    Node res;
    res.mn = min(X.mn, Y.mn);
    if (res.mn == X.mn)
        res.mn_sm += X.mn_sm, res.fl = true;
    if (res.mn == Y.mn)
        res.mn_sm += Y.mn_sm, res.fr = true;
    res.val = X.val + Y.val;
    return res;
}

void lazy_update(int n, int s, int e) {
    if (tree[n].lazy == 0)
        return;
    tree[n].mn += tree[n].lazy;
    if (s ^ e)
        tree[n << 1].lazy += tree[n].lazy, tree[n << 1 | 1].lazy += tree[n].lazy;
    tree[n].lazy = 0;
}

void upd_update(int n, int s, int e) {
    if (tree[n].upd == 0)
        return;
    tree[n].val += tree[n].mn_sm * tree[n].upd;
    if (s ^ e) {
        if (tree[n].fl)
            tree[n << 1].upd += tree[n].upd;
        if (tree[n].fr)
            tree[n << 1 | 1].upd += tree[n].upd;
    }
    tree[n].upd = 0;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n].mn_sm = V[s];
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    upd_update(n, s, e), lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        tree[n].lazy += v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

Node query(int n, int s, int e, int l, int r) {
    upd_update(n, s, e), lazy_update(n, s, e);
    if (r < s || e < l)
        return Node();
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, SX, SY, K = 0;
    vector<int> CX, CY;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i][0] >> Y[i][0] >> X[i][1] >> Y[i][1];
        CX.push_back(X[i][0]), CX.push_back(X[i][1]);
        CY.push_back(Y[i][0]), CY.push_back(Y[i][1]);
    }

    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> QX[i][0] >> QY[i][0] >> QX[i][1] >> QY[i][1];
        CX.push_back(QX[i][0]), CX.push_back(QX[i][1]);
        CY.push_back(QY[i][0]), CY.push_back(QY[i][1]);
    }

    sort(CX.begin(), CX.end()), CX.erase(unique(CX.begin(), CX.end()), CX.end()), SX = CX.size();
    sort(CY.begin(), CY.end()), CY.erase(unique(CY.begin(), CY.end()), CY.end()), SY = (int)CY.size() - 1;

    for (int i = 1; i <= SY; i++)
        V[i] = CY[i] - CY[i - 1], S[i] = S[i - 1] + V[i];
    init(1, 1, SY);

    for (int i = 1; i <= N; i++) {
        X[i][0] = lower_bound(CX.begin(), CX.end(), X[i][0]) - CX.begin() + 1;
        X[i][1] = lower_bound(CX.begin(), CX.end(), X[i][1]) - CX.begin() + 1;

        Y[i][0] = lower_bound(CY.begin(), CY.end(), Y[i][0]) - CY.begin() + 1;
        Y[i][1] = lower_bound(CY.begin(), CY.end(), Y[i][1]) - CY.begin();
        arr[X[i][0] + 1].push_back(i), arr[X[i][1] + 1].push_back(-i);
    }

    for (int i = 1; i <= M; i++) {
        QX[i][0] = lower_bound(CX.begin(), CX.end(), QX[i][0]) - CX.begin() + 1;
        QX[i][1] = lower_bound(CX.begin(), CX.end(), QX[i][1]) - CX.begin() + 1;

        QY[i][0] = QY[i + M][0] = lower_bound(CY.begin(), CY.end(), QY[i][0]) - CY.begin() + 1;
        QY[i][1] = QY[i + M][1] = lower_bound(CY.begin(), CY.end(), QY[i][1]) - CY.begin();
        queries[QX[i][0]].push_back(i), queries[QX[i][1]].push_back(i + M);
    }

    for (int i = 1; i <= SX; i++) {
        for (int j : arr[i]) {
            if (j > 0)
                update(1, 1, SY, Y[j][0], Y[j][1], 1);
            else
                update(1, 1, SY, Y[-j][0], Y[-j][1], -1);
        }

        K += i > 1 ? CX[i - 1] - CX[i - 2] : 0;
        if (tree[1].mn == 0 && i > 1)
            tree[1].upd += CX[i - 1] - CX[i - 2], upd_update(1, 1, SY);

        for (int j : queries[i])
            ans[j] = K * (S[QY[j][1]] - S[QY[j][0] - 1]) - query(1, 1, SY, QY[j][0], QY[j][1]).val;
    }

    for (int i = 1; i <= M; i++)
        cout << ans[i + M] - ans[i] << '\n';

    return 0;
}