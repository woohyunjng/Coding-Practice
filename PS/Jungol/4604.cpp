#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 400000;

int A[MAX], tree[MAX * 4], lazy[MAX * 4];

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] += v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = min(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return MAX;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return min(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, V = 0;
    vector<int> comp;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back(A[i]);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 1; i <= N; i++)
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;

    for (int i = N; i >= 1; i--) {
        update(1, 1, S, A[i] + 1, S, 1);
        V += query(1, 1, S, A[i], A[i]);
    }

    for (int i = 1; i <= N; i++) {
        update(1, 1, S, A[i] + 1, S, -1);
        cout << V - query(1, 1, S, A[i], A[i]) + query(1, 1, S, 1, S) << ' ';
        update(1, 1, S, 1, A[i] - 1, 1);
    }
    cout << '\n';

    return 0;
}