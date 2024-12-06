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

int A[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, res = 0;
    cin >> N;

    FenwickTree tree(N * 2);
    vector<pr> arr;

    for (int i = 1; i <= N * 2; i++) {
        cin >> X;
        if (A[X][0] == 0)
            A[X][0] = i;
        else
            A[X][1] = i;
    }

    for (int i = 1; i <= N; i++)
        arr.push_back({A[i][0], A[i][1]});
    sort(arr.begin(), arr.end());

    for (pr i : arr) {
        res += tree.query(i.first, i.second);
        tree.update(i.second, 1);
    }

    cout << res << '\n';

    return 0;
}