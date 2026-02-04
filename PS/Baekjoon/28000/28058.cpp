#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 2002;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<pr> in[MAX], DL[MAX];
int X, Y, C[MAX],
    lazy[MAX * 4];
pr tree[MAX * 4];

int calc(pr line, int x) { return line[0] * x + line[1]; }

void init(int n, int s, int e) {
    tree[n] = {0, INF};
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n][1] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void insert(int n, int s, int e, int l, int r, pr line) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        pr low = tree[n], high = line;
        if (calc(low, s) >= calc(high, s))
            swap(low, high);
        if (calc(low, e) <= calc(high, e)) {
            tree[n] = low;
            return;
        }

        if (s ^ e) {
            int m = s + e >> 1;
            if (calc(low, m) <= calc(high, m))
                tree[n] = low, insert(n << 1 | 1, m + 1, e, l, r, high);
            else
                tree[n] = high, insert(n << 1, s, m, l, r, low);
        }
    } else {
        int m = s + e >> 1;
        insert(n << 1, s, m, l, r, line), insert(n << 1 | 1, m + 1, e, l, r, line);
    }
}

void add(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] = v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        insert(n << 1, s, m, s, m, tree[n]), insert(n << 1 | 1, m + 1, e, m + 1, e, tree[n]);
        tree[n] = {0, INF};
        add(n << 1, s, m, l, r, v), add(n << 1 | 1, m + 1, e, l, r, v);
    }
}

int query(int n, int s, int e, int x) {
    lazy_update(n, s, e);
    if (s == e)
        return calc(tree[n], x);
    else {
        int m = s + e >> 1, res = calc(tree[n], x);
        if (x <= m)
            res = min(res, query(n << 1, s, m, x));
        else
            res = min(res, query(n << 1 | 1, m + 1, e, x));
        return res;
    }
}

void spread(int x, int v, int c) {
    insert(1, 0, X + 1, x, X + 1, pr{c, v - c * x});
    insert(1, 0, X + 1, 0, x, pr{-c, v + c * x});
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, P, Q, R, S, E;
    vector<tp> arr;

    cin >> X >> Y >> N >> M;
    init(1, 0, X + 1);

    for (int i = 0; i < N; i++) {
        cin >> P >> Q >> R;
        in[Q].push_back({P, R});
    }
    for (int i = 0; i < M; i++) {
        cin >> S >> E >> P >> R;
        DL[P].push_back({S, R}), DL[P].push_back({E + 1, -R});
    }
    for (int i = 1; i < Y; i++)
        cin >> C[i];

    for (int i = 1; i < Y; i++) {
        arr.clear(), sort(DL[i].begin(), DL[i].end());
        E = S = 0;
        for (int j = 0; j < DL[i].size(); j++) {
            P = DL[i][j][0], Q = DL[i][j][1];
            while (j + 1 < DL[i].size() && DL[i][j + 1][0] == P)
                Q += DL[i][++j][1];
            if (S)
                arr.push_back({E, P - 1, S});
            S += Q, E = P;
        }
        for (tp j : arr)
            add(1, 0, X + 1, j[0], j[1], j[2]);

        for (pr j : in[i])
            spread(j[0], min(j[1], query(1, 0, X + 1, j[0])), C[i]);
        for (tp j : arr) {
            spread(j[0] - 1, query(1, 0, X + 1, j[0] - 1), C[i]);
            spread(j[1] + 1, query(1, 0, X + 1, j[1] + 1), C[i]);
        }
    }

    for (int i = 1; i <= X; i++)
        cout << query(1, 0, X + 1, i) << '\n';

    return 0;
}