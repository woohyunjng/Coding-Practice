#include <bits/stdc++.h>
#define int long long

#define MAX 100000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX + 1], divide_sm[MAX + 1];

class FenwickTree {
  public:
    int N;
    vector<pr> tree;

    FenwickTree(int n) : N(n), tree(n + 1, {0, 0}) {}

    void update(int n, int val) {
        int K = n * val;

        while (n <= N) {
            tree[n].first += val;
            tree[n].second += K;
            n += n & -n;
        }
    }

    pr query(int n) {
        pr res = {0, 0};
        while (n) {
            res.first += tree[n].first;
            res.second += tree[n].second;
            n -= n & -n;
        }
        return res;
    }

    pr query(int l, int r) {
        pr left = query(l - 1), right = query(r);
        return {right.first - left.first, right.second - left.second};
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, X, Y, sm = 0;
    cin >> N;

    FenwickTree tree(MAX);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sm += A[i], tree.update(A[i], 1);

        for (int j = 1; j * j <= MAX; j++) {
            divide_sm[j] += A[i] / j;
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> X;

            if (X * X <= MAX)
                Y = divide_sm[X];
            else {
                Y = 0;
                for (int i = 1; i * X <= MAX; i++)
                    Y += tree.query(i * X, MAX).first;
            }

            cout << sm - X * Y << '\n';
        } else if (T == 2) {
            cin >> X;

            Y = 0;

            for (int i = 1; i * i <= X; i++) {
                if (X / i != i)
                    Y += i * tree.query(i, i).first * (X / i);
                Y += tree.query(X / (i + 1) + 1, X / i).second * i;
            }

            cout << X * N - Y << '\n';
        } else {
            cin >> X >> Y;
            sm += Y - A[X];

            tree.update(A[X], -1);
            tree.update(Y, 1);

            for (int i = 1; i * i <= MAX; i++)
                divide_sm[i] += Y / i - A[X] / i;

            A[X] = Y;
        }
    }

    return 0;
}