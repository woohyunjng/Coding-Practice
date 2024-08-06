#include <bits/stdc++.h>
#define int long long
#define MAX 5010
#define MOD 1000000009

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int fac[MAX], inv_fac[MAX], arr[MAX], comb[MAX][MAX];
bool checked[MAX];

class FenwickTree {
  public:
    int N;
    int arr[MAX] = {}, tree[MAX] = {};

    FenwickTree(int n) : N(n) {}

    void build() {
        for (int i = 1; i <= N; i++) {
            tree[i] += arr[i];
            if (i + (i & -i) <= N)
                tree[i + (i & -i)] += tree[i];
        }
    }

    void update(int n, int val) {
        arr[n] += val;
        while (n <= N) {
            tree[n] += val;
            n += n & -n;
        }
    }

    int query(int n) {
        int res = 0;
        while (n) {
            res += tree[n];
            n -= n & -n;
        }
        return res;
    }

    int query(int l, int r) { return query(r) - query(l - 1); }
};

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1;
        N = N * N % MOD;
    }
    return res;
}

int prime_inverse(int K, int X) { return fpow(K, X - 2); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, res = 0, X, Y, Z, st, en, md;
    bool found = false;
    cin >> N >> K;

    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv_fac[i] = prime_inverse(fac[i], MOD);
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                comb[i][j] = 1;
            else {
                X = fac[i], Y = inv_fac[i - j], Z = inv_fac[j];
                comb[i][j] = X * Y % MOD * Z % MOD;
            }
        }
    }

    for (int i = 1; i <= K; i++) {
        cin >> arr[i];
        checked[arr[i]] = true;
    }

    FenwickTree tree_arr(N);

    for (int i = 1; i <= N; i++) {
        if (!checked[i])
            tree_arr.update(i, 1);
    }

    for (int i = K; i >= 1; i--) {
        X = comb[N - arr[i - 1]][K - i + 1], Y = 0;
        for (int j = arr[i]; j <= N; j++) {
            Y = (Y + comb[N - j][K - i] + MOD) % MOD;
        }
        X = (X - Y + MOD) % MOD;
        res = (res + X) % MOD;
    }

    cout << (res + 1) % MOD << '\n';

    X = K;
    while (true) {
        if (tree_arr.query(arr[X] + 1, N) > K - X) {
            Y = X;
            for (int i = arr[X] + 1; i <= N; i++) {
                if (tree_arr.arr[i] != 0) {
                    arr[Y++] = i;
                }
            }
            break;
        }

        tree_arr.update(arr[X--], 1);
    }

    for (int i = 1; i <= K; i++)
        cout << arr[i] << ' ';

    return 0;
}