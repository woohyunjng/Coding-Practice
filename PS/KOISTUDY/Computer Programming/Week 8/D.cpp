#include <bits/stdc++.h>

#define int long long
#define double long double

using namespace std;

const int MAX = 400001;

int A[MAX], T[MAX], X[MAX], Y[MAX], tree[MAX * 4];

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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, Q, B, C;
    char PT;
    double D;

    vector<int> comp;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> B >> PT >> C, A[i] = B * 100 + C;
        comp.push_back(A[i]);
    }

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> T[i];
        if (T[i] == 1)
            cin >> X[i];
        else {
            cin >> X[i] >> B >> PT >> C, Y[i] = B * 100 + C;
            comp.push_back(Y[i]);
        }
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();

    for (int i = 1; i <= N; i++) {
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;
        update(1, 1, S, A[i], 1);
    }

    for (int i = 1; i <= Q; i++) {
        if (T[i] == 1)
            cout << query(1, 1, S, A[X[i]] + 1, S) + 1 << '\n';
        else {
            update(1, 1, S, A[X[i]], -1);
            A[X[i]] = lower_bound(comp.begin(), comp.end(), Y[i]) - comp.begin() + 1;
            update(1, 1, S, A[X[i]], 1);
        }
    }

    return 0;
}