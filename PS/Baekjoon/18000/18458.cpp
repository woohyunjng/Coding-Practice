#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 300001;
const int MOD = 998'244'353;
const int W = 3;

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1, N = N * N % MOD;
    }
    return res;
}

vector<int> adj[MAX], V[MAX], SV[MAX];

int sz[MAX], depth[MAX], parent[MAX], M[MAX], CD[MAX],
    dis[MAX][25];
int R[MAX << 2], IR[MAX << 2], fac[MAX], inv[MAX];
bool vst[MAX];

int get_sz(int node, int par) {
    sz[node] = 1;
    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        sz[node] += get_sz(i, node);
    }
    return sz[node];
}

int get_cent(int node, int par, int cap) {
    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        if (sz[i] * 2 > cap)
            return get_cent(i, node, cap);
    }
    return node;
}

void dfs(int node, int par) {
    depth[node] = depth[par] + 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
    }
}

void dis_dfs(int node, int par, int len, int c) {
    dis[node][CD[c]] = len, M[c] = max(M[c], len);
    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        dis_dfs(i, node, len + 1, c);
    }
}

void dnc(int node, int par, int dep) {
    int cent = get_cent(node, 0, get_sz(node, 0));
    vst[cent] = true, parent[cent] = par, CD[cent] = dep;

    M[cent] = 0, dis_dfs(cent, 0, 0, cent);

    V[cent].resize(M[cent] + 2, 0);
    if (par != 0)
        SV[cent] = vector<int>(min(sz[node], M[par]) + 2, 0);

    for (int i : adj[cent]) {
        if (vst[i])
            continue;
        dnc(i, cent, dep + 1);
    }
}

void NTT(vector<int> &v, bool inv) {
    int S = v.size(), K, ang, A, B, root;

    for (int i = 1, j = 0; i < S; i++) {
        K = S >> 1;
        for (; j & K; K >>= 1)
            j ^= K;
        j ^= K;
        if (i < j)
            swap(v[i], v[j]);
    }

    for (int i = 2; i <= S; i <<= 1)
        for (int j = 0; j < S; j += i) {
            root = 1;
            for (int k = 0; k < (i >> 1); k++) {
                A = v[j | k], B = v[j | k | i >> 1] * root % MOD;
                v[j | k] = (A + B) % MOD, v[j | k | i >> 1] = (A - B + MOD) % MOD;
                root = root * (inv ? IR[i] : R[i]) % MOD;
            }
        }

    A = fpow(S, MOD - 2);
    if (inv)
        for (int i = 0; i < S; i++)
            v[i] = v[i] * A % MOD;
}

vector<int> mul(vector<int> A, vector<int> B) {
    int S = 1, SZ = (int)A.size() + B.size() - 1;
    while (S < A.size() + B.size())
        S <<= 1;
    A.resize(S), B.resize(S);

    NTT(A, false), NTT(B, false);
    for (int i = 0; i < S; i++)
        A[i] = A[i] * B[i] % MOD;
    NTT(A, true), A.resize(SZ);
    return A;
}

void update(vector<int> &tree, int x, int v) {
    for (x++; x < tree.size(); x += x & -x)
        tree[x] += v;
}

int query(vector<int> &tree, int x) {
    int res = 0;
    if (x < 0)
        return 0;
    for (x = min(x + 1, (int)tree.size() - 1); x > 0; x -= x & -x)
        res += tree[x];
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, A, B, C, D, K;
    vector<int> arr;
    vector<int> VX, VY, ans;

    cin >> N >> L, fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[N] = fpow(fac[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    for (int i = 2; i <= N * 4; i <<= 1)
        R[i] = fpow(W, (MOD - 1) / i), IR[i] = fpow(R[i], MOD - 2);

    VX.resize(N + 1, 0), VY.resize(N + 1, 0);
    for (int i = 0; i <= N; i++)
        VY[i] = inv[N - i];

    for (int i = 1; i < N; i++)
        cin >> A >> B, adj[A].push_back(B), adj[B].push_back(A);

    dfs(1, 0), dnc(1, 0, 1);
    for (int i = 1; i <= N; i++)
        arr.push_back(i);

    sort(arr.begin(), arr.end(), [](int x, int y) { return depth[x] < depth[y]; });
    for (int i : arr) {
        A = -1, B = i, C = 0, K = CD[i];
        while (B) {
            D = dis[i][K];
            update(V[B], D, 1), A += query(V[B], L - D);
            if (C != 0)
                update(SV[C], D, 1), A -= query(SV[C], L - D);
            C = B, B = parent[B], K--;
        }
        VX[A] += fac[A], VX[A] %= MOD;
    }

    ans = mul(VX, VY);
    for (int i = 0; i < N; i++)
        cout << ans[i + N] * inv[i] % MOD << ' ';
    cout << '\n';

    return 0;
}