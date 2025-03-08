#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int A[MAX], tree[MAX * 4], sm[MAX];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = 0;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i], A[i] %= M;

    init(1, 0, M - 1);
    for (int i = 1; i <= N; i++) {
        X = query(1, 0, M - 1, 0, A[i] - 1), Y = query(1, 0, M - 1, A[i] + 1, M - 1);
        sm[M - A[i]] += X + Y;
        sm[0] += Y;
        update(1, 0, M - 1, A[i], 1);
    }

    init(1, 0, M - 1);
    for (int i = N; i >= 1; i--) {
        sm[M - A[i]] -= N - i - query(1, 0, M - 1, A[i], A[i]);
        update(1, 0, M - 1, A[i], 1);
    }

    for (int i = 1; i < M; i++)
        sm[i] += sm[i - 1];

    for (int i = 0; i < M; i++)
        cout << sm[i] << '\n';

    return 0;
}