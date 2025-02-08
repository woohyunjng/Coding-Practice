#include <bits/stdc++.h>
#define int long long

#define MAX 600000
using namespace std;

int P[MAX], ans[MAX], tree[MAX * 4];

int query(int n, int s, int e, int v) {
    if (s == e)
        return s;
    else {
        int m = s + e >> 1;
        if (tree[n << 1] >= v)
            return query(n << 1, s, m, v);
        else
            return query(n << 1 | 1, m + 1, e, v - tree[n << 1]);
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

    int N, K;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> P[i], update(1, 1, N, i, 1);

    for (int i = N; i >= 1; i--) {
        K = query(1, 1, N, P[i]);
        ans[K] = i, update(1, 1, N, K, -1);
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}