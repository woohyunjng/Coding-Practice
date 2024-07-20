#include <bits/stdc++.h>
#define int unsigned int

using namespace std;
typedef pair<int, int> pr;

class LazyPropagation {
  private:
    vector<int> tree, lazy_mul, lazy_sum;
    int N;

    void update_cal(int n, int mul, int sum) {
        lazy_mul[n] *= mul;
        lazy_sum[n] = lazy_sum[n] * mul + sum;
    }

    void lazy_update(int n, int s, int e) {
        if (lazy_mul[n] == 1 && lazy_sum[n] == 0)
            return;
        tree[n] = tree[n] * lazy_mul[n] + (e - s + 1) * lazy_sum[n];
        if (s != e) {
            update_cal(n << 1, lazy_mul[n], lazy_sum[n]);
            update_cal(n << 1 | 1, lazy_mul[n], lazy_sum[n]);
        }
        lazy_mul[n] = 1;
        lazy_sum[n] = 0;
    }

    int query(int n, int s, int e, int l, int r) {
        lazy_update(n, s, e);
        if (l <= s && e <= r)
            return tree[n];
        if (r < s || e < l)
            return 0;
        int mid = (s + e) >> 1;
        return query(n << 1, s, mid, l, r) + query(n << 1 | 1, mid + 1, e, l, r);
    }

    void update(int n, int s, int e, int l, int r, int mul, int sum) {
        lazy_update(n, s, e);
        if (r < s || e < l)
            return;
        if (l <= s && e <= r) {
            update_cal(n, mul, sum);
            lazy_update(n, s, e);
        } else {
            int mid = (s + e) >> 1;
            update(n << 1, s, mid, l, r, mul, sum);
            update(n << 1 | 1, mid + 1, e, l, r, mul, sum);
            tree[n] = tree[n << 1] + tree[n << 1 | 1];
        }
    }

  public:
    LazyPropagation(int n) : N(n) {
        tree.resize(4 * N);
        lazy_mul.resize(4 * N, 1);
        lazy_sum.resize(4 * N, 0);
    }

    int query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int l, int r, int m, int s) { update(1, 1, N, l, r, m, s); }
};

class LazyHLD {
  private:
    int pv;
    vector<int> parent, depth, sz, top, in, out;
    vector<bool> checked;
    vector<vector<int>> arr, child;
    LazyPropagation seg;

    void dfs(int cur) {
        in[cur] = ++pv;
        for (int i : child[cur]) {
            top[i] = (i == child[cur][0]) ? top[cur] : i;
            dfs(i);
        }
        out[cur] = pv;
    }

  public:
    LazyHLD(int n, int rt = 1) : N(n), root(rt), pv(0), seg(n) {
        arr.resize(N + 1);
        child.resize(N + 1);
        parent.resize(N + 1);
        depth.resize(N + 1);
        sz.resize(N + 1);
        top.resize(N + 1);
        in.resize(N + 1);
        out.resize(N + 1);
        checked.resize(N + 1, false);
    }

    void add_edge(int u, int v) {
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    void build_tree() {
        queue<int> q;
        stack<int> st;

        q.push(root);
        checked[root] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
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
            int cur = st.top();
            st.pop();
            sz[cur] = 1;
            for (int &i : child[cur]) {
                sz[cur] += sz[i];
                if (sz[i] > sz[child[cur][0]])
                    swap(i, child[cur][0]);
            }
        }

        dfs(root);
    }

    void update(int u, int v, int m, int s) {
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]])
                swap(u, v);
            seg.update(in[top[u]], in[u], m, s);
            u = parent[top[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        seg.update(in[u], in[v], m, s);
    }

    void update_sub(int pos, int m, int s) {
        seg.update(in[pos], out[pos], m, s);
    }

    int query(int u, int v) {
        int res = 0;
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]])
                swap(u, v);
            res += seg.query(in[top[u]], in[u]);
            u = parent[top[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        res += seg.query(in[u], in[v]);
        return res;
    }

    int query_sub(int pos) {
        return seg.query(in[pos], out[pos]);
    }

  private:
    int N, root;
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    LazyHLD hld(N);

    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        hld.add_edge(A, B);
    }

    hld.build_tree();

    while (Q--) {
        int A, B, C, D;
        cin >> A >> B;
        if (A != 5)
            cin >> C;
        if (A == 2 || A == 4)
            cin >> D;

        if (A == 1)
            hld.update_sub(B, 1, C);
        else if (A == 2)
            hld.update(B, C, 1, D);
        else if (A == 3)
            hld.update_sub(B, C, 0);
        else if (A == 4)
            hld.update(B, C, D, 0);
        else if (A == 5)
            cout << hld.query_sub(B) << '\n';
        else
            cout << hld.query(B, C) << '\n';
    }

    return 0;
}
