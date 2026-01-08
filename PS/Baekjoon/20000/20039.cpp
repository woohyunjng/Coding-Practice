#include <bits/stdc++.h>
using namespace std;

const int MAX = 500001;

int A[MAX], tree[6][MAX * 2], S;

void init(int t) {
    for (int i = 1; i <= S; i++)
        tree[t][i + S - 1] = -1e9;
    for (int i = S - 1; i > 0; i--)
        tree[t][i] = max(tree[t][i << 1], tree[t][i << 1 | 1]);
}

int query(int t, int l, int r) {
    int res = -1e9;
    for (l += S - 1, r += S; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = max(res, tree[t][l++]);
        if (r & 1)
            res = max(res, tree[t][--r]);
    }
    return res;
}

void update(int t, int x, int v) {
    x += S - 1, tree[t][x] = max(tree[t][x], v);
    for (; x > 1; x >>= 1)
        tree[t][x >> 1] = max(tree[t][x], tree[t][x ^ 1]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans;
    vector<int> comp;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back(A[i]);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 1; i <= N; i++)
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;

    for (int t = 0; t < 6; t++)
        init(t);

    for (int i = 1; i <= N; i++) {
        update(0, A[i], 1), update(3, A[i], 1);
        update(0, A[i], max(query(4, A[i] + 1, S), query(5, A[i] + 1, S)) + 1);
        update(1, A[i], query(0, 1, A[i] - 1) + 1);
        update(2, A[i], max(query(1, 1, A[i] - 1), query(2, 1, A[i] - 1)) + 1);
        update(3, A[i], max(query(1, 1, A[i] - 1), query(2, 1, A[i] - 1)) + 1);
        update(4, A[i], query(3, A[i] + 1, S) + 1);
        update(5, A[i], max(query(4, A[i] + 1, S), query(5, A[i] + 1, S)) + 1);
    }

    ans = max({0, query(2, 1, S), query(5, 1, S)});
    cout << ans << '\n';

    return 0;
}