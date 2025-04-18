#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 250001;
const int MAX_LOG = 20;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[MAX];
set<pr> st[MAX];
multiset<int> val[MAX];

int N, parent[MAX][MAX_LOG], depth[MAX], mx[MAX], V[2][MAX];

void dfs(int node, int par) {
    val[node].insert(0), mx[node] = 0;
    depth[node] = depth[par] + 1, parent[node][0] = par;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), mx[node] = max(mx[node], mx[i] + 1);
        st[node].insert({i, mx[i] + 1}), val[node].insert(mx[i] + 1);
    }
}

void len_dfs(int node, int par, int len) {
    st[node].insert({par, len}), val[node].insert(len);
    for (int i : adj[node]) {
        if (i == par)
            continue;
        val[node].erase(val[node].find(mx[i] + 1));
        len_dfs(i, node, *val[node].rbegin() + 1);
        val[node].insert(mx[i] + 1);
    }
}

int lca(int A, int B) {
    if (depth[A] < depth[B])
        swap(A, B);

    int diff = depth[A] - depth[B];
    for (int i = 0; diff; i++) {
        if (diff & 1)
            A = parent[A][i];
        diff >>= 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[A][i] != parent[B][i])
            A = parent[A][i], B = parent[B][i];
    if (A != B)
        A = parent[A][0];
    return A;
}

int get_dis(int A, int B) {
    int X = lca(A, B);
    return depth[A] + depth[B] - 2 * depth[X];
}

void init(signed n, vector<signed> X, vector<signed> Y) {
    N = n;
    for (int i = 0; i < N - 1; i++)
        adj[X[i]].push_back(Y[i]), adj[Y[i]].push_back(X[i]);
    dfs(1, 0), len_dfs(1, 0, 0);
}

int mx_chain(int node, int par) {
    int X = (*st[node].lower_bound({par, 0}))[1], res;
    val[node].erase(val[node].find(X));
    res = *val[node].rbegin(), val[node].insert(X);
    return res;
}

int move(int idx, int X, int Y) {
    int L = 0, R = 0, res = -X - Y, K = X + Y, D = 0;
    bool flag;

    while (true) {
        res += K - L - R, flag = false;
        while (L + 1 <= X && V[idx][L + 1] + L + R + 1 >= K)
            L++, flag = true;
        if (L + R == K)
            return res;
        if (!flag)
            return INF;
        res += K - L - R;
        while (R + 1 <= Y && V[idx ^ 1][R + 1] + L + R + 1 >= K)
            R++, flag = true;
        if (X == L && Y == R)
            return res;
        if (!flag)
            return INF;
    }
}

int get(int rt, int A, int B) {
    int X = get_dis(rt, A), Y = get_dis(rt, B), K, Z, C;

    K = rt, Z = depth[rt] - depth[lca(rt, A)];
    for (int i = 1; i <= Z; i++)
        C = parent[K][0], V[0][i] = mx_chain(C, K), K = C;

    K = A;
    for (int i = X; i >= Z + 1; i--)
        V[0][i] = mx_chain(K, parent[K][0]), K = parent[K][0];

    K = rt, Z = depth[rt] - depth[lca(rt, B)];
    for (int i = 1; i <= Z; i++)
        C = parent[K][0], V[1][i] = mx_chain(C, K), K = C;

    K = B;
    for (int i = Y; i >= Z + 1; i--)
        V[1][i] = mx_chain(K, parent[K][0]), K = parent[K][0];

    K = min(move(0, X, Y), move(1, Y, X));
    return K == INF ? -INF : K;
}

int train(vector<signed> Z) {
    int ans = 0, X, Y;

    X = lca(Z[0], Z[1]) ^ lca(Z[0], Z[2]) ^ lca(Z[1], Z[2]);
    Y = lca(Z[2], Z[3]) ^ lca(Z[2], Z[0]) ^ lca(Z[3], Z[0]);

    ans += get_dis(X, Y) + get_dis(Z[0], Z[1]);
    ans += get(X, Z[0], Z[1]) + get(Y, Z[2], Z[3]);

    if (ans < 0)
        return -1;

    return ans;
}