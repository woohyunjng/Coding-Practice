#include <bits/stdc++.h>
#define int long long

#define MAX 300100

using namespace std;
typedef pair<int, int> pr;

int L[MAX], R[MAX], tree[MAX * 4], lazy[MAX * 4], X[MAX], idx[MAX];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = X[s];
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

void lazy_propagate(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n] += lazy[n];
    if (s != e) {
        lazy[n << 1] += lazy[n];
        lazy[n << 1 | 1] += lazy[n];
    }
    lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r, int x) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return;
    if (l <= s && e <= r) {
        lazy[n] += x;
        lazy_propagate(n, s, e);
        return;
    }
    int m = s + e >> 1;
    update(n << 1, s, m, l, r, x), update(n << 1 | 1, m + 1, e, l, r, x);
    tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
}

int query(int n, int s, int e, int l, int r) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return 0;
    if (l <= s && e <= r)
        return tree[n];
    int m = s + e >> 1;
    return max(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, K, st, en, mid, l, r;
    vector<pr> arr;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> L[i] >> R[i];

    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> K, arr.push_back({K, i});
    sort(arr.begin(), arr.end());

    for (int i = 0; i < Q; i++) {
        idx[arr[i].second] = i + 1;
        X[i + 1] = arr[i].first;
    }
    init(1, 1, Q);

    for (int i = 1; i <= N; i++) {
        st = 1, en = Q, l = -1;
        while (st <= en) {
            mid = st + en >> 1;
            if (query(1, 1, Q, 1, mid) >= L[i])
                en = mid - 1, l = mid;
            else
                st = mid + 1;
        }

        st = 1, en = Q, r = -1;
        while (st <= en) {
            mid = st + en >> 1;
            if (query(1, 1, Q, 1, mid) <= R[i])
                st = mid + 1, r = mid;
            else
                en = mid - 1;
        }

        if (l != -1 && r != -1)
            update(1, 1, Q, l, r, 1);
    }

    for (int i = 1; i <= Q; i++)
        cout << query(1, 1, Q, idx[i], idx[i]) << '\n';

    return 0;
}