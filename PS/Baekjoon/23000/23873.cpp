#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class SegTree {
  public:
    int N;
    vector<int> tree;

    SegTree(int n) : N(n), tree(n * 2 + 1, INF) {}

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

    void update(int pos, int val) {
        for (tree[pos += N - 1] = val; pos > 1; pos >>= 1)
            tree[pos >> 1] = min(tree[pos], tree[pos ^ 1]);
    }
};

int A[MAX], X[MAX], Y[MAX], res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;

    set<int> st;
    set<int>::iterator it;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        it = st.lower_bound(A[i]);
        X[i] = it == st.begin() ? 1 : *prev(it);
        st.insert(A[i]);
    }

    SegTree tree(N);

    for (int i = N; i >= 1; i--) {
        tree.update(A[i], i);
        K = tree.query(X[i], A[i] - 1);
        if (K != INF)
            res[A[K]]++, res[A[i]]--;
    }

    for (int i = 0; i <= N; i++) {
        res[i + 1] += res[i];
        cout << res[i] << '\n';
    }

    return 0;
}