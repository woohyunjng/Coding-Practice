#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;

typedef long long ll;
typedef array<int, 2> pr;

const int MAX = 200001;
const int MAX_LOG = 20;
const int BUCKET = 400;
const int SEG_LOG = 18;

struct FastInput {
    static const int SZ = 1 << 20;
    int idx, size;
    char buf[SZ];

    FastInput() : idx(0), size(0) {}

    inline char readChar() {
        if (idx >= size) {
            size = (int)fread(buf, 1, SZ, stdin);
            idx = 0;
            if (size == 0)
                return 0;
        }
        return buf[idx++];
    }

    template <typename T>
    inline bool readInt(T &out) {
        char c = readChar();
        if (!c)
            return false;
        while (c <= ' ') {
            c = readChar();
            if (!c)
                return false;
        }
        T sign = 1;
        if (c == '-') {
            sign = -1;
            c = readChar();
        }
        T val = 0;
        while (c > ' ') {
            val = val * 10 + (c - '0');
            c = readChar();
        }
        out = val * sign;
        return true;
    }
} In;

struct FastOutput {
    static const int SZ = 1 << 20;
    int idx;
    char buf[SZ];

    FastOutput() : idx(0) {}

    inline void flush() {
        if (idx) {
            fwrite(buf, 1, idx, stdout);
            idx = 0;
        }
    }

    inline void pushChar(char c) {
        if (idx >= SZ)
            flush();
        buf[idx++] = c;
    }

    template <typename T>
    inline void writeInt(T x, char endc) {
        if (x == 0) {
            pushChar('0');
            pushChar(endc);
            return;
        }
        if (x < 0) {
            pushChar('-');
            x = -x;
        }
        char s[24];
        int n = 0;
        while (x) {
            s[n++] = char('0' + (x % 10));
            x /= 10;
        }
        for (int i = n - 1; i >= 0; i--)
            pushChar(s[i]);
        pushChar(endc);
    }

    ~FastOutput() {
        flush();
    }
} Out;

struct Node {
    ll LS = 0, RS = 0, Fval = 0, Lval = 0, Rval = 0, val = 0, S = 0, M = 0;
    Node(int V) {
        M = max(0ll, -(ll)V), S = V;
        LS = RS = max(0ll, (ll)V), Fval = Lval = Rval = val = abs(V);
    };
    Node() {};
};

int in[MAX], out[MAX], cnt, depth[MAX], W[MAX], parent[MAX_LOG][MAX],
    U[MAX], V[MAX], P[MAX], L[MAX], R[MAX], G[MAX];
ll ans[MAX], OR[MAX];
bool toggled[MAX];

alignas(64) Node tree[1 << (SEG_LOG + 1)];
Node DF[MAX];
vector<pr> adj[MAX];

static inline Node merge(const Node &X, const Node &Y) {
    Node res;
    res.S = X.S + Y.S, res.M = max(Y.M, X.M - Y.S);
    res.LS = max(X.LS, X.S + Y.LS), res.RS = max(Y.RS, X.RS + Y.S);
    res.Lval = max(max(X.Lval, X.Fval + Y.LS), -X.S + Y.Lval), res.Rval = max(max(Y.Rval, X.Rval + Y.S), X.M + Y.Fval);
    res.Fval = max(X.Fval + Y.S, -X.S + Y.Fval);
    res.val = max(max(max(X.val, Y.val), X.Rval + Y.LS), X.M + Y.Lval);
    return res;
}

void dfs(int node, int par) {
    in[node] = ++cnt, depth[node] = depth[par] + 1;
    parent[0][node] = par;
    for (int i = 1; i < MAX_LOG; i++)
        parent[i][node] = parent[i - 1][parent[i - 1][node]];

    for (pr &i : adj[node]) {
        if (i[0] == par)
            continue;
        W[i[0]] = i[1], dfs(i[0], node);
    }
    out[node] = ++cnt;
}

