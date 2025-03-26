#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 100010;
const int INF = 1'000'000'000;

struct Line {
    int A, B;
    int get(int X) { return A * X + B; }

    Line(int A, int B) : A(A), B(B) {}
};

struct Node {
    int s, e, l = -1, r = -1;
    Line line;

    Node(int s, int e, Line line) : s(s), e(e), line(line) {}
};

int S[MAX], V[MAX], depth[MAX], dp[MAX];
vector<pr> adj[MAX];

vector<Node> tree;
vector<vector<pair<int, Line>>> st;

void update(int n, Line v) {
    st.back().push_back({n, tree[n].line});

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
            tree.push_back(Node(m + 1, e, Line(0, INF)));
        }
        update(tree[n].r, high);
    } else {
        tree[n].line = high;
        if (tree[n].l == -1) {
            tree[n].l = tree.size();
            tree.push_back(Node(s, m, Line(0, INF)));
        }
        update(tree[n].l, low);
    }
}

int query(int n, int x) {
    if (n == -1)
        return INF;
    int s = tree[n].s, e = tree[n].e, m = s + e >> 1;

    if (x <= m)
        return min(tree[n].line.get(x), query(tree[n].l, x));
    return min(tree[n].line.get(x), query(tree[n].r, x));
}

void rollback() {
    for (pair<int, Line> i : st.back())
        tree[i.first].line = i.second;
    st.pop_back();
}

void dfs(int node, int par) {
    if (node != 1)
        dp[node] = S[node] + V[node] * depth[node] + query(0, V[node]);

    st.push_back({});
    update(0, Line(-depth[node], dp[node]));

    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        depth[i[0]] = depth[node] + i[1];
        dfs(i[0], node);
    }

    rollback();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, Z;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z}), adj[Y].push_back({X, Z});
    }

    for (int i = 2; i <= N; i++)
        cin >> S[i] >> V[i];

    tree.push_back(Node(0, INF, Line(0, INF)));

    dfs(1, 0);

    for (int i = 2; i <= N; i++)
        cout << dp[i] << ' ';
    cout << '\n';

    return 0;
}