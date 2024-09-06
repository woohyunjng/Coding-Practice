#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class MinSegTree {
  public:
    int N;
    vector<int> tree;

    MinSegTree(int n) : N(n), tree(n * 2 + 1, INF) {}

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

class MaxSegTree {
  public:
    int N;
    vector<int> tree;

    MaxSegTree(int n) : N(n), tree(n * 2 + 1, 0) {}

    int query(int l, int r) {
        int res = 0;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = max(res, tree[l++]);
            if (r & 1)
                res = max(res, tree[--r]);
        }
        return res;
    }

    int query(int pos) { return query(pos, pos); }
    void update(int pos, int val) {
        for (tree[pos += N - 1] += val; pos > 1; pos >>= 1)
            tree[pos >> 1] = max(tree[pos], tree[pos ^ 1]);
    }
};

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, Q, L, R;
    cin >> T;

    while (T--) {
        cin >> N >> K >> Q;

        MaxSegTree max_tree(N * 2);
        MinSegTree min_tree(N);

        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        for (int i = 1; i <= K; i++)
            max_tree.update(arr[i] - i + N, 1);
        min_tree.update(K, K - max_tree.query(1, N * 2));

        for (int i = K + 1; i <= N; i++) {
            max_tree.update(arr[i] - i + N, 1);
            max_tree.update(arr[i - K] - (i - K) + N, -1);
            min_tree.update(i, K - max_tree.query(1, N * 2));
        }

        while (Q--) {
            cin >> L >> R;
            cout << min_tree.query(R, R) << '\n';
        }
    }

    return 0;
}