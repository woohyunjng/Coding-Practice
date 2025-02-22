#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 5> ftp;

const int MAX = 300000;

int parent[MAX], rnk[MAX], mn[MAX], A[MAX], B[MAX];
vector<ftp> st;
vector<pr> tree[MAX * 4];
vector<int> val[MAX];

int find(int X) { return X == parent[X] ? X : find(parent[X]); }

void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    if (rnk[X] < rnk[Y])
        swap(X, Y);
    if (rnk[X] == rnk[Y])
        rnk[X]++, st.push_back({X, Y, mn[X], mn[Y], 1});
    else
        st.push_back({X, Y, mn[X], mn[Y], 0});
    parent[Y] = X, mn[X] = min(mn[X], mn[Y]);
}

void rollback(int cnt) {
    ftp K;
    while (cnt--) {
        K = st.back(), st.pop_back();
        parent[K[1]] = K[1], rnk[K[0]] -= K[4];
        mn[K[0]] = K[2], mn[K[1]] = K[3];
    }
}

void update(int n, int s, int e, int l, int r, pr v) {
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        tree[n].push_back(v);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
    }
}

bool dfs(int n, int s, int e) {
    int cnt = 0;
    bool res = true;

    for (pr i : tree[n]) {
        if (find(i[0]) == find(i[1]))
            continue;
        cnt++, uni(i[0], i[1]);
    }

    if (s == e) {
        for (int i : val[s])
            res &= mn[find(i)] == B[i];
    } else {
        int m = s + e >> 1;
        res &= dfs(n << 1, s, m);
        res &= dfs(n << 1 | 1, m + 1, e);
    }

    rollback(cnt);

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, S, X, Y, K = 0;
    bool ans;

    vector<pr> edge;

    cin >> T;

    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            parent[i] = i, rnk[i] = 1;
            val[i].clear();
        }
        for (int i = 1; i <= N * 4; i++)
            tree[i].clear();

        for (int i = 1; i <= N; i++)
            cin >> A[i], mn[i] = A[i];
        for (int i = 1; i <= N; i++) {
            cin >> B[i];
            val[B[i]].push_back(i);
        }

        for (int i = 1; i <= M; i++) {
            cin >> X >> Y;
            update(1, 1, N, max(B[X], B[Y]), min(A[X], A[Y]), {X, Y});
        }

        ans = dfs(1, 1, N);
        cout << ans << '\n';
    }

    return 0;
}