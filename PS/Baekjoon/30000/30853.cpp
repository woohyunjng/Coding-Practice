#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int A[MAX], ans[MAX], tree[MAX * 4];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = 1;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

int query(int n, int s, int e, int x) {
    if (s == e)
        return s;
    else {
        int m = s + e >> 1;
        if (x <= tree[n << 1])
            return query(n << 1, s, m, x);
        else
            return query(n << 1 | 1, m + 1, e, x - tree[n << 1]);
    }
}

void update(int n, int s, int e, int x) {
    if (s == e)
        tree[n] = 0;
    else {
        int m = s + e >> 1;
        if (x <= m)
            update(n << 1, s, m, x);
        else
            update(n << 1 | 1, m + 1, e, x);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, D = 0, X;

    cin >> N, init(1, 0, N - 1);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    swap(A[0], A[A[N - 1] % (N - 1)]);

    for (int i = 0; i < N; i++) {
        X = query(1, 0, N - 1, D + 1), ans[X] = A[i];
        update(1, 0, N - 1, X);
        if (i < N - 1)
            D = (D + A[i] - 1) % (N - i - 1);
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << '\n';

    return 0;
}