#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define ADD 10000000000000000
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

struct Node {
    int l = -1, r = -1, val = 0;
};

class DynamicSeg {
  private:
    int nxt = 2;
    vector<Node> tree;

    int update(int n, int s, int e, int target, int val) {
        if (n == -1)
            return 0;
        if (target < s || target > e)
            return tree[n].val;
        if (s == e)
            return tree[n].val = max(tree[n].val, val);

        int mid = s + e >> 1;
        if (target <= mid) {
            if (tree[n].l == -1)
                tree[n].l = nxt++;
        } else if (tree[n].r == -1)
            tree[n].r = nxt++;
            

        return tree[n].val = max(update(tree[n].l, s, mid, target, val), update(tree[n].r, mid + 1, e, target, val));
    }

    int get(int n, int s, int e, int l, int r) {
        if (n == -1 || e < l || s > r)
            return 0;
        if (s >= l && e <= r)
            return tree[n].val;
        return max(get(tree[n].l, s, (s + e) >> 1, l, r), get(tree[n].r, ((s + e) >> 1) + 1, e, l, r));
    }

  public:
    DynamicSeg(int N) : tree(N + 1) {}

    int update(int target, int val) { return update(1, -ADD + ADD, ADD + ADD, target, val); }
    int get(int l, int r) { return get(1, -ADD + ADD, ADD + ADD, l, r); }
};

int dp[MAX], arr[MAX], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N;

    DynamicSeg tree(MAX * 30);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sm[i] = sm[i - 1] + arr[i];
    }

    if (sm[N] < 0) {
        cout << -1 << endl;
        return 0;
    }

    tree.update(0 + ADD, 1);
    for (int i = 1; i <= N; i++) {
        K = tree.get(-ADD + ADD, sm[i] + ADD);
        if (K == 0)
            dp[i] = 0;
        else {
            dp[i] = K + 1;
            tree.update(sm[i] + ADD, dp[i]);
        }
    }

    cout << N - (dp[N] - 1);

    return 0;
}