#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;

int D[MAX], DX[MAX], X[MAX], P[MAX], ans[MAX], tree[MAX * 4][2];

int query(int n, int s, int e, int x) {
    if (s == e)
        return s;
    else {
        int m = s + e >> 1;
        if (tree[n << 1 | 1][0] >= x)
            return query(n << 1 | 1, m + 1, e, x);
        else
            return query(n << 1, s, m, x - tree[n << 1 | 1][0]);
    }
}

int sm(int n, int t, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n][t];
    else {
        int m = s + e >> 1;
        return sm(n << 1, t, s, m, l, r) + sm(n << 1 | 1, t, m + 1, e, l, r);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n][0] += v, tree[n][1] += 1;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n][0] = tree[n << 1][0] + tree[n << 1 | 1][0];
        tree[n][1] = tree[n << 1][1] + tree[n << 1 | 1][1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, C = 0, K;
    vector<int> arr, comp;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> D[i], comp.push_back(i);

    sort(comp.begin(), comp.end(), [&](int x, int y) { return D[x] == D[y] ? x < y : D[x] < D[y]; });
    for (int i = 1; i <= N; i++)
        DX[comp[i - 1]] = i;

    for (int i = 1; i <= Q; i++)
        cin >> X[i] >> P[i], arr.push_back(i);
    sort(arr.begin(), arr.end(), [&](int x, int y) { return X[x] < X[y]; });

    for (int i : arr) {
        while (C + 1 <= X[i])
            C++, update(1, 1, N, DX[C], D[C]);
        K = query(1, 1, N, P[i]);
        if (sm(1, 0, 1, N, K, N) < P[i])
            ans[i] = -1;
        else
            ans[i] = sm(1, 1, 1, N, K, N);
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}