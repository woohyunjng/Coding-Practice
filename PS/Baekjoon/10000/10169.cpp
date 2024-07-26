#include <bits/stdc++.h>
#define int long long
#define MAX 300100

using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> pr;
typedef array<int, 4> tp;

class LazyPropagition {
  private:
    void lazy_update(int n, int s, int e) {
        if (lazy[n] < INF) {
            tree[n] = min(tree[n], lazy[n]);
            if (s != e) {
                lazy[n << 1] = min(lazy[n << 1], lazy[n]);
                lazy[n << 1 | 1] = min(lazy[n << 1 | 1], lazy[n]);
            }
        }
    }

    int query(int n, int s, int e, int l, int r) {
        lazy_update(n, s, e);
        if (l <= s && e <= r)
            return tree[n];
        else if (r < s || e < l)
            return INF;
        else {
            int m = (s + e) >> 1;
            int lv = query(n << 1, s, m, l, r);
            int rv = query(n << 1 | 1, m + 1, e, l, r);
            return min(lv, rv);
        }
    }

    void update(int n, int s, int e, int l, int r, int val) {
        lazy_update(n, s, e);
        if (r < s || e < l)
            return;
        else if (l <= s && e <= r) {
            lazy[n] = min(lazy[n], val);
            lazy_update(n, s, e);
        } else {
            int m = (s + e) >> 1;
            update(n << 1, s, m, l, r, val);
            update(n << 1 | 1, m + 1, e, l, r, val);
            tree[n] = min(tree[n << 1], tree[n << 1 | 1]);
        }
    }

  public:
    int N;
    vector<int> tree, lazy;

    LazyPropagition(int n) : N(n), tree(4 * n + 1, INF), lazy(4 * n + 1, INF) {}

    int query(int pos) { return query(1, 1, N, pos, pos); }
    int query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int l, int r, int val) { update(1, 1, N, l, r, val); }
};

class LazyHLD {
  private:
    int pv;
    vector<bool> checked;

    void dfs(int cur) {
        in[cur] = ++pv;
        for (int i : child[cur]) {
            top[i] = i == child[cur][0] ? top[cur] : i;
            dfs(i);
        }
        out[cur] = pv;
    }

  public:
    LazyPropagition seg;

    vector<vector<int>> arr, child;
    vector<int> parent, depth, sz, top, in, out, val;
    int N, root;

    LazyHLD(int n, int rt = 1) : N(n), pv(0), seg(n), root(rt), arr(n + 1), child(n + 1), parent(n + 1), depth(n + 1), sz(n + 1), top(n + 1), in(n + 1), out(n + 1), val(n + 1), checked(n + 1) {}

    void add_edge(int u, int v) {
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    void build_tree() {
        int cur;

        queue<int> q;
        stack<int> st;

        q.push(root);
        checked[root] = true;

        while (!q.empty()) {
            cur = q.front(), q.pop();
            st.push(cur);

            for (int i : arr[cur]) {
                if (checked[i])
                    continue;
                checked[i] = true;
                parent[i] = cur;
                depth[i] = depth[cur] + 1;
                child[cur].push_back(i);
                q.push(i);
            }
        }

        while (!st.empty()) {
            cur = st.top(), st.pop();
            sz[cur] = 1;
            for (int i = 0; i < child[cur].size(); i++) {
                sz[cur] += sz[child[cur][i]];
                if (sz[child[cur][i]] > sz[child[cur][0]])
                    swap(child[cur][i], child[cur][0]);
            }
        }

        dfs(root);
    }

    void update(int u, int v, int val) {
        for (; top[u] ^ top[v]; u = parent[top[u]]) {
            if (depth[top[u]] < depth[top[v]])
                swap(u, v);
            seg.update(in[top[u]], in[u], val);
        }
        if (depth[u] > depth[v])
            swap(u, v);
        seg.update(in[u] + 1, in[v], val);
    }

    int query(int u, int v) {
        int res = INF;
        for (; top[u] ^ top[v]; u = parent[top[u]]) {
            if (depth[top[u]] < depth[top[v]])
                swap(u, v);
            res = min(res, seg.query(in[top[u]], in[u]));
        }
        if (depth[u] > depth[v])
            swap(u, v);
        res = min(res, seg.query(in[u] + 1, in[v]));
        return res;
    }
};

class UnionFind {
  private:
    vector<int> uf_parent;

  public:
    UnionFind(int N) : uf_parent(N + 1) { clear(N); }

    int find(int K) {
        if (uf_parent[K] != K)
            uf_parent[K] = find(uf_parent[K]);
        return uf_parent[K];
    }

    void uni(int A, int B) {
        A = find(A), B = find(B);
        if (A > B)
            swap(A, B);
        uf_parent[B] = A;
    }

    void clear(int N) {
        for (int i = 1; i <= N; i++)
            uf_parent[i] = i;
    }
};

vector<tp> arr, used_arr, unused_arr;
vector<int> res;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, M, A, B, C, sz = 0, K;
    cin >> N >> M;

    res.resize(M + 1);

    LazyHLD hld(N);
    UnionFind uf(N);

    for (int i = 1; i <= M; i++) {
        cin >> A >> B >> C;
        arr.push_back({C, A, B, i});
    }
    sort(arr.begin(), arr.end());

    for (tp i : arr) {
        C = i[0], A = i[1], B = i[2];
        if (uf.find(A) == uf.find(B)) {
            unused_arr.push_back(i);
            continue;
        }
        uf.uni(A, B);
        hld.add_edge(A, B);
        sz += C;
        used_arr.push_back(i);
    }

    hld.build_tree();

    for (tp i : unused_arr) {
        C = i[0], A = i[1], B = i[2];
        hld.update(A, B, C);
        res[i[3]] = sz;
    }

    for (tp i : used_arr) {
        C = i[0], A = i[1], B = i[2];
        if (hld.depth[A] < hld.depth[B])
            swap(A, B);

        K = hld.seg.query(hld.in[A]);
        if (K < INF)
            res[i[3]] = sz + K - C;
        else
            res[i[3]] = -1;
    }

    for (int i = 1; i <= M; i++)
        cout << res[i] << '\n';

    return 0;
}