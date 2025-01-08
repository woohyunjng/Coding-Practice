#include <bits/stdc++.h>
#define int long long

#define MAX 250100
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;
typedef pair<int, int> pr;

int N, A[MAX];
pr tree[MAX * 2 + 1];

pr merge(pr A, pr B) { return {A.first + B.first, min(A.second, B.second)}; }

void init() {
    for (int i = 1; i <= N; i++)
        tree[i + N - 1] = {A[i], A[i]};

    for (int i = N - 1; i > 0; --i)
        tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
}

pr query(int l, int r) {
    pr res = {0, INF};
    for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = merge(res, tree[l++]);
        if (r & 1)
            res = merge(res, tree[--r]);
    }
    return res;
}

void update(int pos, int val) {
    for (tree[pos += N - 1] = {val, val}; pos > 1; pos >>= 1)
        tree[pos >> 1] = merge(tree[pos], tree[pos ^ 1]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, T, L, R;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    init();

    while (Q--) {
        cin >> T >> L >> R;
        if (T == 1)
            update(L, R);
        else if (T == 2)
            cout << query(L, R).second << '\n';
        else
            cout << query(L, R).first << '\n';
    }

    return 0;
}