#include <bits/stdc++.h>

#define MAX 1000100
#define MOD 998244353
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, lazy[4 * MAX][10];
long long tree[4 * MAX][10], ims[10], ten[MAX];
string S;

long long val(int n) {
    long long res = 0;
    for (int i = 0; i < 10; i++)
        res = (res + tree[n][i] * i) % MOD;
    return res;
}

long long merge_node(int n, int s, int e) {
    for (int i = 0; i < 10; i++)
        tree[n][i] = (tree[n << 1][i] * ten[e - ((s + e) >> 1)] % MOD + tree[n << 1 | 1][i]) % MOD;
    return val(n);
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n][S[s - 1] - '0'] = 1;
    else {
        init(n << 1, s, (s + e) >> 1);
        init(n << 1 | 1, ((s + e) >> 1) + 1, e);
        merge_node(n, s, e);
    }

    for (int i = 0; i < 10; i++)
        lazy[n][i] = i;
}

void lazy_update(int n, int s, int e) {
    for (int i = 0; i < 10; i++) {
        ims[i] = tree[n][i];
        tree[n][i] = 0;
    }
    for (int i = 0; i < 10; i++)
        tree[n][lazy[n][i]] = (tree[n][lazy[n][i]] + ims[i]) % MOD;

    if (s != e) {
        for (int i = 0; i < 10; i++) {
            lazy[n << 1][i] = lazy[n][lazy[n << 1][i]];
            lazy[n << 1 | 1][i] = lazy[n][lazy[n << 1 | 1][i]];
        }
    }

    for (int i = 0; i < 10; i++)
        lazy[n][i] = i;
}

long long query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (l <= s && e <= r)
        return val(n);
    else if (r < s || e < l)
        return 0;
    else {
        long long lv = query(n << 1, s, (s + e) >> 1, l, r);
        long long rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
        return (lv * ten[max(0, min(e, r) - ((s + e) >> 1))] % MOD + rv) % MOD;
    }
}

void update(int n, int s, int e, int l, int r, int from, int to) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        lazy_update(n, s, e);
        lazy[n][from] = to;
        lazy_update(n, s, e);
    } else {
        update(n << 1, s, (s + e) >> 1, l, r, from, to);
        update(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r, from, to);
        merge_node(n, s, e);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, T, A, B, X, Y;

    cin >> S;
    N = S.size();

    ten[0] = 1;
    for (int i = 1; i <= N; i++)
        ten[i] = ten[i - 1] * 10 % MOD;

    init(1, 1, N);

    cin >> Q;
    while (Q--) {
        cin >> T >> A >> B;
        if (T == 1) {
            cin >> X >> Y;
            update(1, 1, N, A, B, X, Y);
        } else
            cout << query(1, 1, N, A, B) << '\n';
    }

    return 0;
}