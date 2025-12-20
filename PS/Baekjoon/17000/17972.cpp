#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 4001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int L[MAX], R[MAX], dp[2][MAX], ans[MAX],
    tree[MAX * 4], lazy[MAX * 4];
vector<int> val[MAX];

void init(int t, int n, int s, int e) {
    lazy[n] = 0;
    if (s == e)
        tree[n] = dp[t][s];
    else {
        int m = s + e >> 1;
        init(t, n << 1, s, m), init(t, n << 1 | 1, m + 1, e);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
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

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] = v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return -INF;
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

    int N, S, X = 0;
    vector<int> comp;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        comp.push_back(L[i]), comp.push_back(R[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();

    for (int i = 0; i < N; i++) {
        L[i] = lower_bound(comp.begin(), comp.end(), L[i]) - comp.begin() + 1;
        R[i] = lower_bound(comp.begin(), comp.end(), R[i]) - comp.begin() + 1;
        val[R[i]].push_back(L[i]);
    }

    fill(dp[0] + 1, dp[0] + S + 1, -INF);
    for (int i = 1; i <= N; i++) {
        init(i & 1 ^ 1, 1, 0, S), X = 0;
        fill(dp[i & 1], dp[i & 1] + S + 1, -INF);
        for (int j = 1; j <= S; j++) {
            for (int k : val[j])
                X = max(X, k), update(1, 0, S, 0, k - 1, 1);
            dp[i & 1][j] = max(dp[i & 1][j - 1], query(1, 0, S, 0, X - 1));
        }
        for (int j = N - dp[i & 1][S]; j <= N - i; j++)
            ans[j] = max(ans[j], i);
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}