#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<pr, 2> matrix;

const int MAX = 100001;
const int MOD = 1000000007;

vector<int> adj[MAX];
int N, K, dp1[MAX], dp2[MAX], S, sz[MAX], L[MAX];
bool chk1[MAX], chk2[MAX];

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        N = N * N % MOD, K >>= 1;
    }
    return res;
}

matrix mul(matrix X, matrix Y) {
    matrix res = matrix{pr{0, 0}, pr{0, 0}};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                res[i][j] += X[i][k] * Y[k][j] % MOD, res[i][j] %= MOD;
    return res;
}

matrix fpow(matrix N, int K) {
    matrix res = matrix{pr{1, 0}, pr{0, 1}};
    while (K) {
        if (K & 1)
            res = mul(res, N);
        N = mul(N, N), K >>= 1;
    }
    return res;
}

void dfs1(int node, int par) {
    sz[node] = 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs1(i, node);
        chk1[node] |= !chk1[i], sz[node] += sz[i];
    }
}

void dfs2(int node, int par, int chk) {
    int C = !chk;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        C += !chk1[i];
    }
    chk2[node] = C > 0;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs2(i, node, (C - !chk1[i]) > 0);
    }
}

void dfs3(int node, int par) {
    int C = 0, X = 0;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs3(i, node), C += !chk1[i];
    }

    dp1[node] = fpow(N, (K - 1) << 1 | 1) * sz[node] % MOD;
    if (C == 0) {
        dp1[node] = (dp1[node] - S + MOD) % MOD;
        for (int i : adj[node]) {
            if (i == par)
                continue;
            dp1[node] = (dp1[node] - dp1[i] + MOD) % MOD;
        }
    } else if (C == 1)
        for (int i : adj[node]) {
            if (i == par || chk1[i])
                continue;
            dp1[node] = (dp1[node] - dp1[i] + MOD) % MOD;
        }
}

void dfs4(int node, int par, bool chk, int val) {
    int C = !chk, X, S1 = !chk ? val : 0, S2 = chk ? val : 0;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        C += !chk1[i];
        if (chk1[i])
            S2 += dp1[i], S2 %= MOD;
        else
            S1 += dp1[i], S1 %= MOD;
    }

    dp2[node] = fpow(N, K << 1);
    if (C == 0)
        dp2[node] = (dp2[node] - S2 - S + MOD * 2) % MOD;
    else if (C == 1)
        dp2[node] = (dp2[node] - S1 + MOD) % MOD;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        C -= !chk1[i], X = fpow(N, (K - 1) << 1 | 1) * (N - sz[i]) % MOD;
        if (chk1[i])
            S2 = (S2 - dp1[i] + MOD) % MOD;
        else
            S1 = (S1 - dp1[i] + MOD) % MOD;
        if (C == 0)
            X = (X - S2 - S + MOD * 2) % MOD;
        else if (C == 1)
            X = (X - S1 + MOD) % MOD;
        dfs4(i, node, C > 0, X);
        C += !chk1[i];
        if (chk1[i])
            S2 += dp1[i], S2 %= MOD;
        else
            S1 += dp1[i], S1 %= MOD;
    }
}

void dfs5(int node, int par) {
    int C = 0, X = 0, Y = 0;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        C += !chk1[i], dfs5(i, node);
        if (!chk1[i])
            X += L[i];
        else
            Y += L[i];
    }
    L[node] = !chk1[node];
    if (!chk1[node])
        L[node] += Y;
    else if (C == 1)
        L[node] += X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int D, U, V, F = 0, E, ans, Z;

    cin >> N >> D;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    dfs1(1, 0), dfs2(1, 0, true);
    for (int i = 1; i <= N; i++)
        dp1[i] = chk1[i], dp2[i] = chk2[i], S += dp2[i], S %= MOD;
    F = N - S;

    K = 1, dfs3(1, 0), dfs4(1, 0, true, 0), S = 0;
    for (int j = 1; j <= N; j++)
        S += dp2[j], S %= MOD;
    V = (N * N % MOD * N % MOD - S + MOD) % MOD;

    E = (V - F * N % MOD * N % MOD + MOD) % MOD * fpow(F, MOD - 2) % MOD;
    matrix asdf = fpow((matrix){pr{E, F * N % MOD * N % MOD}, pr{0, N * N % MOD}}, D - 1);
    V = (asdf[0][0] * F + asdf[0][1]) % MOD;

    dfs5(1, 0), Z = L[1];

    if (!chk2[1])
        ans = Z * V % MOD;
    else
        ans = (fpow(N, 2 * D) - Z * V % MOD + MOD) % MOD;
    cout << ans << '\n';

    return 0;
}