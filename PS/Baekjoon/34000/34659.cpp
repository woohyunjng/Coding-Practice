#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001 * 6;
const int MOD = 998244353;

int L[MAX], R[MAX], C[MAX],
    fac[MAX], inv[MAX],
    cntL[MAX], cntR[MAX], CL[MAX], CR[MAX],
    V[MAX][4], tree[MAX * 4];

vector<int> arrL[MAX], arrR[MAX], arr[MAX];
map<int, int> cntCL[MAX], cntCR[MAX];

// V[i][0] -> l' < l <= r'이면서 다른색
// V[i][1] -> 같은색
// V[i][2] -> l' <= r < r'이면서 다른색
// V[i][3] -> 같은색

int inv_pow(int N) {
    int K = MOD - 2, res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        N = N * N % MOD, K >>= 1;
    }
    return res;
}

void init(int n, int s, int e) {
    tree[n] = 0;
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

int comb(int N, int K) {
    if (K < 0 || K > N)
        return 0;
    return fac[N] * inv[K] % MOD * inv[N - K] % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int D, S, CS, N, ans = 0, base = 0,
                     X, Y, Z;
    vector<int> comp;

    cin >> D >> N, comp.push_back(1), comp.push_back(D);
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i] >> C[i];
        comp.push_back(L[i]), comp.push_back(R[i]);
        if (L[i] > 1)
            comp.push_back(L[i] - 1);
        if (R[i] < D)
            comp.push_back(R[i] + 1);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();

    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[N] = inv_pow(fac[N]);
    for (int i = N - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;

    for (int i = 1; i <= N; i++) {
        L[i] = lower_bound(comp.begin(), comp.end(), L[i]) - comp.begin() + 1, cntL[L[i]]++;
        R[i] = lower_bound(comp.begin(), comp.end(), R[i]) - comp.begin() + 1, cntR[R[i]]++;
        arrL[L[i]].push_back(i), arrR[R[i]].push_back(i), arr[C[i]].push_back(i);
        cntCL[L[i]][C[i]]++, cntCR[R[i]][C[i]]++;
    }

    init(1, 1, S);
    for (int i = 1; i <= S; i++) {
        for (int j : arrL[i])
            V[j][0] = query(1, 1, S, i, S);
        for (int j : arrL[i])
            update(1, 1, S, R[j], 1);
    }

    for (int i = 1; i <= N; i++) {
        if (arr[i].empty())
            continue;

        sort(arr[i].begin(), arr[i].end(), [&](int x, int y) { return L[x] < L[y]; }), comp.clear();
        for (int j : arr[i])
            comp.push_back(L[j]), comp.push_back(R[j]);
        sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), CS = comp.size();
        init(1, 1, CS);

        for (int j : arr[i]) {
            CL[j] = lower_bound(comp.begin(), comp.end(), L[j]) - comp.begin() + 1;
            CR[j] = lower_bound(comp.begin(), comp.end(), R[j]) - comp.begin() + 1;
        }

        for (int j = 0; j < arr[i].size(); j++) {
            X = CL[arr[i][j]], Y = j;

            while (j + 1 < arr[i].size() && CL[arr[i][j + 1]] == X)
                j++;
            for (int k = Y; k <= j; k++)
                V[arr[i][k]][1] = query(1, 1, CS, X, CS);
            for (int k = Y; k <= j; k++)
                update(1, 1, CS, CR[arr[i][k]], 1);
        }
    }

    init(1, 1, S);
    for (int i = S; i >= 1; i--) {
        for (int j : arrR[i])
            V[j][2] = query(1, 1, S, 1, i);
        for (int j : arrR[i])
            update(1, 1, S, L[j], 1);
    }

    for (int i = 1; i <= N; i++) {
        if (arr[i].empty())
            continue;

        sort(arr[i].begin(), arr[i].end(), [&](int x, int y) { return R[x] > R[y]; }), comp.clear();
        for (int j : arr[i])
            comp.push_back(L[j]), comp.push_back(R[j]);
        sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), CS = comp.size();
        init(1, 1, CS);

        for (int j : arr[i]) {
            CL[j] = lower_bound(comp.begin(), comp.end(), L[j]) - comp.begin() + 1;
            CR[j] = lower_bound(comp.begin(), comp.end(), R[j]) - comp.begin() + 1;
        }

        for (int j = 0; j < arr[i].size(); j++) {
            X = CR[arr[i][j]], Y = j;

            while (j + 1 < arr[i].size() && CR[arr[i][j + 1]] == X)
                j++;
            for (int k = Y; k <= j; k++)
                V[arr[i][k]][3] = query(1, 1, CS, 1, X);
            for (int k = Y; k <= j; k++)
                update(1, 1, CS, CL[arr[i][k]], 1);
        }
    }

    for (int i = 1; i <= N; i++) {
        V[i][0] -= V[i][1], V[i][2] -= V[i][3];
        if (L[i] > 1 && cntCR[L[i] - 1].find(C[i]) != cntCR[L[i] - 1].end())
            V[i][1] += cntCR[L[i] - 1][C[i]], V[i][0] -= cntCR[L[i] - 1][C[i]];
        if (L[i] > 1)
            V[i][0] += cntR[L[i] - 1];
        if (R[i] < S && cntCL[R[i] + 1].find(C[i]) != cntCL[R[i] + 1].end())
            V[i][3] += cntCL[R[i] + 1][C[i]], V[i][2] -= cntCL[R[i] + 1][C[i]];
        if (R[i] < S)
            V[i][2] += cntL[R[i] + 1];
    }

    for (int i = 1; i <= N; i++) {
        X = 0;
        if (L[i] == 1 || (V[i][0] == 0 && V[i][1] == 0))
            X = fac[cntL[L[i]] - 1] * fac[N] % MOD * inv[cntL[L[i]]] % MOD;
        else if (V[i][0] > 0) {
            X = V[i][0] * fac[V[i][0] + V[i][1] - 1] % MOD;
            X = X * comb(V[i][0] + V[i][1] + cntL[L[i]] - 1, cntL[L[i]] - 1) % MOD * fac[cntL[L[i]] - 1] % MOD;
            X = X * fac[N] % MOD * inv[V[i][0] + V[i][1] + cntL[L[i]]] % MOD;
        }

        ans += X, ans %= MOD;
    }

    for (int i = 1; i <= N; i++) {
        if (R[i] == S)
            continue;

        X = 0;
        if (V[i][2] == 0 && V[i][3] == 0)
            X = fac[cntR[R[i]] - 1] * fac[N] % MOD * inv[cntR[R[i]]] % MOD;
        else if (V[i][2] > 0) {
            X = V[i][2] * fac[V[i][2] + V[i][3] - 1] % MOD;
            X = X * comb(V[i][2] + V[i][3] + cntR[R[i]] - 1, cntR[R[i]] - 1) % MOD * fac[cntR[R[i]] - 1] % MOD;
            X = X * fac[N] % MOD * inv[V[i][2] + V[i][3] + cntR[R[i]]] % MOD;
        }

        ans += X, ans %= MOD;
    }

    if (cntL[1] == 0)
        ans += fac[N], ans %= MOD;

    ans = ans * inv_pow(fac[N]) % MOD;

    cout << ans << '\n';
}
