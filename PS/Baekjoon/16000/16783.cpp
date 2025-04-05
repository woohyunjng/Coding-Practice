#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 3> tp;
typedef array<int, 2> pr;

const int MAX = 2001;

int X[MAX], Y[MAX], T[MAX], P[MAX];

struct Node {
    int lv, rv, mx, sm;

    Node() : lv(0), rv(0), mx(0), sm(0) {}
    Node(int t) : lv(max(0ll, t)), rv(max(0ll, t)), mx(t), sm(t) {}
};

Node merge(Node A, Node B) {
    Node res;
    res.lv = max(A.lv, A.sm + B.lv);
    res.rv = max(B.rv, A.rv + B.sm);
    res.mx = max({A.mx, B.mx, A.rv + B.lv});
    res.sm = A.sm + B.sm;
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

    int N, A, B, C, D, K, ans = 0;

    vector<tp> arr;
    vector<pr> rotating_line;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> K;
        arr.push_back({X[i], Y[i], K});
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

    ans = max(ans, query(1, 0, N - 1, 0, N - 1).mx);
    for (int i = 0; i < rotating_line.size(); i++) {
        A = rotating_line[i][0], B = rotating_line[i][1];

        K = query(1, 0, N - 1, P[A], P[A]).sm;
        update(1, 0, N - 1, P[A], query(1, 0, N - 1, P[B], P[B]).sm), update(1, 0, N - 1, P[B], K);
        swap(P[A], P[B]);

        if (i == rotating_line.size() - 1)
            ans = max(ans, query(1, 0, N - 1, 0, N - 1).mx);
        else {
            C = rotating_line[i + 1][0], D = rotating_line[i + 1][1];
            if ((Y[A] - Y[B]) * (X[C] - X[D]) != (Y[C] - Y[D]) * (X[A] - X[B]))
                ans = max(ans, query(1, 0, N - 1, 0, N - 1).mx);
        }
    }

    cout << ans << '\n';
}
