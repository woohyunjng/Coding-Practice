#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 300000;

vector<int> arr[MAX];
int X[MAX], Y[MAX], C[MAX], tree[MAX * 4], lazy[MAX * 4], S = 250000;
multiset<int> st[MAX];

void init(int n, int s, int e) {
    tree[n] = lazy[n] = 0;
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
        return max(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
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

pr get(int X, int Y, int L) {
    set<int>::iterator iter;
    pr res = {max(1ll, Y - L), Y};
    int K;

    iter = st[X].lower_bound(Y);
    if (iter != st[X].begin()) {
        iter = prev(iter), K = *iter;
        res[0] = max(res[0], K + 1);
    }

    iter = st[X].lower_bound(Y);
    if (iter != st[X].end()) {
        K = *iter;
        res[1] = min(res[1], K - L - 1);
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, bg, en, mid, ans;
    pr V;
    bool flag;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i] >> C[i];
        arr[X[i]].push_back(i);
    }

    bg = 0, en = S, ans = S;
    while (bg <= en) {
        mid = bg + en >> 1, flag = false;
        init(1, 1, S);
        for (int i = 1; i <= K; i++)
            st[i].clear();

        for (int i = 1; i <= S; i++) {
            if (i - mid - 1 >= 1)
                for (int j : arr[i - mid - 1])
                    st[C[j]].erase(st[C[j]].lower_bound(Y[j])), V = get(C[j], Y[j], mid), update(1, 1, S, V[0], V[1], -1);
            for (int j : arr[i])
                V = get(C[j], Y[j], mid), update(1, 1, S, V[0], V[1], 1), st[C[j]].insert(Y[j]);
            flag |= query(1, 1, S, 1, S) == K;
        }

        if (flag)
            en = mid - 1, ans = mid;
        else
            bg = mid + 1;
    }

    cout << ans << '\n';

    return 0;
}