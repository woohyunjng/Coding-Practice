#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 201000;

int N, X[MAX], D[MAX], L[MAX], tree[2][MAX];

int query(int t, int n) {
    int res = 0;
    while (n)
        res += tree[t][n], n -= n & -n;
    return res;
}

void update(int t, int n, int v) {
    while (n <= N)
        tree[t][n] += v, n += n & -n;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, K, st, en, md;

    cin >> N >> Q;

    for (int i = 1; i <= Q; i++)
        cin >> X[i] >> D[i] >> L[i];

    for (int i = 1; i <= N; i++)
        update(0, i, 1), update(1, i, 1);

    for (int i = Q; i >= 1; i--) {
        st = 1, en = N, K = 0, L[i] *= 2;
        while (st <= en) {
            md = st + en >> 1;
            if (query(D[i] == 2 ? 0 : 1, md) <= X[i])
                st = md + 1, K = md;
            else
                en = md - 1;
        }
        if (D[i] == 1)
            update(0, 1, -L[i]), update(0, K + 1, L[i]);
        else
            update(1, K + 1, L[i]);
    }

    for (int i = 1; i <= N; i++)
        cout << (query(1, i) - query(0, i)) / 2 << ' ';
    cout << '\n';

    return 0;
}