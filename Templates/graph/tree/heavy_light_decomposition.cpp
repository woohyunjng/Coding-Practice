class HLD {
  private:
    int pv;
    vector<bool> checked;

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

    vector<vector<int>> arr, child;
    vector<int> parent, depth, sz, top, in, out, val;
    int N, root;

    HLD(int n, int rt = 1) : N(n), pv(0), seg(n), root(rt), arr(n + 1), child(n + 1), parent(n + 1), depth(n + 1), sz(n + 1), top(n + 1), in(n + 1), out(n + 1), val(n + 1), checked(n + 1) {}

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
                sz[cur] += sz[child[cur][i]];
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
            res = res + seg.query(in[top[u]], in[u]);
            u = parent[top[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        res = res + seg.query(in[u] + 1, in[v]);
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

class LazyHLD {
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
    LazyPropagition seg;

    vector<int> arr[MAX], child[MAX];
    int N, root, parent[MAX], depth[MAX], sz[MAX], top[MAX], in[MAX], out[MAX], val[MAX];

    LazyHLD(int n, int rt = 1) : N(n), pv(0), seg(n), root(rt) {}

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
                sz[cur] += sz[child[cur[i]]];
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

    void update(int u, int v, int val) {
        while (top[u] ^ top[v]) {
            if (depth[top[u]] < depth[top[v]])
                swap(u, v);
            seg.update(in[top[u]], in[u], val);
            u = parent[top[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        seg.update(in[u] + 1, in[v], val);
    }

    void update_sub(int pos, int val) {
        seg.update(in[pos], out[pos], val);
    }

    int query(int u, int v) {
        int res = 0;
        while (top[u] ^ top[v]) {
            if (depth[top[u]] < depth[top[v]])
                swap(u, v);
            res = res + seg.query(in[top[u]], in[u]);
            u = parent[top[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        res = res + seg.query(in[u] + 1, in[v]);
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