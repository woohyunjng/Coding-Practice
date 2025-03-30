#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct Line {
    int A, B, num;
    int get(int X) { return A * X + B; }

    Line(int A, int B, int num) : A(A), B(B), num(num) {}
};

struct Node {
    int s, e, l = -1, r = -1;
    Line line;

    Node(int s, int e, Line line) : s(s), e(e), line(line) {}
};

vector<pr> adj[MAX];

int V[MAX], ans[MAX], sz[MAX];
bool vst[MAX];

vector<Node> tree;

void clear() {
    tree.clear();
    tree.push_back(Node(1, 1'000'000, Line(0, INF, -1)));
}

void update(int n, Line v) {
    int s = tree[n].s, e = tree[n].e, m = s + e >> 1;
    Line low = tree[n].line, high = v;

    if (low.get(s) > high.get(s))
        swap(low, high);
    if (low.get(e) <= high.get(e)) {
        tree[n].line = low;
        return;
    }

    if (low.get(m) < high.get(m)) {
        tree[n].line = low;
        if (tree[n].r == -1) {
            tree[n].r = tree.size();
            tree.push_back(Node(m + 1, e, Line(0, INF, -1)));
        }
        update(tree[n].r, high);
    } else {
        tree[n].line = high;
        if (tree[n].l == -1) {
            tree[n].l = tree.size();
            tree.push_back(Node(s, m, Line(0, INF, -1)));
        }
        update(tree[n].l, low);
    }
}

int query(int n, int v) {
    if (n == -1)
        return INF;
    int s = tree[n].s, e = tree[n].e, m = s + e >> 1;

    if (v <= m)
        return min(tree[n].line.get(v), query(tree[n].l, v));
    return min(tree[n].line.get(v), query(tree[n].r, v));
}

int get_sz(int node, int par) {
    sz[node] = 1;
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        sz[node] += get_sz(i[0], node);
    }
    return sz[node];
}

int get_cent(int node, int par, int cap) {
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        if (sz[i[0]] * 2 > cap)
            return get_cent(i[0], node, cap);
    }
    return node;
}

void dfs1(int node, int par, int len) {
    ans[node] = min(ans[node], query(0, V[node]) + len);
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        dfs1(i[0], node, len + i[1]);
    }
}

void dfs2(int node, int par, int len) {
    update(0, Line(V[node], len, node));
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        dfs2(i[0], node, len + i[1]);
    }
}

void divide_and_conquer(int node) {
    int cent = get_cent(node, -1, get_sz(node, -1));
    vst[cent] = true;

    clear(), update(0, Line(V[cent], 0, cent));

    for (pr i : adj[cent]) {
        if (vst[i[0]])
            continue;
        dfs1(i[0], cent, i[1]), dfs2(i[0], cent, i[1]);
    }
    ans[cent] = min(ans[cent], query(0, V[cent]));

    clear(), update(0, Line(V[cent], 0, cent));
    reverse(adj[cent].begin(), adj[cent].end());

    for (pr i : adj[cent]) {
        if (vst[i[0]])
            continue;
        dfs1(i[0], cent, i[1]), dfs2(i[0], cent, i[1]);
    }

    for (pr i : adj[cent]) {
        if (vst[i[0]])
            continue;
        divide_and_conquer(i[0]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, Z;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> V[i], ans[i] = V[i] * V[i];

    for (int i = 1; i < N; i++) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z}), adj[Y].push_back({X, Z});
    }

    divide_and_conquer(1);

    cout << accumulate(ans + 1, ans + N + 1, 0ll) << '\n';

    return 0;
}