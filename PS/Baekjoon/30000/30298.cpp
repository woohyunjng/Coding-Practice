#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class FenwickTree {
  public:
    int N;
    vector<int> tree;

    FenwickTree(int n) : N(n), tree(n + 1, 0) {}

    void update(int n, int val) {
        while (n <= N) {
            tree[n] += val;
            n += n & -n;
        }
    }

    int query(int n) {
        int res = 0;
        while (n) {
            res += tree[n];
            n -= n & -n;
        }
        return res;
    }

    int query(int l, int r) { return query(r) - query(l - 1); }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, res = 0;
    vector<pr> arr;
    vector<int> compX, compY;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X >> Y;
        arr.push_back({X - Y, X + Y});
        compX.push_back(X - Y), compY.push_back(X + Y);
    }

    FenwickTree tree[4] = {FenwickTree(N), FenwickTree(N), FenwickTree(N), FenwickTree(N)};

    res = N * (N - 1) / 2 * (N - 2) / 3;

    sort(compX.begin(), compX.end()), sort(compY.begin(), compY.end());
    compX.erase(unique(compX.begin(), compX.end()), compX.end()), compY.erase(unique(compY.begin(), compY.end()), compY.end());

    sort(arr.begin(), arr.end(), [](pr a, pr b) { return a.first == b.first ? a.second > b.second : a.first < b.first; });

    for (pr i : arr) {
        X = lower_bound(compX.begin(), compX.end(), i.first) - compX.begin() + 1;
        Y = lower_bound(compY.begin(), compY.end(), i.second) - compY.begin() + 1;

        tree[0].update(Y, 1);
        tree[1].update(Y, tree[0].query(1, Y - 1));
        res -= tree[1].query(1, Y - 1);
    }

    sort(arr.begin(), arr.end());

    for (pr i : arr) {
        X = lower_bound(compX.begin(), compX.end(), i.first) - compX.begin() + 1;
        Y = lower_bound(compY.begin(), compY.end(), i.second) - compY.begin() + 1;

        tree[2].update(Y, 1);
        tree[3].update(Y, tree[2].query(Y + 1, N));
        res -= tree[3].query(Y + 1, N);
    }

    cout << res << '\n';

    return 0;
}