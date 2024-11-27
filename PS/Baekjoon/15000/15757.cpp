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

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 1, X;
    cin >> N;

    FenwickTree tree(N);
    vector<pr> arr;

    for (int i = 1; i <= N; i++)
        cin >> A[i], arr.push_back({A[i], i});
    sort(arr.begin(), arr.end());

    for (int i = 1; i <= N; i++) {
        tree.update(arr[i - 1].second, 1);
        X = tree.query(1, i);
        res = max({res, i - X});
    }

    cout << res << '\n';

    return 0;
}