#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int gcd(int X, int Y) { return Y == 0 ? X : gcd(Y, X % Y); }
pr merge(pr X, pr Y) { return {min(X[0], Y[0]), max(X[1], Y[1])}; }
int merge(int X, int Y) {
    if (X == -1 || Y == -1)
        return X == -1 ? Y : X;
    return X * Y == 0 ? 0 : gcd(X, Y);
}

int A[MAX], gtree[MAX * 4];
pr tree[2][MAX * 4];
map<int, set<int>> mp;

pr query(int t, int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {INF, -INF};
    else if (l <= s && e <= r)
        return tree[t][n];
    else {
        int m = s + e >> 1;
        return merge(query(t, n << 1, s, m, l, r), query(t, n << 1 | 1, m + 1, e, l, r));
    }
}

void update(int t, int n, int s, int e, int x, pr v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[t][n] = v;
    else {
        update(t, n << 1, s, s + e >> 1, x, v), update(t, n << 1 | 1, (s + e >> 1) + 1, e, x, v);
        tree[t][n] = merge(tree[t][n << 1], tree[t][n << 1 | 1]);
    }
}

void ginit(int n, int s, int e) {
    if (s == e)
        gtree[n] = abs(A[s] - A[s + 1]);
    else {
        int m = s + e >> 1;
        ginit(n << 1, s, m), ginit(n << 1 | 1, m + 1, e);
        gtree[n] = merge(gtree[n << 1], gtree[n << 1 | 1]);
    }
}

int gquery(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return -1;
    else if (l <= s && e <= r)
        return gtree[n];
    else {
        int m = s + e >> 1;
        return merge(gquery(n << 1, s, m, l, r), gquery(n << 1 | 1, m + 1, e, l, r));
    }
}

void gupdate(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        gtree[n] = v;
    else {
        int m = s + e >> 1;
        gupdate(n << 1, s, m, x, v), gupdate(n << 1 | 1, m + 1, e, x, v);
        gtree[n] = merge(gtree[n << 1], gtree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, X, Y, K;
    bool ans;
    pr V, Z;

    set<int>::iterator it;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], update(0, 1, 1, N, i, (pr){A[i], A[i]});
        mp[A[i]].insert(i);
    }
    ginit(1, 1, N - 1);

    for (int i = 1; i <= N; i++) {
        it = mp[A[i]].find(i);
        X = it == mp[A[i]].begin() ? 0 : *prev(it);
        Y = next(it) == mp[A[i]].end() ? N + 1 : *next(it);
        update(1, 1, 1, N, i, (pr){Y, X});
    }

    while (Q--) {
        cin >> T >> X >> Y;
        if (T == 1) {
            V = query(1, 1, 1, N, X, X), it = mp[A[X]].find(X);
            if (it != mp[A[X]].begin()) {
                Z = query(1, 1, 1, N, *prev(it), *prev(it));
                update(1, 1, 1, N, *prev(it), (pr){V[0], Z[1]});
            }
            if (next(it) != mp[A[X]].end()) {
                Z = query(1, 1, 1, N, *next(it), *next(it));
                update(1, 1, 1, N, *next(it), (pr){Z[0], V[1]});
            }

            mp[A[X]].erase(X), mp[Y].insert(X), it = mp[Y].find(X);
            V = {N + 1, 0};
            if (next(it) != mp[Y].end()) {
                V[0] = *next(it), Z = query(1, 1, 1, N, *next(it), *next(it));
                update(1, 1, 1, N, *next(it), (pr){Z[0], X});
            }
            if (it != mp[Y].begin()) {
                V[1] = *prev(it), Z = query(1, 1, 1, N, *prev(it), *prev(it));
                update(1, 1, 1, N, *prev(it), (pr){X, Z[1]});
            }
            update(1, 1, 1, N, X, V);

            update(0, 1, 1, N, X, (pr){Y, Y}), A[X] = Y;
            if (X > 1)
                gupdate(1, 1, N - 1, X - 1, abs(A[X] - A[X - 1]));
            if (X < N)
                gupdate(1, 1, N - 1, X, abs(A[X + 1] - A[X]));
        } else {
            V = query(0, 1, 1, N, X, Y), K = gquery(1, 1, N - 1, X, Y - 1);
            ans = (V[1] - V[0]) % (Y - X) == 0;
            if (V[0] != V[1]) {
                ans &= K != 0 && K % ((V[1] - V[0]) / (Y - X)) == 0;
                V = query(1, 1, 1, N, X, Y), ans &= V[1] < X && Y < V[0];
            }
            cout << (ans ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}