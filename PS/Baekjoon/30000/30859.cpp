#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 20001;

int A[MAX], B[MAX], tree[MAX * 4], lazy[MAX * 4];

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
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
        return max(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
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
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, V;
    vector<pr> arr;
    vector<int> comp;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++) {
        cin >> B[i], comp.push_back(B[i]);
        arr.push_back({A[i], B[i]});
    }

    sort(arr.begin(), arr.end());
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i = 1; i <= N; i++)
        A[i] = arr[i - 1][0], B[i] = lower_bound(comp.begin(), comp.end(), arr[i - 1][1]) - comp.begin();

    for (int i = 1; i <= N; i++) {
        V = query(1, 0, N - 1, 0, B[i] - 1) + A[i] + comp[B[i]], Y = max(A[i], comp[B[i]]);
        update(1, 0, N - 1, B[i], B[i], -query(1, 0, N - 1, B[i], B[i]) + V);
        update(1, 0, N - 1, 0, B[i] - 1, Y), update(1, 0, N - 1, B[i] + 1, N - 1, Y);
    }

    cout << query(1, 0, N - 1, 0, N - 1) << '\n';

    return 0;
}