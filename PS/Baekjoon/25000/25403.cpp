#include <bits/stdc++.h>
using namespace std;

typedef array<int, 4> tp;

const int MAX = 1000001;

vector<int> arr[MAX];

tp tree[MAX * 4];
int X[MAX], Y[MAX], D[MAX], T[MAX], lazy[MAX * 4];

tp merge(tp A, tp B) {
    tp res = {min(A[0], B[0]), max(A[1], B[1]), 0, 0};

    if (res[0] == A[0])
        res[2] = A[2];
    else
        res[2] = B[2];

    if (res[1] == A[1])
        res[3] = A[3];
    else
        res[3] = B[3];

    return res;
}

void lazy_update(int n, int s, int e) {
    if (!lazy[n])
        return;
    tree[n][0] += lazy[n], tree[n][1] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = {0, 0, s, s};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

tp query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return {MAX, -MAX, 0, 0};
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] += v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, W, H, SX, SY, V = 1, ans = 0;
    tp ans_pr, K;
    vector<int> compX, compY;

    cin >> N >> M >> W >> H;

    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i], T[i] = 1;
        compX.push_back(X[i]), compY.push_back(Y[i]);
        compX.push_back(X[i] + W + 1);
        compY.push_back(Y[i] + 1), compY.push_back(Y[i] - H);
    }
    for (int i = 1; i <= M; i++) {
        cin >> X[N + i] >> Y[N + i], T[N + i] = -1;
        compX.push_back(X[N + i]), compY.push_back(Y[N + i]);
        compX.push_back(X[N + i] + W + 1);
        compY.push_back(Y[N + i] + 1), compY.push_back(Y[N + i] - H);
    }

    sort(compX.begin(), compX.end()), compX.erase(unique(compX.begin(), compX.end()), compX.end());
    sort(compY.begin(), compY.end()), compY.erase(unique(compY.begin(), compY.end()), compY.end());
    N += M, SX = compX.size(), SY = compY.size();

    init(1, 1, SY);

    for (int i = 1; i <= N; i++) {
        X[i] = lower_bound(compX.begin(), compX.end(), X[i]) - compX.begin() + 1;
        D[i] = lower_bound(compY.begin(), compY.end(), Y[i] - H) - compY.begin() + 1;
        Y[i] = lower_bound(compY.begin(), compY.end(), Y[i]) - compY.begin() + 1;

        arr[X[i]].push_back(i);
    }

    for (int i = 1; i <= SX; i++) {
        for (int j : arr[i])
            update(1, 1, SY, D[j], Y[j], T[j]);
        while (V <= SX && compX[V - 1] + W < compX[i - 1]) {
            for (int j : arr[V])
                update(1, 1, SY, D[j], Y[j], -T[j]);
            V++;
        }

        K = query(1, 1, SY, 1, SY);
        if (-K[0] > ans)
            ans = -K[0], ans_pr = {compX[i - 1] - W, compY[K[2] - 1]};
        if (K[1] > ans)
            ans = K[1], ans_pr = {compX[i - 1] - W, compY[K[3] - 1]};
    }

    cout << ans << '\n';
    cout << ans_pr[0] << ' ' << ans_pr[1] << '\n';

    return 0;
}