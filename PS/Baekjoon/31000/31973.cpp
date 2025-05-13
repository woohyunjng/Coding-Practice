#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 500001;
const int MOD = 1'000'000'007;

int N, A[MAX], B[MAX], V[MAX], two[MAX], tree[2][MAX * 4], lazy[2][MAX * 4];
vector<int> arr[MAX * 2];

void init(int t, int n, int s, int e) {
    lazy[t][n] = 1;
    if (s == e)
        tree[t][n] = t == 0 ? two[N - s] : two[s - 1];
    else {
        int m = s + e >> 1;
        init(t, n << 1, s, m), init(t, n << 1 | 1, m + 1, e);
        tree[t][n] = (tree[t][n << 1] + tree[t][n << 1 | 1]) % MOD;
    }
}

void lazy_update(int t, int n, int s, int e) {
    if (lazy[t][n] == 1)
        return;
    tree[t][n] = tree[t][n] * lazy[t][n] % MOD;
    if (s ^ e) {
        lazy[t][n << 1] = lazy[t][n << 1] * lazy[t][n] % MOD;
        lazy[t][n << 1 | 1] = lazy[t][n << 1 | 1] * lazy[t][n] % MOD;
    }
    lazy[t][n] = 1;
}

int query(int t, int n, int s, int e, int l, int r) {
    lazy_update(t, n, s, e);
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[t][n];
    else {
        int m = s + e >> 1;
        return (query(t, n << 1, s, m, l, r) + query(t, n << 1 | 1, m + 1, e, l, r)) % MOD;
    }
}

void update(int t, int n, int s, int e, int l, int r, int v) {
    lazy_update(t, n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[t][n] = v, lazy_update(t, n, s, e);
    else {
        int m = s + e >> 1;
        update(t, n << 1, s, m, l, r, v), update(t, n << 1 | 1, m + 1, e, l, r, v);
        tree[t][n] = (tree[t][n << 1] + tree[t][n << 1 | 1]) % MOD;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int S, X, ans = 0;
    vector<int> comp;
    set<int> st[2];

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back(A[i]);
    for (int i = 1; i <= N; i++)
        cin >> B[i], comp.push_back(B[i]);

    two[0] = 1;
    for (int i = 1; i <= N; i++)
        two[i] = two[i - 1] * 2 % MOD;

    for (int i = 1; i <= N; i++)
        ans = (ans - (A[i] + B[i]) * two[N - 1] % MOD + MOD) % MOD;

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 1; i <= N; i++) {
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;
        B[i] = lower_bound(comp.begin(), comp.end(), B[i]) - comp.begin() + 1;
        arr[A[i]].push_back(i), arr[B[i]].push_back(i);
        st[0].insert(i), st[1].insert(i);
    }

    init(0, 1, 1, N), init(1, 1, 1, N);

    function<int(int, int)> get = [&](int t, int x) {
        if (st[t].empty())
            return x;
        else if (t == 0)
            return min(x, *st[t].begin() - 1);
        else
            return max(x, *st[t].rbegin() + 1);
    };

    for (int i = 1; i <= S; i++) {
        if (st[0].empty())
            ans = (ans + query(0, 1, 1, N, N, N) * N % MOD * comp[i - 1] % MOD) % MOD;
        ans = (ans - query(0, 1, 1, N, 1, get(0, N)) * comp[i - 1] % MOD + MOD) % MOD;
        ans = (ans - query(1, 1, 1, N, get(1, 1), N) * comp[i - 1] % MOD + MOD) % MOD;

        for (int j : arr[i]) {
            V[j]++;
            if (V[j] == 1) {
                if (st[0].find(j) != st[0].end())
                    st[0].erase(j);
                if (st[1].find(j) != st[1].end())
                    st[1].erase(j);
            } else
                update(0, 1, 1, N, j, N, 2), update(1, 1, 1, N, 1, j, 2);
        }

        if (st[0].empty())
            ans = (ans - query(0, 1, 1, N, N, N) * N % MOD * comp[i - 1] % MOD + MOD) % MOD;
        ans = (ans + query(0, 1, 1, N, 1, get(0, N)) * comp[i - 1] % MOD) % MOD;
        ans = (ans + query(1, 1, 1, N, get(1, 1), N) * comp[i - 1] % MOD) % MOD;
    }

    cout << ans << '\n';

    return 0;
}