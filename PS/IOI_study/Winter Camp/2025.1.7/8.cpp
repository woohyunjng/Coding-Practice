#include <bits/stdc++.h>
#define int long long

#define MAX 1000100

using namespace std;
typedef pair<int, int> pr;

pr tree[MAX * 4];

pr merge(pr A, pr B) {
    return {
        A.first + B.first,
        max(B.second, A.second + B.first)};
}

void init(int n, int s, int e) {
    if (s == e) {
        tree[n] = {0, s};
        return;
    }

    int mid = (s + e) >> 1;
    init(n << 1, s, mid), init(n << 1 | 1, mid + 1, e);
    tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
}

pr query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {0, 0};
    if (l <= s && e <= r)
        return tree[n];

    int mid = (s + e) >> 1;
    return merge(query(n << 1, s, mid, l, r), query(n << 1 | 1, mid + 1, e, l, r));
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    if (s == e) {
        tree[n].first += v, tree[n].second += v;
        return;
    }

    int mid = (s + e) >> 1;
    update(n << 1, s, mid, x, v), update(n << 1 | 1, mid + 1, e, x, v);
    tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
}

int inp[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, X, Y, st, en, mid, res;
    char T;

    init(1, 1, 1000000);

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> T;
        if (T == '?') {
            cin >> X;
            cout << max(0ll, query(1, 1, 1000000, 1, X).second - X) << '\n';
        } else if (T == '-')
            cin >> X, update(1, 1, 1000000, inp[X][0], -inp[X][1]);
        else {
            cin >> X >> Y, update(1, 1, 1000000, X, Y);
            inp[i][0] = X, inp[i][1] = Y;
        }
    }

    return 0;
}