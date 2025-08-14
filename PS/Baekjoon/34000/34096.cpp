#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 1000001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], C[MAX], tree[MAX * 4][2], lazy[MAX * 4]; // 0 -> dp, 1 -> val + dp

void init(int n, int s, int e) {
    lazy[n] = 0;
    if (s == e)
        tree[n][0] = tree[n][1] = INF;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n][0] = min(tree[n << 1][0], tree[n << 1 | 1][0]);
        tree[n][1] = min(tree[n << 1][1], tree[n << 1 | 1][1]);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n][0] += lazy[n], tree[n][1] += lazy[n];
    tree[n][0] = min(tree[n][0], INF), tree[n][1] = min(tree[n][1], INF);
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void update(int n, int s, int e, int x, int v1, int v2) {
    lazy_update(n, s, e);
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n][0] = v1, tree[n][1] = v2;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v1, v2), update(n << 1 | 1, m + 1, e, x, v1, v2);
        tree[n][0] = min(tree[n << 1][0], tree[n << 1 | 1][0]);
        tree[n][1] = min(tree[n << 1][1], tree[n << 1 | 1][1]);
    }
}

void add(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] += v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        add(n << 1, s, m, l, r, v), add(n << 1 | 1, m + 1, e, l, r, v);
        tree[n][0] = min(tree[n << 1][0], tree[n << 1 | 1][0]);
        tree[n][1] = min(tree[n << 1][1], tree[n << 1 | 1][1]);
    }
}

int query(int n, int s, int e, int l, int r, int t) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return INF;
    else if (l <= s && e <= r)
        return tree[n][t];
    else {
        int m = s + e >> 1;
        return min(
            query(n << 1, s, m, l, r, t),
            query(n << 1 | 1, m + 1, e, l, r, t));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X, Y, ans;
    vector<pr> comp;

    cin >> T;
    while (T--) {
        cin >> N, comp.clear();
        for (int i = 1; i <= N; i++)
            cin >> A[i], comp.push_back({A[i], i});

        if (N <= 2) {
            cout << max(A[1], N == 2 ? A[2] : 0) << '\n';
            continue;
        }

        sort(comp.begin(), comp.end());
        for (int i = 1; i <= N; i++)
            C[comp[i - 1][1]] = i;
        init(1, 1, N);

        update(1, 1, N, C[1], max(A[2], A[3]), A[1] + max(A[2], A[3]));
        update(1, 1, N, C[2], max(A[1], A[3]), A[2] + max(A[1], A[3]));
        update(1, 1, N, C[3], max(A[1], A[2]), A[3] + max(A[1], A[2]));

        for (int i = 4; i + 1 <= N; i += 2) {
            X = min(A[i + 1] + query(1, 1, N, 1, C[i + 1], 0), query(1, 1, N, C[i + 1] + 1, N, 1));
            Y = min(A[i] + query(1, 1, N, 1, C[i], 0), query(1, 1, N, C[i] + 1, N, 1));

            add(1, 1, N, 1, N, max(A[i], A[i + 1]));
            update(1, 1, N, C[i], X, X + A[i]), update(1, 1, N, C[i + 1], Y, Y + A[i + 1]);
        }

        if (N % 2 == 0)
            ans = min(query(1, 1, N, C[N] + 1, N, 1), A[N] + query(1, 1, N, 1, C[N], 0));
        else
            ans = query(1, 1, N, 1, N, 1);

        cout << ans << '\n';
    }

    return 0;
}