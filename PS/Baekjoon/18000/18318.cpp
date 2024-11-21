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

    SegTree(int n) : N(n), tree(n * 2 + 1, 0) {}

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

    void update(int pos, int val) {
        for (tree[pos += N - 1] = val; pos > 1; pos >>= 1)
            tree[pos >> 1] = max(tree[pos], tree[pos ^ 1]);
    }
};

pr points[MAX];
int val[MAX], res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, P, X;

    vector<tp> arr;
    vector<int> comp;

    cin >> N >> P;

    for (int i = 1; i <= 2 * P; i += 2) {
        cin >> points[i].first >> points[i].second >> points[i + 1].first >> points[i + 1].second;
        val[i] = points[i + 1].first - points[i].first + points[i + 1].second - points[i].second;

        comp.push_back(points[i].second), comp.push_back(points[i + 1].second);

        arr.push_back({points[i].first, points[i].second, i});
        arr.push_back({points[i + 1].first, points[i + 1].second, i + 1});
    }
    comp.push_back(N);

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    sort(arr.begin(), arr.end());

    SegTree tree(2 * P + 1);

    for (tp i : arr) {
        X = lower_bound(comp.begin(), comp.end(), i[1]) - comp.begin() + 1;
        res[i[2]] = tree.query(1, X);
        if ((i[2] & 1) == 0)
            res[i[2]] = max(res[i[2]], val[i[2] - 1] + res[i[2] - 1]);
        tree.update(X, res[i[2]]);
    }

    cout << 2 * N - tree.query(1, comp.size()) << '\n';

    return 0;
}