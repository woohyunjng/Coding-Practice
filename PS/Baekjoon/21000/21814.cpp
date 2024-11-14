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

int B[MAX], X[MAX];
vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        arr[B[i]].push_back(i), X[i] = -1;
    }

    FenwickTree tree(N);

    for (int i = 1; i <= N; i++) {
        if (X[B[i]] != -1)
            tree.update(arr[B[i]][X[B[i]]], -1);
        ++X[B[i]], tree.update(arr[B[i]][X[B[i]]], 1);
        res += tree.query(X[B[i]] == 0 ? 1 : arr[B[i]][X[B[i]] - 1], arr[B[i]][X[B[i]]] - 1);
    }

    cout << res << '\n';

    return 0;
}