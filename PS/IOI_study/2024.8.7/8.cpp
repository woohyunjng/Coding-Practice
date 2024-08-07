#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 99999999
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class MergeSortTree {
  public:
    int N;
    vector<int> arr;
    vector<vector<int>> tree;

    MergeSortTree(int n) : N(n), arr(n + 1), tree(n * 2 + 1) {}

    void init() {
        for (int i = 1; i <= N; i++)
            tree[i + N - 1].push_back(arr[i]);

        for (int i = N - 1; i > 0; --i) {
            tree[i].resize(tree[i << 1].size() + tree[i << 1 | 1].size());
            merge(tree[i << 1].begin(), tree[i << 1].end(), tree[i << 1 | 1].begin(), tree[i << 1 | 1].end(), tree[i].begin());
        }
    }

    int query(int l, int r, int k) {
        int res = 0;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res += lower_bound(tree[l].begin(), tree[l].end(), k) - tree[l].begin(), ++l;
            if (r & 1)
                --r, res += lower_bound(tree[r].begin(), tree[r].end(), k) - tree[r].begin();
        }
        return res;
    }
    int query(int pos, int k) { return query(pos, pos, k); }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, C, res = 0;
    cin >> N >> Q;

    MergeSortTree tree(N);
    for (int i = 1; i <= N; i++)
        cin >> tree.arr[i];
    tree.init();

    for (int i = 1; i <= Q; i++) {
        cin >> A >> B >> C;
        res = tree.query(A, B, (C + res * i) % MOD + 1);
        cout << res << '\n';
    }

    return 0;
}