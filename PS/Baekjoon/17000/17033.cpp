#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class SegTree {
  public:
    int N;
    vector<int> arr, tree;

    SegTree(int n) : N(n), arr(n + 1), tree(n * 2 + 1) {}

    void init() {
        for (int i = 1; i <= N; i++)
            tree[i + N - 1] = arr[i];

        for (int i = N - 1; i > 0; --i)
            tree[i] = tree[i << 1] ^ tree[i << 1 | 1];
    }

    int query(int l, int r) {
        int res = 0;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = res ^ tree[l++];
            if (r & 1)
                res = res ^ tree[--r];
        }
        return res;
    }

    void update(int pos, int val) {
        for (tree[pos += N - 1] = val; pos > 1; pos >>= 1)
            tree[pos >> 1] = tree[pos] ^ tree[pos ^ 1];
    }
};

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
            res = res ^ seg.query(in[top[u]], in[u]);
            u = parent[top[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        res = res ^ seg.query(in[u], in[v]);
        return res;
    }
};

vector<int> adj[MAX];
int E[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, T;
    cin >> N >> Q;

    HLD hld(N);

    for (int i = 1; i <= N; i++)
        cin >> X, hld.set_node(i, X);

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        hld.add_edge(X, Y);
    }

    hld.build_tree();
    hld.build_seg();

    while (Q--) {
        cin >> T >> X >> Y;
        if (T == 1)
            hld.update(X, Y);
        else
            cout << hld.query(X, Y) << '\n';
    }

    return 0;
}