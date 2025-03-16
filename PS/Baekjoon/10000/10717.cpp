#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

const int MAX = 5000;

vector<int> row[MAX], column[MAX], val[MAX];
int st[MAX][MAX], en[MAX][MAX], tree[MAX * 4];

void init(int n, int s, int e) {
    tree[n] = 0;
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, H, W, L, P, X, Y, ans = 0;
    cin >> H >> W >> L >> P;

    while (P--) {
        cin >> X >> Y;
        row[X].push_back(Y), column[Y].push_back(X);
    }

    for (int i = 1; i <= H; i++) {
        row[i].push_back(0), row[i].push_back(W + 1);
        sort(row[i].begin(), row[i].end());
    }
    for (int i = 1; i <= W; i++) {
        column[i].push_back(0), column[i].push_back(H + 1);
        sort(column[i].begin(), column[i].end());
    }

    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++) {
            st[i][j] = min(*lower_bound(row[i].begin(), row[i].end(), j) - j, *lower_bound(column[j].begin(), column[j].end(), i) - i);
            en[i][j] = min(j - *prev(upper_bound(row[i].begin(), row[i].end(), j)), i - *prev(upper_bound(column[j].begin(), column[j].end(), i)));
            if (st[i][j] <= 2)
                st[i][j] = 0;
            if (en[i][j] <= 2)
                en[i][j] = 0;
        }

    for (int i = 2 - W; i <= H; i++) {
        for (int j = 1; j <= W; j++)
            val[j].clear();
        init(1, 1, W);

        for (int j = 1; j <= W; j++) {
            if (i + j - 1 <= 0 || i + j - 1 > H || en[i + j - 1][j] == 0)
                continue;
            val[j - en[i + j - 1][j] + 1].push_back(j);
        }

        for (int j = 1; j <= W; j++) {
            for (int k : val[j])
                update(1, 1, W, k, 1);
            if (i + j - 1 <= 0 || i + j - 1 > H || st[i + j - 1][j] == 0)
                continue;
            ans += query(1, 1, W, j + L - 1, j + st[i + j - 1][j] - 1);
        }
    }

    cout << ans << '\n';

    return 0;
}