#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], QR[MAX], ans[MAX], tree[MAX * 4], R[MAX];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = 1;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
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

int kth(int n, int s, int e, int k) {
    if (s == e)
        return s;
    else {
        int m = s + e >> 1;
        if (tree[n << 1] >= k)
            return kth(n << 1, s, m, k);
        else
            return kth(n << 1 | 1, m + 1, e, k - tree[n << 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, S, D, X, Y, Z, V;
    vector<int> queries;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], A[i];
    sort(A + 1, A + N + 1);

    cin >> Q >> D;
    for (int i = 1; i <= Q; i++) {
        cin >> QR[i], QR[i];
        if (QR[i] >= A[1])
            queries.push_back(i);
        else
            ans[i] = QR[i];
    }

    sort(queries.begin(), queries.end(), [&](int a, int b) { return QR[a] > QR[b]; }), S = queries.size();

    X = 0, Y = INF, init(1, 1, N);
    for (int i = N, j = 0; i > 0;) {
        V = (Y - A[i] + i - 1) / i, Z = Y - V * i;
        for (; j < S && QR[queries[j]] >= Z; j++) {
            R[queries[j]] = X + (Y - QR[queries[j]] + i - 1) / i - D;
            QR[queries[j]] = kth(1, 1, N, i - (Y - QR[queries[j]] + i - 1) % i);
        }
        X += V, Y = Z;
        for (; i > 0 && A[i] >= Y; i--)
            update(1, 1, N, kth(1, 1, N, A[i] - Y + 1), -1);
    }

    sort(queries.begin(), queries.end(), [&](int a, int b) { return R[a] < R[b]; });

    X = 0, Y = INF, init(1, 1, N);
    for (int i = N, j = 0; i > 0;) {
        V = (Y - A[i] + i - 1) / i, Z = Y - V * i;
        for (; j < S && R[queries[j]] <= X + V; j++)
            ans[queries[j]] = query(1, 1, N, 1, QR[queries[j]]) + Y - 1 - (R[queries[j]] - X) * i;
        X += V, Y = Z;
        for (; i > 0 && A[i] >= Y; i--)
            update(1, 1, N, kth(1, 1, N, A[i] - Y + 1), -1);
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}