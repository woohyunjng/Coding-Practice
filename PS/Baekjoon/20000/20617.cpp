#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 1000001;
const int INF = 100000000;

int A[MAX][2], S[MAX][2], X[MAX][2], Y[MAX][2], tree[MAX * 8];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = -INF;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = max(tree[n], v);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return -INF;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return max(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N[2], ST, ans, V, K[2], M, MC;

    cin >> T;
    while (T--) {
        cin >> N[0] >> N[1], ans = 0, M = MAX;
        ST = max(N[0], N[1]) + 1;

        for (int t = 0; t < 2; t++) {
            K[0] = K[1] = 0;
            for (int i = 0; i <= N[t]; i++)
                A[i][t] = S[i][t] = X[i][t] = Y[i][t] = 0;

            for (int i = 1; i <= N[t]; i++) {
                cin >> A[i][t], S[i][t] = S[i - 1][t] + (A[i][t] == 2);
                if (A[i][t] == 1)
                    X[++K[0]][t] = i;
            }
            for (int i = N[t]; i >= 1; i--)
                if (A[i][t] == 3)
                    Y[++K[1]][t] = i;
            M = min(M, K[1]), Y[0][t] = N[t] + 1;
        }

        init(1, -ST, ST), MC = 0;
        for (int i = min(N[0], N[1]); i >= 0; i--) {
            if (i != 0 && (X[i][0] == 0 || X[i][1] == 0))
                continue;
            while (MC <= M && Y[MC][0] > X[i][0] && Y[MC][1] > X[i][1])
                update(1, -ST, ST, S[Y[MC][0] - 1][0] - S[Y[MC][1] - 1][1], MC + S[Y[MC][0] - 1][0]), MC++;

            ans = max(ans,
                      query(1, -ST, ST, -ST, S[X[i][0]][0] - S[X[i][1]][1]) - S[X[i][0]][0] + i);
        }

        init(1, -ST, ST), MC = 0;
        for (int i = min(N[0], N[1]); i >= 0; i--) {
            if (i != 0 && (X[i][0] == 0 || X[i][1] == 0))
                continue;
            while (MC <= M && Y[MC][0] > X[i][0] && Y[MC][1] > X[i][1])
                update(1, -ST, ST, S[Y[MC][0] - 1][0] - S[Y[MC][1] - 1][1], MC + S[Y[MC][1] - 1][1]), MC++;
            ans = max(ans,
                      query(1, -ST, ST, S[X[i][0]][0] - S[X[i][1]][1], ST) - S[X[i][1]][1] + i);
        }

        cout << ans << '\n';
    }

    return 0;
}