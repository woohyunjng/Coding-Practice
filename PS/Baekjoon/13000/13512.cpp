#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sm(int a, int b) {
    if (a == 0)
        return b;
    else
        return a;
}

class SegTree {
  private:
    void init(int n, int s, int e) {
        if (s == e)
            tree[n] = arr[s];
        else {
            init(n << 1, s, (s + e) >> 1);
            init(n << 1 | 1, ((s + e) >> 1) + 1, e);
            tree[n] = sm(tree[n << 1], tree[n << 1 | 1]);
        }
    }

    int query(int n, int s, int e, int l, int r) {
        if (l <= s && e <= r)
            return tree[n];
        else if (r < s || e < l)
            return 0;
        else {
            int lv = query(n << 1, s, ((s + e) >> 1), l, r);
            int rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
            return sm(lv, rv);
        }
    }

    void update(int n, int s, int e, int pos, int val) {
        if (pos < s || e < pos)
            return;
        else if (s == e) {
            tree[n] = val;
            arr[s] = val;
        } else {
            update(n << 1, s, (s + e) >> 1, pos, val);
            update(n << 1 | 1, ((s + e) >> 1) + 1, e, pos, val);
            tree[n] = sm(tree[n << 1], tree[n << 1 | 1]);
        }
    }

  public:
    int N, arr[MAX];
    int tree[4 * MAX + 1];

    SegTree(int n) : N(n) {}

    void init() { init(1, 1, N); }
    int query(int pos) { return query(1, 1, N, pos, pos); }
    int query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int pos, int val) { update(1, 1, N, pos, val); }
};

class HLD {
  private:
    int pv;
    bool checked[MAX];

    void dfs(int cur) {
        in[cur] = ++pv;
        seg.arr[pv] = val[cur];
        for (int i : child[cur]) {
            top[i] = i == child[cur][0] ? top[cur] : i;
            dfs(i);
        }
        out[cur] = pv;
    }

  public:
    SegTree seg;

    vector<int> arr[MAX], child[MAX];
    int N, root, parent[MAX], depth[MAX], sz[MAX], top[MAX], in[MAX], out[MAX], val[MAX];

    HLD(int n, int rt = 1) : N(n), pv(0), seg(n), root(rt) {}

    void add_edge(int u, int v) {
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    void set_node(int n, int v) {
        val[n] = v;
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
                sz[cur] += sz[i];
                if (sz[child[cur][i]] > sz[child[cur][0]])
                    swap(child[cur][i], child[cur][0]);
            }
        }

        dfs(root);
    }

    void build_seg() {
        for (int i = 1; i <= N; i++)
            seg.arr[in[i]] = val[i];
        seg.init();
    }

    void update(int pos, int val) {
        seg.update(in[pos], val);
    }

    int query(int u, int v) {
        int res = 0;
        while (top[u] ^ top[v]) {
            if (depth[top[u]] < depth[top[v]])
                swap(u, v);
            res = sm(seg.query(in[top[u]], in[u]), res);
            u = parent[top[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        res = sm(seg.query(in[u], in[v]), res);
        return res;
    }

    int lca(int u, int v) {
        while (top[u] ^ top[v]) {
            if (depth[top[u]] < depth[top[v]])
                swap(u, v);
            u = parent[top[u]];
        }
        return depth[u] < depth[v] ? u : v;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, X;

    cin >> N;
    HLD hld(N);

    for (int i = 1; i <= N - 1; i++) {
        cin >> A >> B;
        hld.add_edge(A, B);
    }

    for (int i = 1; i <= N; i++)
        hld.set_node(i, 0);
    hld.build_tree();
    hld.build_seg();

    cin >> M;
    while (M--) {
        cin >> A >> B;
        if (A == 1) {
            if (hld.query(B, B) == B)
                hld.update(B, 0);
            else
                hld.update(B, B);
        } else {
            X = hld.query(1, B);
            if (X == 0)
                X = -1;
            cout << X << "\n";
        }
    }
    return 0;
}