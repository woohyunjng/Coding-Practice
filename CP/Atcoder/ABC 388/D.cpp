#include <bits/stdc++.h>
#define int long long

#define MAX 500100
using namespace std;

int A[MAX], tree[MAX * 4];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = A[s];
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    }
}

void lazy(int n, int s, int e) {
    if (s == e)
        return;
    tree[n << 1] += tree[n], tree[n << 1 | 1] += tree[n];
    tree[n] = 0;
}

int query(int n, int s, int e, int x) {
    lazy(n, s, e);
    if (s == e)
        return tree[n];
    int m = s + e >> 1;
    if (x <= m)
        return query(n << 1, s, m, x);
    return query(n << 1 | 1, m + 1, e, x);
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy(n, s, e);
    if (r < s || e < l)
        return;
    if (l <= s && e <= r) {
        tree[n] += v, lazy(n, s, e);
        return;
    }
    int m = s + e >> 1;
    update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    init(1, 1, N);
    for (int i = 1; i <= N; i++) {
        X = query(1, 1, N, i), Y = min(X, N - i);
        cout << X - Y << ' ';
        update(1, 1, N, i + 1, i + Y, 1);
    }
    cout << '\n';

    return 0;
}