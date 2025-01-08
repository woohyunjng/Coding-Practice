#include <bits/stdc++.h>
#define int long long

#define MAX 100100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool lazy[MAX * 4];
int tree[MAX * 4];

void lazy_update(int n, int s, int e) {
    if (!lazy[n])
        return;
    tree[n] = e - s + 1 - tree[n];
    if (s != e)
        lazy[n << 1] ^= 1, lazy[n << 1 | 1] ^= 1;
    lazy[n] = 0;
}

int query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);

    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

void update(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);

    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        lazy[n] ^= 1;
        lazy_update(n, s, e);
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r);
        update(n << 1 | 1, m + 1, e, l, r);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, T, A, B;
    cin >> N >> M;

    while (M--) {
        cin >> T >> A >> B;
        if (T == 0)
            update(1, 1, N, A, B);
        else
            cout << query(1, 1, N, A, B) << '\n';
    }

    return 0;
}