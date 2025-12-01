#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], tree[MAX * 4][3], lazy[MAX * 4][3];

void lazy_update(int t, int n, int s, int e) {
    if (lazy[n][t] == 0)
        return;
    tree[n][t] += lazy[n][t];
    if (s ^ e)
        lazy[n << 1][t] += lazy[n][t], lazy[n << 1 | 1][t] += lazy[n][t];
    lazy[n][t] = 0;
}

void update(int t, int n, int s, int e, int l, int r, int v) {
    lazy_update(t, n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n][t] += v, lazy_update(t, n, s, e);
    else {
        int m = s + e >> 1;
        update(t, n << 1, s, m, l, r, v), update(t, n << 1 | 1, m + 1, e, l, r, v);
        if (t == 2)
            tree[n][t] = tree[n << 1][t] + tree[n << 1 | 1][t];
        else
            tree[n][t] = min(tree[n << 1][t], tree[n << 1 | 1][t]);
    }
}

int query(int t, int n, int s, int e, int l, int r) {
    lazy_update(t, n, s, e);
    if (r < s || e < l)
        return t == 2 ? 0 : INF;
    else if (l <= s && e <= r)
        return tree[n][t];
    else {
        int m = s + e >> 1;
        if (t == 2)
            return query(t, n << 1, s, m, l, r) + query(t, n << 1 | 1, m + 1, e, l, r);
        else
            return min(query(t, n << 1, s, m, l, r), query(t, n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, L, R, K, ans, V[6];
    bool flag;

    cin >> N >> Q;
    while (Q--) {
        cin >> T >> L >> R;
        V[0] = query(0, 1, 1, N, L - 1, L - 1), V[1] = query(0, 1, 1, N, L, L), V[2] = query(0, 1, 1, N, L + 1, L + 1);
        V[3] = query(0, 1, 1, N, R - 1, R - 1), V[4] = query(0, 1, 1, N, R, R), V[5] = query(0, 1, 1, N, R + 1, R + 1);

        if (T == 1) {
            cin >> K, update(0, 1, 1, N, L, R, K);
            V[1] += K, V[2] += K, V[3] += K, V[4] += K;
            if (L == R)
                V[2] -= K, V[3] -= K;

            update(2, 1, 1, N, L, L, -query(2, 1, 1, N, L, L) + max(0ll, V[1] - V[0]));
            update(2, 1, 1, N, L + 1, L + 1, -query(2, 1, 1, N, L + 1, L + 1) + max(0ll, V[2] - V[1]));
            update(2, 1, 1, N, R, R, -query(2, 1, 1, N, R, R) + max(0ll, V[4] - V[3]));
            update(2, 1, 1, N, R + 1, R + 1, -query(2, 1, 1, N, R + 1, R + 1) + max(0ll, V[5] - V[4]));

            update(1, 1, 1, N, L - 1, R + 1, K), update(1, 1, 1, N, L, L, -K), update(1, 1, 1, N, R, R, -K);
        } else {
            if (L == R) {
                cout << (query(0, 1, 1, N, L, L) == 0 ? 0 : -1) << '\n';
                continue;
            }

            flag = V[1] <= V[2], flag &= V[4] <= V[3], flag &= L < R, ans = 0;
            flag &= query(1, 1, 1, N, L + 1, R - 1) >= 0;

            if (!flag)
                ans = -1;
            else
                ans = query(0, 1, 1, N, L, L) + query(2, 1, 1, N, L + 1, R);
            cout << ans << '\n';
        }
    }

    return 0;
}