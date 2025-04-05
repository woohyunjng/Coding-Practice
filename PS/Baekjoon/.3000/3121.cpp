#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 3> tp;
typedef array<int, 2> pr;

const int MAX = 1001;

int X[MAX], Y[MAX], T[MAX], P[MAX];

struct Node {
    int lv, rv, sz, mx;

    Node() : lv(0), rv(0), sz(0), mx(0) {}
    Node(int t) : lv(t), rv(t), sz(1), mx(t) {}
};

Node merge(Node A, Node B) {
    Node res;
    res.sz = A.sz + B.sz;
    res.lv = A.lv == A.sz ? A.lv + B.lv : A.lv;
    res.rv = B.rv == B.sz ? A.rv + B.rv : B.rv;
    res.mx = max({A.mx, B.mx, A.rv + B.lv});
    return res;
}

Node tree[MAX * 4];

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = Node(v);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

Node query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return Node();
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, A, B, K, ans = 0;
    char C;

    vector<tp> arr;
    vector<pr> rotating_line;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> C;
        arr.push_back({X[i], Y[i], C == 'R' ? 1 : 0});
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        X[i] = arr[i][0], Y[i] = arr[i][1];
        P[i] = i, update(1, 0, N - 1, i, arr[i][2]);
    }

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            rotating_line.push_back({i, j});

    sort(rotating_line.begin(), rotating_line.end(), [&](pr x, pr y) {
        if ((Y[x[0]] - Y[x[1]]) * (X[y[0]] - X[y[1]]) == (Y[y[0]] - Y[y[1]]) * (X[x[0]] - X[x[1]]))
            return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0];
        return (Y[x[0]] - Y[x[1]]) * (X[y[0]] - X[y[1]]) < (Y[y[0]] - Y[y[1]]) * (X[x[0]] - X[x[1]]);
    });

    for (pr i : rotating_line) {
        A = i[0], B = i[1];
        ans = max(ans, query(1, 0, N - 1, 0, N - 1).mx);
        K = query(1, 0, N - 1, P[A], P[A]).mx;
        update(1, 0, N - 1, P[A], query(1, 0, N - 1, P[B], P[B]).mx), update(1, 0, N - 1, P[B], K);
        swap(P[A], P[B]);
    }

    cout << ans << '\n';
}