int lca(int X, int Y) {
    if (depth[X] < depth[Y])
        swap(X, Y);
    int diff = depth[X] - depth[Y];
    for (int i = 0; i < MAX_LOG; i++)
        if (diff & (1 << i))
            X = parent[i][X];

    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[i][X] ^ parent[i][Y])
            X = parent[i][X], Y = parent[i][Y];
    if (X ^ Y)
        X = parent[0][X];
    return X;
}

static inline void update(int x, int v) {
    x += 1 << SEG_LOG, tree[x] = DF[v], x >>= 1;
    while (x)
        tree[x] = merge(tree[x << 1], tree[x << 1 | 1]), x >>= 1;
}

void toggle(int node) {
    if (node == 0 || node == 1)
        return;
    if (!toggled[node])
        update(in[node], 0), update(out[node], 0);
    else
        update(in[node], node << 1), update(out[node], node << 1 | 1);
    toggled[node] ^= 1;
}

static inline long long hilbertOrder(int x, int y, int pow = 18, int rot = 0) {
    if (pow == 0)
        return 0;
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rot) & 3;
    static const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (hpow - 1), ny = y & (hpow - 1);
    int nrot = (rot + rotateDelta[seg]) & 3;
    long long sub = hilbertOrder(nx, ny, pow - 1, nrot);
    long long add = (long long)seg << (2 * pow - 2);
    if (seg == 1 || seg == 2)
        return add + sub;
    else
        return add + ((1LL << (2 * pow - 2)) - 1 - sub);
}

signed main() {
    int N, Q, X, Y, Z, PL, PR;
    vector<int> queries;

    In.readInt(N);
    for (int i = 1; i < N; i++) {
        In.readInt(X), In.readInt(Y), In.readInt(Z);
        adj[X].push_back({Y, Z}), adj[Y].push_back({X, Z});
    }

    dfs(1, 0);
    for (int i = 1; i <= N; i++)
        P[in[i]] = P[out[i]] = i;

    for (int i = 2; i <= N; i++) {
        DF[i << 1] = Node(W[i]), DF[i << 1 | 1] = Node(-W[i]);
        update(in[i], i << 1), update(out[i], i << 1 | 1);
    }

    In.readInt(Q);
    for (int i = 1; i <= Q; i++) {
        In.readInt(U[i]), In.readInt(V[i]), X = lca(U[i], V[i]);

        if ((depth[U[i]] - depth[X]) + (depth[V[i]] - depth[X]) <= 300) {
            Y = U[i], Z = V[i];
            while (Y ^ X) {
                update(in[Y], 0), update(out[Y], 0);
                Y = parent[0][Y];
            }
            while (Z ^ X) {
                update(in[Z], 0), update(out[Z], 0);
                Z = parent[0][Z];
            }
            ans[i] = tree[1].val;
            Y = U[i], Z = V[i];
            while (Y ^ X) {
                update(in[Y], Y << 1), update(out[Y], Y << 1 | 1);
                Y = parent[0][Y];
            }
            while (Z ^ X) {
                update(in[Z], Z << 1), update(out[Z], Z << 1 | 1);
                Z = parent[0][Z];
            }
        } else {
            if (in[U[i]] > in[V[i]])
                swap(U[i], V[i]);
            L[i] = in[U[i]], R[i] = in[V[i]];
            if (X != U[i] && X != V[i]) {
                L[i] = out[U[i]];
                if (L[i] > R[i])
                    swap(L[i], R[i]);
            } else
                G[i] = X;
            queries.push_back(i), OR[i] = hilbertOrder(L[i], R[i]);
        }
    }

    sort(queries.begin(), queries.end(), [&](int x, int y) { return OR[x] < OR[y]; });

    PL = PR = 1, toggle(P[1]);

    for (int i : queries) {
        while (PL > L[i])
            toggle(P[--PL]);
        while (PR < R[i])
            toggle(P[++PR]);
        while (PL < L[i])
            toggle(P[PL++]);
        while (PR > R[i])
            toggle(P[PR--]);

        toggle(G[i]), ans[i] = tree[1].val, toggle(G[i]);
    }

    for (int i = 1; i <= Q; i++)
        Out.writeInt(ans[i], '\n');

    return 0;
}