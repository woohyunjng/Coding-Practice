#include <bits/stdc++.h>
using namespace std;

const int MAX = 200002;
const int INF = 1000000000;

vector<int> tres[MAX], in[MAX], out[MAX];
int TY[MAX], TV[MAX], DL[MAX], DR[MAX],
    tree[MAX * 4], lazy[MAX * 4][2], // val, set, max
    mtree[MAX * 4], mlazy[MAX * 4];  // min val, add

void mlazy_update(int n, int s, int e) {
    if (mlazy[n] == 0)
        return;
    mtree[n] += mlazy[n];
    if (s ^ e)
        mlazy[n << 1] += mlazy[n], mlazy[n << 1 | 1] += mlazy[n];
    mlazy[n] = 0;
}

int mquery(int n, int s, int e, int l, int r) {
    mlazy_update(n, s, e);
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return mtree[n];
    else {
        int m = s + e >> 1;
        return max(
            mquery(n << 1, s, m, l, r),
            mquery(n << 1 | 1, m + 1, e, l, r));
    }
}

void mupdate(int n, int s, int e, int l, int r, int v) {
    mlazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        mlazy[n] += v, mlazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        mupdate(n << 1, s, m, l, r, v), mupdate(n << 1 | 1, m + 1, e, l, r, v);
        mtree[n] = max(mtree[n << 1], mtree[n << 1 | 1]);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n][1] == -1 && lazy[n][0] == -1)
        return;
    tree[n] = max(tree[n], lazy[n][1]), tree[n] = lazy[n][0] == -1 ? tree[n] : lazy[n][0];
    if (s ^ e) {
        if (lazy[n][0] != -1) {
            lazy[n << 1][0] = lazy[n][0], lazy[n << 1][1] = -1;
            lazy[n << 1 | 1][0] = lazy[n][0], lazy[n << 1 | 1][1] = -1;
        } else {
            if (lazy[n << 1][0] != -1)
                lazy[n << 1][0] = max(lazy[n << 1][0], lazy[n][1]);
            else
                lazy[n << 1][1] = max(lazy[n << 1][1], lazy[n][1]);

            if (lazy[n << 1 | 1][0] != -1)
                lazy[n << 1 | 1][0] = max(lazy[n << 1 | 1][0], lazy[n][1]);
            else
                lazy[n << 1 | 1][1] = max(lazy[n << 1 | 1][1], lazy[n][1]);
        }
    }
    lazy[n][0] = lazy[n][1] = -1;
}

void init(int n, int s, int e) {
    tree[n] = -INF, lazy[n][0] = lazy[n][1] = -1;
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    }
}

int query(int n, int s, int e, int x) {
    lazy_update(n, s, e);
    if (x < s || e < x)
        return -INF;
    else if (s == e)
        return tree[n];
    else {
        int m = s + e >> 1;
        return max(
            query(n << 1, s, m, x),
            query(n << 1 | 1, m + 1, e, x));
    }
}

void update(int n, int s, int e, int l, int r, int t, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n][t] = v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, t, v), update(n << 1 | 1, m + 1, e, l, r, t, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int mxR(int C, int X) {
    int res = X;
    for (int st = X, en = C, md; st <= en;) {
        md = st + en >> 1;
        if (mquery(1, 1, C, X, md) == 0)
            res = md, st = md + 1;
        else
            en = md - 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int R, C, N, M, X, Y, ans;

    cin >> R >> C >> N >> M, init(1, 1, C);
    for (int i = 1; i <= N; i++) {
        cin >> X >> TY[i] >> TV[i];
        tres[X].push_back(i);
    }

    for (int i = 1; i <= M; i++) {
        cin >> X >> DL[i] >> Y >> DR[i];
        in[X].push_back(i), out[Y + 1].push_back(i);
    }

    for (int i = 1; i <= C; i++) {
        sort(out[i].begin(), out[i].end(), [&](int x, int y) { return DL[x] < DL[y]; });
        sort(tres[i].begin(), tres[i].end(), [&](int x, int y) { return TY[x] < TY[y]; });

        for (int j : in[i])
            update(1, 1, C, DL[j], DR[j], 0, -INF), mupdate(1, 1, C, DL[j], DR[j], 1);
        for (int j : out[i]) {
            mupdate(1, 1, C, DL[j], DR[j], -1);
            update(1, 1, C, DL[j] - 1, mxR(C, DL[j] - 1), 1, query(1, 1, C, DL[j] - 1));
        }

        if (i == 1)
            update(1, 1, C, 1, mxR(C, 1), 1, 0);

        for (int j : tres[i]) {
            if (query(1, 1, C, TY[j]) == -INF)
                continue;
            update(1, 1, C, TY[j], mxR(C, TY[j]), 1, query(1, 1, C, TY[j]) + TV[j]);
        }
    }

    ans = query(1, 1, C, C);
    cout << (ans == -INF ? -1 : ans) << '\n';

    return 0;
}