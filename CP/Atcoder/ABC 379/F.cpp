#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
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
                res += upper_bound(tree[l].begin(), tree[l].end(), k) - tree[l].begin(), ++l;
            if (r & 1)
                --r, res += upper_bound(tree[r].begin(), tree[r].end(), k) - tree[r].begin();
        }
        return res;
    }
    int query(int pos, int k) { return query(pos, pos, k); }
};

int H[MAX], val[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> H[i];

    stack<int> st;
    for (int i = N; i >= 1; i--) {
        while (!st.empty() && H[st.top()] < H[i])
            val[st.top()] = i, st.pop();
        st.push(i);
    }

    while (!st.empty())
        val[st.top()] = 0, st.pop();

    MergeSortTree tree(N);

    for (int i = 1; i <= N; i++)
        tree.arr[i] = val[i];
    tree.init();

    while (Q--) {
        cin >> L >> R;
        cout << tree.query(R + 1, N, L) << '\n';
    }

    return 0;
}