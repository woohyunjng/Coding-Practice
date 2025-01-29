#include <bits/stdc++.h>
#define int long long

#define MAX 2000000
using namespace std;

typedef array<int, 3> tp;

int val[MAX], tree[MAX * 4];
unordered_map<int, int> par;

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e) {
        tree[n] += v;
        return;
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

int query(int n, int s, int e, int k) {
    assert(k <= tree[n]);
    if (s == e)
        return s;
    else {
        int m = s + e >> 1;
        if (k <= tree[n << 1])
            return query(n << 1, s, m, k);
        return query(n << 1 | 1, m + 1, e, k - tree[n << 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, R, S;
    vector<int> comp;
    vector<tp> queries;
    char C;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> C;
        if (C == 'N') {
            cin >> X >> R;
            queries.push_back({0, X, R}), comp.push_back(-R);
        } else if (C == 'M') {
            cin >> X >> R;
            queries.push_back({1, X, R}), comp.push_back(-R);
        } else {
            cin >> X;
            queries.push_back({2, X, 0});
        }
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = (int)comp.size();

    for (tp i : queries) {
        if (i[0] == 0) {
            X = i[1], R = lower_bound(comp.begin(), comp.end(), -i[2]) - comp.begin() + 1;
            val[X] = R, par[R] = X, update(1, 1, S, R, 1);
        } else if (i[0] == 1) {
            X = i[1], R = lower_bound(comp.begin(), comp.end(), -i[2]) - comp.begin() + 1;
            update(1, 1, S, val[X], -1), val[X] = R, par[R] = X, update(1, 1, S, R, 1);
        } else
            cout << par[query(1, 1, S, i[1])] << '\n';
    }

    return 0;
}