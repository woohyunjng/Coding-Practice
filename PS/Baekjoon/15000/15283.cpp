#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int tree[MAX * 4],
    T[MAX], X[MAX], Y[MAX], V[MAX];

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
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

    int N, S, K;
    vector<int> comp;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> X[i] >> Y[i];
        comp.push_back(X[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
    S = comp.size();

    for (int i = 1; i <= N; i++) {
        X[i] = lower_bound(comp.begin(), comp.end(), X[i]) - comp.begin();

        if (T[i] == 1) {
            V[X[i]] = i, update(1, 0, S - 1, X[i], Y[i] * 2);
        } else {
            K = -1;
            for (int st = 0, en = X[i], md; st <= en;) {
                md = st + en >> 1;
                if (query(1, 0, S - 1, md, X[i]) >= Y[i])
                    st = md + 1, K = md;
                else
                    en = md - 1;
            }

            if (K != -1 && (comp[X[V[K]]] - comp[X[i]]) * (comp[X[V[K]]] - comp[X[i]]) + (Y[V[K]] - Y[i]) * (Y[V[K]] - Y[i]) < Y[V[K]] * Y[V[K]]) {
                cout << V[K] << '\n', V[K] = 0;
                update(1, 0, S - 1, K, 0);
                continue;
            }

            K = -1;
            for (int st = X[i], en = S - 1, md; st <= en;) {
                md = st + en >> 1;
                if (query(1, 0, S - 1, X[i], md) >= Y[i])
                    en = md - 1, K = md;
                else
                    st = md + 1;
            }

            if (K != -1 && (comp[X[V[K]]] - comp[X[i]]) * (comp[X[V[K]]] - comp[X[i]]) + (Y[V[K]] - Y[i]) * (Y[V[K]] - Y[i]) < Y[V[K]] * Y[V[K]]) {
                cout << V[K] << '\n', V[K] = 0;
                update(1, 0, S - 1, K, 0);
                continue;
            }

            cout << -1 << '\n';
        }
    }

    return 0;
}