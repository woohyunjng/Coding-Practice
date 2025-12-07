#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 200001;

int uf[MAX], tree[MAX], ans[MAX];
set<int> st[MAX];
vector<pr> G[MAX], queries[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
int query(int x) {
    int ret = 0;
    for (x++; x > 0; x -= x & -x)
        ret += tree[x];
    return ret;
}
void update(int x, int v) {
    for (x++; x < MAX; x += x & -x)
        tree[x] += v;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, U, V, W, S = 0;
    pr K;

    vector<tp> arr;
    vector<pr> val;

    set<pr> hull;
    set<pr>::iterator hull_it;

    set<int>::iterator it;

    cin >> N >> M >> Q;
    for (int i = 0; i < N; i++)
        uf[i] = i, st[i].insert(i);

    for (int i = 0; i < M; i++) {
        cin >> U >> V >> W;
        arr.push_back({W, U, V});
    }
    sort(arr.begin(), arr.end());

    for (tp i : arr) {
        W = i[0], U = find(i[1]), V = find(i[2]);
        if (find(U) == find(V))
            continue;

        if (st[U].size() > st[V].size())
            swap(U, V);
        uf[U] = V, val.clear(), hull.clear(), S += W;

        for (int j : st[U]) {
            it = st[V].lower_bound(j);
            if (it != st[V].begin())
                val.push_back({*prev(it), j});
            if (it != st[V].end())
                val.push_back({j, *it});
        }
        for (int j : st[U])
            st[V].insert(j);
        st[U].clear(), sort(val.begin(), val.end(), [&](pr x, pr y) { return x[0] != y[0] ? x[0] < y[0] : x[1] > y[1]; });

        for (pr j : val) {
            while (!hull.empty() && (*prev(hull.end()))[1] >= j[1])
                hull.erase(prev(hull.end()));
            hull.insert(j);
        }
        K = {-1, -1};
        for (pr j : hull) {
            hull_it = hull.find(j);
            if (K[0] != -1)
                G[(*prev(hull_it))[0]].push_back({j[1], -W});
            G[j[0]].push_back({j[1], W}), K = j;
        }
    }

    for (int i = 1; i <= Q; i++)
        cin >> U >> V, queries[U].push_back({V, i});

    for (int i = N - 1; i >= 0; i--) {
        for (pr j : G[i])
            update(j[0], j[1]);
        for (pr j : queries[i])
            ans[j[1]] = query(j[0]);
    }

    for (int i = 1; i <= Q; i++)
        cout << S - ans[i] << '\n';

    return 0;
}