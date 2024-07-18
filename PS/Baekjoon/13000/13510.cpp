#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class SegTree {
  public:
    int N, arr[MAX];
    int tree[2 * MAX + 1];

    SegTree(int n) : N(n) {}

    void init() {
        for (int i = 1; i <= N; i++)
            tree[i + N - 1] = arr[i];

        for (int i = N - 1; i > 0; --i)
            tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }

    int query(int l, int r) {
        int res = 0;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = max(res, tree[l++]);
            if (r & 1)
                res = max(res, tree[--r]);
        }
        return res;
    }

    void update(int pos, int val) {
        for (tree[pos += N - 1] = val; pos > 1; pos >>= 1)
            tree[pos >> 1] = max(tree[pos], tree[pos ^ 1]);
    }
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
            res = max(res, seg.query(in[top[u]], in[u]));
            u = parent[top[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        res = max(res, seg.query(in[u] + 1, in[v]));
        return res;
    }
};

tp edges[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C, cur, X, Y;
    cin >> N;

    HLD hld(N);

    for (int i = 1; i <= N - 1; i++) {
        cin >> A >> B >> C;
        hld.add_edge(A, B);
        edges[i] = {A, B, C};
    }

    hld.build_tree();
    for (int i = 1; i <= N - 1; i++) {
        if (hld.depth[edges[i][0]] > hld.depth[edges[i][1]])
            swap(edges[i][0], edges[i][1]);
        hld.set_node(edges[i][1], edges[i][2]);
    }
    hld.build_seg();

    cin >> M;
    while (M--) {
        cin >> A >> B >> C;
        if (A == 1) {
            X = edges[B][0], Y = edges[B][1];
            if (hld.depth[X] > hld.depth[Y])
                swap(X, Y);
            hld.update(Y, C);
        } else
            cout << (B ^ C ? hld.query(B, C) : 0) << "\n";
    }

    return 0;
}