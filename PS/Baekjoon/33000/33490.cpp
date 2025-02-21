#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 1000000;

pr tree[MAX * 4];

int C[MAX], S[MAX], QI[MAX], QC[MAX], QS[MAX], V[MAX];

pr merge(pr A, pr B) {
    if (B[0] == 0)
        return A;
    pr res = {A[0] + B[0], max(A[1] + B[0], B[1])};
    return res;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = {0, V[s]};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n][0] += v, tree[n][1] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, Z, SZ, K;
    vector<int> comp;

    comp.push_back(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> C[i] >> S[i];
        comp.push_back(S[i]);
    }

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> QI[i] >> QC[i] >> QS[i];
        comp.push_back(QS[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), SZ = comp.size();
    for (int i = 1; i <= SZ; i++)
        V[i] = comp[i - 1];
    init(1, 1, SZ);

    for (int i = 1; i <= N; i++) {
        X = lower_bound(comp.begin(), comp.end(), S[i]) - comp.begin() + 1;
        update(1, 1, SZ, X, C[i]);
    }
    cout << tree[1][1] - 1 << '\n';

    for (int i = 1; i <= Q; i++) {
        K = QI[i];
        X = lower_bound(comp.begin(), comp.end(), S[K]) - comp.begin() + 1;
        update(1, 1, SZ, X, -C[K]);

        S[K] = QS[i], C[K] = QC[i];
        X = lower_bound(comp.begin(), comp.end(), S[K]) - comp.begin() + 1;
        update(1, 1, SZ, X, C[K]);

        cout << tree[1][1] - 1 << '\n';
    }

    return 0;
}