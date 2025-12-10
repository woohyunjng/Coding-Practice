#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;

int A[MAX], L[MAX], R[MAX], lazy[MAX * 4], ans[MAX][2];
pr tree[MAX * 4];

vector<int> queries[MAX];

pr merge(pr X, pr Y) { return X[0] <= Y[0] ? X : Y; }

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = {0, s};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n][0] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] += v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int x) {
    lazy_update(n, s, e);
    if (s == e)
        return s;
    else {
        int m = s + e >> 1;
        lazy_update(n << 1, s, m), lazy_update(n << 1 | 1, m + 1, e);
        if (tree[n << 1 | 1][0] == 0 && tree[n << 1 | 1][1] <= x)
            return query(n << 1 | 1, m + 1, e, x);
        else
            return query(n << 1, s, m, x);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;

    set<pr> val;
    vector<int> upper, lower;

    cin >> N, init(1, 1, N);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    cin >> M;
    for (int i = 1; i <= M; i++)
        cin >> L[i] >> R[i], queries[R[i]].push_back(i);

    for (int i = 1; i <= N; i++) {
        for (int j : queries[i])
            val.insert({-L[j], j});

        while (!upper.empty() && A[upper.back()] < A[i]) {
            X = upper.back(), upper.pop_back();
            Y = upper.empty() ? 0 : upper.back();
            update(1, 1, N, Y + 1, X, A[i] - A[X]);
        }
        upper.push_back(i);

        while (!lower.empty() && A[lower.back()] > A[i]) {
            X = lower.back(), lower.pop_back();
            Y = lower.empty() ? 0 : lower.back();
            update(1, 1, N, Y + 1, X, -A[i] + A[X]);
        }
        lower.push_back(i);

        update(1, 1, N, 1, i - 1, -1);

        while (!val.empty() && tree[1][0] == 0 && -(*val.begin())[0] >= tree[1][1]) {
            X = (*val.begin())[1], val.erase(val.begin());
            ans[X][0] = query(1, 1, N, L[X]), ans[X][1] = i;
        }
    }

    for (int i = 1; i <= M; i++)
        cout << ans[i][0] << ' ' << ans[i][1] << '\n';

    return 0;
}