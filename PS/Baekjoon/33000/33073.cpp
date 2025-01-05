#include <bits/stdc++.h>
#define int long long

#define MAX 200100

using namespace std;
typedef pair<int, int> pr;

int X[MAX][2], Y[MAX][2];

class FenwickTree {
  public:
    int N;
    vector<pr> tree;

    FenwickTree(int n) : N(n), tree(n + 1, {0, 0}) {}

    void update(int n, pr val) {
        while (n <= N) {
            tree[n] = {tree[n].first + val.first, tree[n].second + val.second};
            n += n & -n;
        }
    }

    pr query(int n) {
        if (n < 0)
            return {0, 0};
        pr res = {0, 0};
        while (n) {
            res = {res.first + tree[n].first, res.second + tree[n].second};
            n -= n & -n;
        }
        return res;
    }

    pr query(int l, int r) {
        pr A = query(l - 1), B = query(r);
        return {B.first - A.first, B.second - A.second};
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, C;
    pr res;
    cin >> N >> Q;

    FenwickTree row(Q), col(Q);

    for (int i = 1; i <= Q; i++) {
        cin >> A >> B;
        if (A == 1) {
            cin >> C;
            if (X[B][0] != 0)
                row.update(X[B][0], {-1, -X[B][1]});
            X[B][0] = i, X[B][1] = C;
            row.update(i, {1, C});
        } else if (A == 2) {
            cin >> C;
            if (Y[B][0] != 0)
                col.update(Y[B][0], {-1, -Y[B][1]});
            Y[B][0] = i, Y[B][1] = C;
            col.update(i, {1, C});
        } else if (A == 3) {
            res = col.query(X[B][0], i);
            cout << (N - res.first) * X[B][1] + res.second << '\n';
        } else {
            res = row.query(Y[B][0], i);
            cout << (N - res.first) * Y[B][1] + res.second << '\n';
        }
    }

    return 0;
}