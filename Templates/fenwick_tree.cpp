#include <bits/stdc++.h>
#define int long long
#define MAX 1000000
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;

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