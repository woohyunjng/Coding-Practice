#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 200'001;
const int INF = 1e9;

int N, A[MAX], dp[MAX],
    min_suf[MAX], max_suf[MAX], min_pre[MAX], max_pre[MAX],
    V[4][MAX], tree[4][MAX * 4];

int query(int t, int l, int r) {
    int res = INF;
    for (l += (N << 1) - 1, r += (N << 1); l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = min(res, tree[t][l++]);
        if (r & 1)
            res = min(res, tree[t][--r]);
    }
    return res;
}

void update(int t, int x, int v) {
    for (tree[t][x += (N << 1) - 1] = v; x > 1; x >>= 1)
        tree[t][x >> 1] = min(tree[t][x], tree[t][x ^ 1]);
}

void dnc(int l, int r) {
    if (l == r) {
        dp[l] = min(dp[l], dp[l - 1] + 1);
        return;
    }

    int m = l + r >> 1, T_0 = m, T_1 = m;
    vector<pr> comp;

    dnc(l, m);

    for (int i = m; i >= l; i--) {
        min_suf[i] = min(i == m ? INF : min_suf[i + 1], A[i]);
        max_suf[i] = max(i == m ? 0 : max_suf[i + 1], A[i]);

        V[0][i] = i + max_suf[i] - min_suf[i] - 1, V[1][i] = i;
        V[2][i] = i + max_suf[i], V[3][i] = i - min_suf[i];
    }

    for (int i = m + 1; i <= r; i++) {
        min_pre[i] = min(i == m + 1 ? INF : min_pre[i - 1], A[i]);
        max_pre[i] = max(i == m + 1 ? 0 : max_pre[i - 1], A[i]);

        V[0][i] = i, V[1][i] = i - max_pre[i] + min_pre[i] + 1;
        V[2][i] = i + min_pre[i] + 1, V[3][i] = i - max_pre[i] + 1;
    }

    for (int i = 0; i < 4; i++) {
        comp.clear();
        for (int j = l; j <= m; j++)
            comp.push_back({V[i][j], j});
        for (int j = m + 1; j <= r; j++)
            comp.push_back({V[i][j], N + 1});

        sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
        for (int j = l; j <= m; j++)
            V[i][j] = lower_bound(comp.begin(), comp.end(), pr{V[i][j], j}) - comp.begin() + 1;
        for (int j = m + 1; j <= r; j++)
            V[i][j] = lower_bound(comp.begin(), comp.end(), pr{V[i][j], N + 1}) - comp.begin() + 1;
    }

    for (int j = l; j <= m; j++)
        update(0, V[0][j], dp[j - 1] + 1);

    for (int i = m + 1; i <= r; i++) {
        while (T_0 >= l && ((min_suf[T_0] >= min_pre[i]) || (max_suf[T_0] <= max_pre[i])))
            update(0, V[0][T_0], INF), update(2, V[2][T_0], dp[T_0 - 1] + 1), update(3, V[3][T_0], dp[T_0 - 1] + 1), T_0--;
        while (T_1 >= l && min_suf[T_1] >= min_pre[i] && max_suf[T_1] <= max_pre[i])
            update(1, V[1][T_1], dp[T_1 - 1] + 1), update(2, V[2][T_1], INF), update(3, V[3][T_1], INF), T_1--;
        assert(T_0 <= T_1);

        for (int j = 0; j < 4; j++) {
            if (j == 2 && (T_0 == T_1 || min_suf[T_1] < min_pre[i]))
                continue;
            if (j == 3 && (T_0 == T_1 || min_suf[T_1] >= min_pre[i]))
                continue;
            dp[i] = min(dp[i], query(j, 1, V[j][i]));
        }
    }

    for (int i = 0; i < 4; i++)
        for (int j = l; j <= r; j++)
            update(i, V[i][j], INF);

    dnc(m + 1, r);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], dp[i] = INF;

    for (int i = 0; i < 4; i++)
        for (int j = 1; j < (N << 2); j++)
            tree[i][j] = INF;

    dnc(1, N);

    cout << dp[N] << '\n';

    return 0;
}