#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

pr merge(pr a, pr b) {
    if (a.first > b.first)
        swap(a, b);
    return a;
}

class SegTree {
  public:
    int N;
    vector<pr> tree;

    SegTree(int n) : N(n), tree(n * 2 + 1, {INF, 0}) {}

    pr query(int l, int r) {
        pr res = {INF, 0};
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = merge(res, tree[l++]);
            if (r & 1)
                res = merge(res, tree[--r]);
        }
        return res;
    }

    void update(int pos, pr val) {
        for (tree[pos += N - 1] = val; pos > 1; pos >>= 1)
            tree[pos >> 1] = merge(tree[pos], tree[pos ^ 1]);
    }
};

int temp_arr[MAX][4];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, C, res = 0;
    pr K;

    cin >> N;

    vector<tp> arr;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A;
            temp_arr[A][i] = j;
        }
    }

    for (int i = 1; i <= N; i++)
        arr.push_back({N + 1 - temp_arr[i][1], N + 1 - temp_arr[i][2], N + 1 - temp_arr[i][3]});

    sort(arr.begin(), arr.end());

    SegTree tree(N);
    for (int i = 1; i <= N; i++) {
        A = arr[i - 1][1], B = arr[i - 1][2];

        while (true) {
            K = tree.query(1, A);
            if (K.first > B)
                break;
            tree.update(K.second, {INF, K.second});
            res--;
        }

        tree.update(A, {B, A});
        res++;
    }

    cout << res;

    return 0;
}