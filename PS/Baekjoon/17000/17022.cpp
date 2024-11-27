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

int P[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> P[i], A[P[i]] = i;

    FenwickTree tree(N);

    P[N + 1] = N + 1;
    for (int i = N; i >= 1; i--) {
        if (P[i] > P[i + 1]) {
            X = i;
            break;
        }
        tree.update(P[i], 1);
    }

    cout << X << '\n';
    for (int i = 1; i <= X; i++) {
        cout << X - i + tree.query(1, P[i]) << ' ';
        tree.update(P[i], 1);
    }

    return 0;
}