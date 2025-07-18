#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000002;
const int INF = 0x3f3f3f3f3f3f3f3f;

int S, SA[MAX], SB[MAX], C[MAX], dp[MAX], tree[MAX * 2];
vector<int> arr[MAX];

void update(int x, int v) {
    for (tree[x += S - 1] = max(tree[x + S - 1], v); x > 1; x >>= 1)
        tree[x >> 1] = max(tree[x], tree[x ^ 1]);
}

int query(int l, int r) {
    int res = -INF;
    for (l += S - 1, r += S; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = max(res, tree[l++]);
        if (r & 1)
            res = max(res, tree[--r]);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, X, A, B;
    vector<int> comp[2];

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A >> B >> C[i];
        SA[i] = SA[i - 1] + A, SB[i] = SB[i - 1] + B;
        dp[i] = -INF;
        comp[0].push_back(SA[i]), comp[1].push_back(SB[i]);
    }

    for (int i = 0; i < 2; i++) {
        comp[i].push_back(0);
        sort(comp[i].begin(), comp[i].end()), comp[i].erase(unique(comp[i].begin(), comp[i].end()), comp[i].end());
    }
    S = comp[0].size();

    fill(tree, tree + S * 2, -INF);

    for (int i = 0; i <= N; i++)
        arr[lower_bound(comp[1].begin(), comp[1].end(), SB[i]) - comp[1].begin() + 1].push_back(i);

    for (int i = 1; i <= comp[1].size(); i++) {
        sort(arr[i].begin(), arr[i].end(), [](int x, int y) { return SA[x] == SA[y] ? x < y : SA[x] > SA[y]; });
        for (int j : arr[i]) {
            X = lower_bound(comp[0].begin(), comp[0].end(), SA[j]) - comp[0].begin() + 1;
            dp[j] = max(dp[j], query(X, S) + C[j]), update(X, dp[j]);
        }
    }

    for (int i = 1; i <= N; i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';

    return 0;
}