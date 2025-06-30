#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

typedef array<int, 2> pr;

int N, W[MAX], V[MAX], mtree[MAX * 4], tree[MAX * 4];
vector<int> arr;

int merge(int X, int Y) { return W[Y] < W[X] ? Y : X; }

void minit(int n, int s, int e) {
    if (s == e)
        mtree[n] = s;
    else {
        int m = s + e >> 1;
        minit(n << 1, s, m), minit(n << 1 | 1, m + 1, e);
        mtree[n] = merge(mtree[n << 1], mtree[n << 1 | 1]);
    }
}

int mquery(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return mtree[n];
    else {
        int m = s + e >> 1;
        return merge(mquery(n << 1, s, m, l, r), mquery(n << 1 | 1, m + 1, e, l, r));
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

void dnc(int l, int r, int par) {
    if (l > r)
        return;
    int X = mquery(1, 1, N, l, r);
    if (par != 0) {
        V[X] = W[par] + W[X];
        arr.push_back(W[par] + W[X]);
    } else
        V[X] = W[X] * 2;
    arr.push_back(W[X] * 2);
    dnc(l, X - 1, X), dnc(X + 1, r, X);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, X = 0, C = 0, Y, L, R, val, ans = INF;
    vector<int> seg_add[2];
    set<int> st;

    cin >> N >> K, W[0] = INF;
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
        seg_add[0].push_back(i), seg_add[1].push_back(i);
    }

    minit(1, 1, N);
    dnc(1, N, 0);

    sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end());
    sort(seg_add[0].begin(), seg_add[0].end(), [](int x, int y) { return W[x] < W[y]; });
    sort(seg_add[1].begin(), seg_add[1].end(), [](int x, int y) { return V[x] < V[y]; });

    for (int i : arr) {
        while (X < seg_add[0].size() && W[seg_add[0][X]] * 2 <= i)
            Y = seg_add[0][X++], st.insert(Y);
        while (C < seg_add[1].size() && V[seg_add[1][C]] <= i)
            Y = seg_add[1][C++], update(1, 1, N, Y, 1);

        L = *st.begin(), R = *st.rbegin();
        val = query(1, 1, N, L, R);
        if (max(W[L], W[R]) + min(W[mquery(1, 1, N, 1, L - 1)], W[mquery(1, 1, N, R + 1, N)]) <= i)
            val++;
        else if (val == K - 1)
            ans = min(ans, max(W[L], W[R]) + min(W[mquery(1, 1, N, 1, L - 1)], W[mquery(1, 1, N, R + 1, N)]));

        if (val >= K) {
            ans = min(ans, i);
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}