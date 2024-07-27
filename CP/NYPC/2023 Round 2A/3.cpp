#include <bits/stdc++.h>
#define int long long
#define MAX 300100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class SegTree {
  public:
    int N;
    vector<int> arr;
    vector<int> tree;

    SegTree(int n) : N(n), arr(n + 1, 0), tree(n * 2 + 1, 0) {}

    int query(int l, int r) {
        int res = 0;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = res + tree[l++];
            if (r & 1)
                res = res + tree[--r];
        }
        return res;
    }
    int query(int pos) { return query(pos, pos); }
    void update(int pos, int val) {
        for (tree[pos += N - 1] += val; pos > 1; pos >>= 1)
            tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
    }
};

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, S = 1, E, res = 0, X, val = 0;
    bool minus = false;

    cin >> N >> K;
    if (K < 0) {
        minus = true;
        K = -K;
    }

    vector<int> comp;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        comp.push_back(arr[i]);
        comp.push_back(arr[i] + K);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    SegTree tree_1(comp.size()), tree_2(comp.size());

    E = N;
    for (int i = N; i >= 1; i--) {
        X = lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin() + 1;
        res += tree_1.query(0, X);
        tree_1.update(X, 1);
    }
    val = res;

    for (int i = 1; i <= N; i++) {
        X = lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin() + 1;
        tree_1.update(X, -1);
        val -= tree_1.query(0, X);
        val -= tree_2.query(X, comp.size());

        X = lower_bound(comp.begin(), comp.end(), arr[i] + K) - comp.begin() + 1;
        val += tree_1.query(0, X);
        val += tree_2.query(X, comp.size());
        tree_2.update(X, 1);

        if (val > res) {
            res = val;
            E = i;
        }
    }

    if (minus) {
        if (E == N)
            S = 1, E = N;
        else
            S = E + 1, E = N;
    }
    cout << S << ' ' << E;

    return 0;
}