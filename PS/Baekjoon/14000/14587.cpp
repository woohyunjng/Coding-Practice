#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 600000;
const int INF = 0x3f3f3f3f3f3f3f3f;

int dp[MAX], X[MAX], H[MAX], tree[MAX * 4], A[MAX], B[MAX];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = INF;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = min(tree[n << 1], tree[n << 1 | 1]);
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

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return INF;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return min(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    vector<int> arr, comp;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> H[i];
        arr.push_back(i), comp.push_back(X[i]);
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return X[x] < X[y]; });
    sort(comp.begin(), comp.end());

    init(1, 1, N);
    for (int i = 0; i < N; i++) {
        K = lower_bound(comp.begin(), comp.end(), X[arr[i]] - H[arr[i]]) - comp.begin() + 1;
        A[i + 1] = min(i + 1, query(1, 1, N, K, i));
        update(1, 1, N, i + 1, A[i + 1]);
    }

    init(1, 1, N);
    for (int i = N - 1; i >= 0; i--) {
        K = upper_bound(comp.begin(), comp.end(), X[arr[i]] + H[arr[i]]) - comp.begin();
        B[i + 1] = max(i + 1, -query(1, 1, N, i + 2, K));
        update(1, 1, N, i + 1, -B[i + 1]);
    }

    init(1, 1, N);
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[A[i] - 1] + 1;
        dp[i] = min(dp[i], query(1, 1, N, i, N));
        update(1, 1, N, B[i], dp[i - 1] + 1);
    }

    cout << dp[N] << '\n';

    return 0;
}