#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class FenwickTree {
  public:
    int N;
    vector<int> arr, tree;

    FenwickTree(int n) : N(n), arr(n + 1, 0), tree(n + 1, 0) {}

    void build() {
        for (int i = 1; i <= N; i++) {
            tree[i] += arr[i];
            if (i + (i & -i) <= N)
                tree[i + (i & -i)] += tree[i];
        }
    }

    void update(int n, int val) {
        arr[n] += val;
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

int res[MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    vector<pr> arr;

    cin >> N;
    FenwickTree tree(N);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        arr.push_back({A[i], i}), tree.arr[i] = 1;
    }
    sort(arr.begin(), arr.end()), tree.build();

    for (pr i : arr) {
        res[i.first + 1] += tree.query(1, i.second - 1);
        tree.update(i.second, -1);
    }

    cout << res[0] << '\n';
    for (int i = 1; i < N; i++) {
        res[i] += res[i - 1];
        cout << res[i] << '\n';
    }

    return 0;
}