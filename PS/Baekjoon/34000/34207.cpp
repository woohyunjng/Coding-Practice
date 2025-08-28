#include <bits/stdc++.h>
using namespace std;

const int MAX = 400001;

int S[MAX], C[MAX], tree[MAX * 4], lazy[MAX * 4];

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
        return max(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

void update(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n]++, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r), update(n << 1 | 1, m + 1, e, l, r);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans;
    vector<int> comp;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S[i] >> C[i], S[i]--;
        comp.push_back(S[i]), comp.push_back(C[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), K = comp.size();
    for (int i = 1; i <= N; i++) {
        C[i] = lower_bound(comp.begin(), comp.end(), C[i]) - comp.begin() + 1;
        S[i] = lower_bound(comp.begin(), comp.end(), S[i]) - comp.begin() + 1;

        update(1, 1, K, C[i], S[i]), ans = query(1, 1, K, 1, K);
        cout << ans << '\n';
    }

    return 0;
}