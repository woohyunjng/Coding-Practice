#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int MOD = 998244353;

int uf[MAX], MX[MAX], sz[MAX], BSZ[MAX];
bool chk[MAX], uchk[MAX];

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    if (X < Y)
        swap(X, Y);
    uf[Y] = X, sz[X] += sz[Y];
}

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        N = N * N % MOD, K >>= 1;
    }
    return res;
}

void solve() {
    int N, M, U, V, ans, AL = 1;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        uf[i] = i, chk[i] = uchk[i] = false, sz[i] = 1;

    while (M--) {
        cin >> U >> V;
        if (U > V)
            swap(U, V);
        if (V == N)
            chk[U] = true;
        else
            uni(U, V);
    }

    for (int i = 1; i <= N; i++) {
        uchk[find(i)] |= chk[i], MX[i] = find(i);
        BSZ[i] = sz[find(i)];
    }
    for (int i = 1; i <= N; i++)
        if (chk[i])
            uni(i, N);

    vector<int> comp;
    for (int i = 1; i <= N; i++)
        if (find(i) == i)
            comp.push_back(sz[i]);
    if (comp.size() == 1)
        AL = 1;
    else {
        for (int i = 0; i + 2 < comp.size(); i++)
            AL = AL * N % MOD;
        for (int i : comp)
            AL = AL * i % MOD;
    }

    for (int i = 1; i < N; i++) {
        ans = 0;
        if (uchk[MX[i]]) {
            if (chk[i]) {
                if (MX[i] == N - 1)
                    ans = AL;
                else if (find(N - 1) != find(i))
                    ans = AL * BSZ[i] % MOD * fpow(sz[find(N)], MOD - 2) % MOD;
            }
        } else {
            if (find(N - 1) == find(i))
                ans = AL * fpow(N * sz[find(i)] % MOD * sz[find(N)] % MOD, MOD - 2) % MOD * (sz[find(N)] + sz[find(i)]) % MOD;
            else if (find(N - 1) != find(N)) {
                U = AL * fpow(N * sz[find(i)] % MOD * sz[find(N)] % MOD, MOD - 2) % MOD * (sz[find(i)] + sz[find(N)]) % MOD;
                ans = U * BSZ[i] % MOD * fpow(sz[find(N)] + BSZ[i], MOD - 2) % MOD;
            }
        }

        cout << ans << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}