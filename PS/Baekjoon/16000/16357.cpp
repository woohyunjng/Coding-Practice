#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int tree[MAX * 4], lazy[MAX * 4], L[MAX], R[MAX], in[MAX];
vector<int> out[MAX];

void lazy_update(int n, int s, int e) {
    if (!lazy[n])
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
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, S, ans = 0;
    vector<int> comp;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X >> L[i] >> Y >> R[i], swap(L[i], R[i]);
        comp.push_back(L[i]), comp.push_back(R[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 0; i < N; i++) {
        L[i] = lower_bound(comp.begin(), comp.end(), L[i]) - comp.begin() + 1;
        R[i] = lower_bound(comp.begin(), comp.end(), R[i]) - comp.begin() + 1;
        in[L[i]]++, out[R[i] + 1].push_back(L[i]);
    }

    X = 0;
    for (int i = 1; i <= S; i++) {
        X += in[i] - (int)out[i].size();
        for (int j : out[i])
            update(1, 1, S, j, i - 1, 1);
        ans = max(ans, X + query(1, 1, S, 1, i));
    }

    cout << ans << '\n';

    return 0;
}