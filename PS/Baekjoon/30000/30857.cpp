#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int L[MAX], R[MAX], dp[2][MAX],
    tree[MAX * 4], lazy[MAX * 4];
vector<int> in[MAX], out[MAX];

void init(int n, int s, int e) {
    lazy[n] = tree[n] = 0;
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    }
}

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

    int N, K, S, C;
    vector<int> comp;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        comp.push_back(L[i]), comp.push_back(R[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 1; i <= N; i++) {
        L[i] = lower_bound(comp.begin(), comp.end(), L[i]) - comp.begin() + 1;
        R[i] = lower_bound(comp.begin(), comp.end(), R[i]) - comp.begin() + 1;
        in[L[i]].push_back(i), out[R[i] + 1].push_back(i);
    }

    for (int i = 1; i <= K; i++) {
        init(1, 1, S), C = 0;
        for (int j = 1; j <= S; j++) {
            for (int k : in[j])
                C++;
            for (int k : out[j])
                C--, update(1, 1, S, L[k], R[k], 1);
            dp[i & 1][j] = query(1, 1, S, 1, j - 1) + C, update(1, 1, S, j, j, dp[(i & 1) ^ 1][j] - C);
        }
    }

    cout << *max_element(dp[K & 1] + 1, dp[K & 1] + S + 1) << '\n';

    return 0;
}