#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class MergeSortTree {
  public:
    int N;
    vector<int> arr;
    vector<vector<int>> tree;

    MergeSortTree(int n) : N(n), arr(n + 1), tree(n * 2 + 1) {}

    void init() {
        for (int i = 1; i <= N; i++)
            tree[i + N - 1].push_back(arr[i]);

        for (int i = N - 1; i > 0; --i) {
            tree[i].resize(tree[i << 1].size() + tree[i << 1 | 1].size());
            merge(tree[i << 1].begin(), tree[i << 1].end(), tree[i << 1 | 1].begin(), tree[i << 1 | 1].end(), tree[i].begin());
        }
    }

    int query(int l, int r, int k) {
        int res = 0;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res += tree[l].end() - lower_bound(tree[l].begin(), tree[l].end(), k), l++;
            if (r & 1)
                --r, res += tree[r].end() - lower_bound(tree[r].begin(), tree[r].end(), k);
        }
        return res;
    }

    int bin_search(int l, int r, int k, int x) {
        int st = l, en = r, md, res = -1;
        while (st < en) {
            md = (st + en) >> 1;
            if (query(l, md, k) >= x) {
                en = md;
                res = md;
            } else
                st = md + 1;
        }
        if (query(l, res, k) == x)
            return res;
        else
            return -1;
    }

    int query(int pos, int k) { return query(pos, pos, k); }
};

int arr[MAX];
bool query_res[MAX];
vector<pr> queries[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, A, X, Y, Z, K;

    cin >> N >> Q;

    MergeSortTree mst(N);

    for (int i = 1; i <= N; i++)
        cin >> mst.arr[i];

    mst.init();

    for (int i = 1; i <= Q; i++) {
        cin >> A >> X;
        queries[X].push_back({A, i});
    }

    for (int i = 1; i <= N; i++) {
        if (queries[i].empty())
            continue;
        sort(queries[i].begin(), queries[i].end());

        A = 1, X = 0;
        for (Y = 1; Y * i <= N && X < queries[i].size(); Y++) {
            K = mst.bin_search(A, N, Y, i);
            if (K == -1)
                break;
            A = K + 1;

            while (X < queries[i].size() && queries[i][X].first <= K) {
                query_res[queries[i][X].second] = mst.arr[queries[i][X].first] >= Y;
                X++;
            }
        }
        while (X < queries[i].size()) {
            query_res[queries[i][X].second] = mst.arr[queries[i][X].first] >= Y;
            X++;
        }
    }

    for (int i = 1; i <= Q; i++)
        cout << (query_res[i] ? "YES" : "NO") << '\n';

    return 0;
}