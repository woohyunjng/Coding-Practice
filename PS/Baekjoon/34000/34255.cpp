#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 2000002;

struct Node {
    int mx = 0, mx_cnt, val = 0, upd = 0, lazy = 0;
    bool fl = false, fr = false;

    Node(int len = 0) : mx_cnt(len) {}
};

Node merge(Node X, Node Y) {
    Node res;
    res.mx = max(X.mx, Y.mx);
    if (res.mx == X.mx)
        res.mx_cnt += X.mx_cnt, res.fl = true;
    if (res.mx == Y.mx)
        res.mx_cnt += Y.mx_cnt, res.fr = true;
    res.val = X.val + Y.val;
    return res;
}

vector<int> arr[MAX], queries[MAX], area[MAX];

int L[MAX], R[MAX], ans[MAX], idx[MAX], DL[MAX], DR[MAX];
Node tree[MAX * 4];

void lazy_update(int n, int s, int e) {
    if (tree[n].lazy == 0)
        return;
    tree[n].mx += tree[n].lazy;
    if (s ^ e)
        tree[n << 1].lazy += tree[n].lazy, tree[n << 1 | 1].lazy += tree[n].lazy;
    tree[n].lazy = 0;
}

void upd_update(int n, int s, int e) {
    if (tree[n].upd == 0)
        return;
    tree[n].val += tree[n].mx_cnt * tree[n].upd;
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
        tree[n].mx_cnt = 1;
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

    int N, M, Q, U, V, C = 0;

    cin >> N >> M >> Q;
    init(1, 1, M);

    for (int i = 1; i <= N; i++)
        arr[i].push_back(0);

    for (int i = 1; i <= M; i++) {
        cin >> U >> V;
        arr[U].push_back(i), arr[V].push_back(i);
    }

    for (int i = 1; i <= N; i++)
        arr[i].push_back(M + 1);

    for (int i = 1; i <= Q; i++) {
        cin >> L[i] >> R[i];
        queries[L[i] - 1].push_back(-i), queries[R[i]].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j + 1 < arr[i].size(); j++) {
            DL[++C] = arr[i][j] + 1, DR[C] = arr[i][j + 1] - 1, idx[C] = i;
            if (DL[C] > DR[C])
                continue;
            area[DL[C]].push_back(C), area[DR[C] + 1].push_back(-C);
        }

        for (int j = 0; j + 3 < arr[i].size(); j++) {
            DL[++C] = arr[i][j] + 1, DR[C] = arr[i][j + 1], idx[C] = i;
            if (DL[C] > DR[C] || arr[i][j + 2] > arr[i][j + 3] - 1)
                continue;
            area[arr[i][j + 2]].push_back(C), area[arr[i][j + 3]].push_back(-C);
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j : area[i]) {
            if (j > 0)
                update(1, 1, M, DL[j], DR[j], 1);
            else
                update(1, 1, M, DL[-j], DR[-j], -1);
        }

        if (tree[1].mx == N)
            tree[1].upd++, upd_update(1, 1, M);

        for (int j : queries[i]) {
            if (j > 0)
                ans[j] += query(1, 1, M, L[j], R[j]).val;
            else
                ans[-j] -= query(1, 1, M, L[-j], R[-j]).val;
        }
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}