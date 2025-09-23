#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 6> tp;

const int MAX = 300001;

pr merge(pr X, pr Y) {
    if (X[0] != Y[0])
        return X[0] > Y[0] ? X : Y;
    return {X[0], max(X[1], Y[1])};
}

tp merge(tp X, tp Y) {
    pr A = merge((pr){X[0], X[1]}, (pr){Y[0], Y[1]}),
       B = merge((pr){X[2], X[3]}, (pr){Y[2], Y[3]}),
       C = merge((pr){X[4], X[5]}, (pr){Y[4], Y[5]});
    C = merge(C, (pr){X[0] + Y[2], X[1] + Y[3]});
    tp res = {A[0], A[1], B[0], B[1], C[0], C[1]};
    return res;
}

int A[MAX], V[MAX];
pr tree[MAX * 4][2];
tp ptree[MAX * 4];

pr query(int t, int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {0, 0};
    else if (l <= s && e <= r)
        return tree[n][t];
    else {
        int m = s + e >> 1;
        return merge(query(t, n << 1, s, m, l, r), query(t, n << 1 | 1, m + 1, e, l, r));
    }
}

void update(int t, int n, int s, int e, int x, pr v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n][t] = v;
    else {
        int m = s + e >> 1;
        update(t, n << 1, s, m, x, v), update(t, n << 1 | 1, m + 1, e, x, v);
        tree[n][t] = merge(tree[n << 1][t], tree[n << 1 | 1][t]);
    }
}

tp query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {0, 0, 0, 0, 0, 0};
    else if (l <= s && e <= r)
        return ptree[n];
    else {
        int m = s + e >> 1;
        return merge(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

void update(int n, int s, int e, int x, tp v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        ptree[n] = v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        ptree[n] = merge(ptree[n << 1], ptree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans;
    vector<int> comp;
    pr K;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back(A[i]);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 1; i <= N; i++) {
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;
        cin >> V[i];
    }

    for (int i = N; i >= 1; i--) {
        K = query(0, 1, 1, N, A[i] + 1, N);
        update(0, 1, 1, N, A[i], {K[0] + 1, K[1] + V[i]});
        update(1, 1, N, A[i], {0, 0, K[0] + 1, K[1] + V[i], K[0] + 1, K[1] + V[i]});
    }

    for (int i = 1; i <= N; i++) {
        update(1, 1, N, A[i], {0, 0, 0, 0, 0, 0});
        cout << ptree[1][5] << ' ';
        K = query(1, 1, 1, N, 1, A[i] - 1);
        update(1, 1, 1, N, A[i], {K[0] + 1, K[1] + V[i]});
        update(1, 1, N, A[i], {K[0] + 1, K[1] + V[i], 0, 0, K[0] + 1, K[1] + V[i]});
    }
    cout << '\n';

    return 0;
}