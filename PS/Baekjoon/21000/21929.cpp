#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

const int MAX = 100001;
const int INF = 800000000;

int SX, SY, X[MAX], Y[MAX], C[MAX], ans = INF,
                                    tree[3][3][MAX * 4];
vector<int> compX, compY;

void update(int t1, int t2, int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e) {
        if (v == INF)
            tree[t1][t2][n] = v;
        else
            tree[t1][t2][n] = min(tree[t1][t2][n], v);
    } else {
        int m = s + e >> 1;
        update(t1, t2, n << 1, s, m, x, v), update(t1, t2, n << 1 | 1, m + 1, e, x, v);
        tree[t1][t2][n] = min(tree[t1][t2][n << 1], tree[t1][t2][n << 1 | 1]);
    }
}

int query(int t1, int t2, int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return INF;
    else if (l <= s && e <= r)
        return tree[t1][t2][n];
    else {
        int m = s + e >> 1;
        return min(
            query(t1, t2, n << 1, s, m, l, r),
            query(t1, t2, n << 1 | 1, m + 1, e, l, r));
    }
}

void dnc(int l, int r, vector<int> &arr) { // [m, m + 1] 지나는 놈들 처리
    if (l == r) {
        vector<int> val[3];
        int K[3];

        sort(arr.begin(), arr.end(), [&](int x, int y) { return Y[x] < Y[y]; });
        for (int i : arr) {
            val[C[i]].push_back(compY[Y[i]]);
            if (val[0].empty() || val[1].empty() || val[2].empty())
                continue;
            K[0] = val[0].back(), K[1] = val[1].back(), K[2] = val[2].back();
            ans = min(ans, max({K[0], K[1], K[2]}) - min({K[0], K[1], K[2]}));
        }
        return;
    }

    int m = l + r >> 1, L, R;
    vector<int> larr, rarr;

    set<int> st[3];
    set<int>::iterator iter;

    for (int i : arr) {
        if (X[i] <= m)
            larr.push_back(i);
        else
            rarr.push_back(i);
    }

    dnc(l, m, larr), dnc(m + 1, r, rarr);
    reverse(larr.begin(), larr.end());

    for (int i : larr) {
        update(C[i], 0, 1, 0, SY - 1, Y[i], -compX[X[i]] + compY[Y[i]]);
        update(C[i], 1, 1, 0, SY - 1, Y[i], -compX[X[i]]);
        update(C[i], 2, 1, 0, SY - 1, Y[i], -compX[X[i]] - compY[Y[i]]);
    }

    for (int i : rarr) {
        st[C[i]].insert(Y[i]);
        for (int j = 0; j < 3; j++) {
            if (j == C[i])
                continue;
            iter = st[j].lower_bound(Y[i]);
            for (int k = 0; k < 2; k++) {
                if (k == 0) {
                    if (iter == st[j].end())
                        continue;
                    L = *iter;
                } else {
                    if (iter == st[j].begin())
                        continue;
                    L = *prev(iter);
                }
                R = Y[i];
                if (L > R)
                    swap(L, R);

                ans = min({ans,
                           compX[X[i]] + query(3 - C[i] - j, 0, 1, 0, SY - 1, R, SY - 1) - compY[L],
                           compX[X[i]] + query(3 - C[i] - j, 1, 1, 0, SY - 1, L, R) + compY[R] - compY[L],
                           compX[X[i]] + query(3 - C[i] - j, 2, 1, 0, SY - 1, 0, L) + compY[R]});
            }
        }
    }

    for (int i : larr)
        for (int j = 0; j < 3; j++)
            update(C[i], j, 1, 0, SY - 1, Y[i], INF);
    for (int i = 0; i < 3; i++)
        st[i].clear();

    for (int i : rarr) {
        update(C[i], 0, 1, 0, SY - 1, Y[i], compX[X[i]] + compY[Y[i]]);
        update(C[i], 1, 1, 0, SY - 1, Y[i], compX[X[i]]);
        update(C[i], 2, 1, 0, SY - 1, Y[i], compX[X[i]] - compY[Y[i]]);
    }

    for (int i : larr) {
        st[C[i]].insert(Y[i]);
        for (int j = 0; j < 3; j++) {
            if (j == C[i])
                continue;
            iter = st[j].lower_bound(Y[i]);
            for (int k = 0; k < 2; k++) {
                if (k == 0) {
                    if (iter == st[j].end())
                        continue;
                    L = *iter;
                } else {
                    if (iter == st[j].begin())
                        continue;
                    L = *prev(iter);
                }
                R = Y[i];
                if (L > R)
                    swap(L, R);

                ans = min({ans,
                           -compX[X[i]] + query(3 - C[i] - j, 0, 1, 0, SY - 1, R, SY - 1) - compY[L],
                           -compX[X[i]] + query(3 - C[i] - j, 1, 1, 0, SY - 1, L, R) + compY[R] - compY[L],
                           -compX[X[i]] + query(3 - C[i] - j, 2, 1, 0, SY - 1, 0, L) + compY[R]});
            }
        }
    }

    for (int i : rarr)
        for (int j = 0; j < 3; j++)
            update(C[i], j, 1, 0, SY - 1, Y[i], INF);
    for (int i = 0; i < 3; i++)
        st[i].clear();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i] >> C[i];
        compX.push_back(X[i]), compY.push_back(Y[i]);
    }

    sort(compX.begin(), compX.end()), compX.erase(unique(compX.begin(), compX.end()), compX.end()), SX = compX.size();
    sort(compY.begin(), compY.end()), compY.erase(unique(compY.begin(), compY.end()), compY.end()), SY = compY.size();

    for (int i = 0; i < SY; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                update(j, k, 1, 0, SY - 1, i, INF);

    for (int i = 1; i <= N; i++) {
        X[i] = lower_bound(compX.begin(), compX.end(), X[i]) - compX.begin();
        Y[i] = lower_bound(compY.begin(), compY.end(), Y[i]) - compY.begin();
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return X[x] < X[y]; });
    dnc(0, SX - 1, arr);

    cout << ans * 2 << '\n';

    return 0;
}