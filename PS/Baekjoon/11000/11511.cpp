#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;
const int MAX_C = 22;
const int MOD = 10007;

int C, A[MAX], B[MAX], tree[300000][MAX_C];

void init(int n, int s, int e) {
    if (s == e)
        tree[n][1] = A[s], tree[n][0] = B[s];
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);

        for (int i = 0; i <= C; i++)
            tree[n][i] = 0;
        for (int i = 0; i <= C; i++)
            for (int j = 0; j <= C; j++)
                tree[n][min(i + j, C)] = (tree[n][min(i + j, C)] + tree[n << 1][i] * tree[n << 1 | 1][j] % MOD) % MOD;
    }
}

void update(int n, int s, int e, int x) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n][1] = A[s], tree[n][0] = B[s];
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x), update(n << 1 | 1, m + 1, e, x);

        for (int i = 0; i <= C; i++)
            tree[n][i] = 0;
        for (int i = 0; i <= C; i++)
            for (int j = 0; j <= C; j++)
                tree[n][min(i + j, C)] = (tree[n][min(i + j, C)] + tree[n << 1][i] * tree[n << 1 | 1][j] % MOD) % MOD;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, X, Y;

    cin >> N >> C;
    for (int i = 1; i <= N; i++)
        cin >> A[i], A[i] %= MOD;
    for (int i = 1; i <= N; i++)
        cin >> B[i], B[i] %= MOD;

    init(1, 1, N);

    cin >> Q;
    while (Q--) {
        cin >> T >> X >> Y;
        A[T] = X % MOD, B[T] = Y % MOD, update(1, 1, N, T);
        cout << tree[1][C] << '\n';
    }
}