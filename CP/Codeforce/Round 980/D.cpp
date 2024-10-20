#include <bits/stdc++.h>
#define int long long

#define MAX 400100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class SegTree {
  public:
    int N;
    vector<int> arr, tree;

    SegTree(int n) : N(n), arr(n + 1, 0), tree(n * 2 + 1, INF) {}

    void init() {
        for (int i = 1; i <= N; i++)
            tree[i + N - 1] = arr[i];

        for (int i = N - 1; i > 0; --i)
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }

    int query(int l, int r) {
        int res = INF;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = min(res, tree[l++]);
            if (r & 1)
                res = min(res, tree[--r]);
        }
        return res;
    }

    int query(int pos) { return query(pos, pos); }
    void update(int pos, int val) {
        for (tree[pos += N - 1] = val; pos > 1; pos >>= 1)
            tree[pos >> 1] = min(tree[pos], tree[pos ^ 1]);
    }
};

int A[MAX], B[MAX], dp[MAX], sm[MAX];

vector<int> adj[MAX];

void solve() {
    int N, X, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sm[i] = sm[i - 1] + A[i];
        adj[i].clear();
    }

    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        if (i < B[i])
            adj[B[i]].push_back({i});
    }

    fill(dp, dp + N + 1, INF);
    dp[1] = 0;

    SegTree tree(N);

    for (int i = 1; i <= N; i++) {
        for (int j : adj[i])
            dp[i] = min(dp[i], tree.query(j, i - 1) + A[j]);
        tree.update(i, dp[i]);
        res = max(res, sm[i] - dp[i]);
    }

    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}