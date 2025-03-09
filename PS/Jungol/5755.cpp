#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 600000;

int S[MAX], E[MAX], T[MAX], A[MAX], B[MAX], ans[MAX], tree[MAX * 4];

void init(int n, int s, int e) {
    tree[n] = MAX;
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return MAX;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return min(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = min(tree[n], v);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = min(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X;
    vector<int> comp;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> S[i] >> E[i] >> T[i], E[i]--;
        comp.push_back(S[i]), comp.push_back(E[i]);
    }

    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        comp.push_back(A[i]), comp.push_back(B[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), K = comp.size();

    for (int i = 1; i <= N; i++) {
        S[i] = lower_bound(comp.begin(), comp.end(), S[i]) - comp.begin() + 1;
        E[i] = lower_bound(comp.begin(), comp.end(), E[i]) - comp.begin() + 1;
    }

    init(1, 1, K);

    for (int i = 1; i <= M; i++) {
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;
        B[i] = lower_bound(comp.begin(), comp.end(), B[i]) - comp.begin() + 1;

        update(1, 1, K, A[i], i), update(1, 1, K, B[i], i);
    }

    for (int i = 1; i <= N; i++) {
        X = query(1, 1, K, S[i], E[i]);
        if (X != MAX && S[i] <= A[X] && A[X] <= E[i] && S[i] <= B[X] && B[X] <= E[i])
            ans[X] += T[i];
    }

    for (int i = 1; i <= M; i++)
        cout << ans[i] << '\n';

    return 0;
}