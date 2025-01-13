#include <bits/stdc++.h>
using namespace std;

vector<int> tree, lazy, gcd_tree, arr;

int gcd(int X, int Y) {
    int T;
    if (X > Y)
        swap(X, Y);
    if (X == 0)
        return Y;
    while (Y % X)
        T = Y % X, Y = X, X = T;
    return X;
}

int lcm(int X, int Y) {
    int G = gcd(X, Y);
    return X * Y / G;
}

void lazy_propagate(int n, int s, int e) {
    if (lazy[n] == 1)
        return;
    tree[n] = lcm(tree[n], lazy[n]);
    if (s != e) {
        lazy[n << 1] = lcm(lazy[n << 1], lazy[n]);
        lazy[n << 1 | 1] = lcm(lazy[n << 1 | 1], lazy[n]);
    }
    lazy[n] = 1;
}

int query(int n, int s, int e, int x) {
    lazy_propagate(n, s, e);
    if (x < s || e < x)
        return 1;
    else if (s == e)
        return tree[n];

    int m = s + e >> 1;
    int left_val = query(n << 1, s, m, x), right_val = query(n << 1 | 1, m + 1, e, x);
    return lcm(left_val, right_val);
}

void update(int n, int s, int e, int l, int r, int x) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        lazy[n] = lcm(lazy[n], x);
        lazy_propagate(n, s, e);
        return;
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, x), update(n << 1 | 1, m + 1, e, l, r, x);
    }
}

void init(int n, int s, int e) {
    if (s == e) {
        gcd_tree[n] = arr[s];
        return;
    }
    int m = s + e >> 1;
    init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    gcd_tree[n] = gcd(gcd_tree[n << 1], gcd_tree[n << 1 | 1]);
}

int gcd_query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return gcd_tree[n];
    int m = s + e >> 1;
    int left_val = gcd_query(n << 1, s, m, l, r), right_val = gcd_query(n << 1 | 1, m + 1, e, l, r);
    return gcd(left_val, right_val);
}

vector<int> find_sequence(int N, vector<int> L, vector<int> R, vector<int> X) {
    int M = L.size(), l, r, x;
    bool flag = true;

    vector<int> answer(N, 0);

    tree.resize(N * 4 + 1), lazy.resize(N * 4 + 1), gcd_tree.resize(N * 4 + 1), arr.resize(N + 1);
    fill(tree.begin(), tree.end(), 1), fill(lazy.begin(), lazy.end(), 1), fill(gcd_tree.begin(), gcd_tree.end(), 0);

    for (int i = 0; i < M; i++) {
        l = L[i] + 1, r = R[i] + 1, x = X[i];
        update(1, 1, N, l, r, x);
    }

    for (int i = 0; i < N; i++)
        answer[i] = arr[i + 1] = query(1, 1, N, i + 1);

    init(1, 1, N);
    for (int i = 0; i < M; i++) {
        l = L[i] + 1, r = R[i] + 1, x = X[i];
        flag &= gcd_query(1, 1, N, l, r) == x;
    }

    if (!flag)
        for (int i = 0; i < N; i++)
            answer[i] = 0;

    return answer;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> L, R, X, ans;
    int N, M, l, r, x;

    cin >> N >> M;
    while (M--) {
        cin >> l >> r >> x;
        L.push_back(l - 1), R.push_back(r - 1), X.push_back(x);
    }

    ans = find_sequence(N, L, R, X);

    if (ans[0] == 0) {
        cout << "Impossible\n";
        return 0;
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}