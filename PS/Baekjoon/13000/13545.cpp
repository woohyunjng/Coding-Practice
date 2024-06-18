#include <bits/stdc++.h>
#define int long long
#define MAX 100100
#define MAX_VAL 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], ans[MAX];
deque<int> dq[MAX_VAL];

class SegTree {
  public:
    int N, tree[2 * MAX_VAL + 1] = {};

    SegTree(int n) : N(n) {}

    int query(int l, int r) {
        int res = 0;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = max(res, tree[l++]);
            if (r & 1)
                res = max(res, tree[--r]);
        }
        return res;
    }
    int query(int pos) { return tree[pos + N - 1]; }
    void update(int pos, int val) {
        for (tree[pos += N - 1] = val; pos > 1; pos >>= 1)
            tree[pos >> 1] = max(tree[pos], tree[pos ^ 1]);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, S, A, B, l, r, nl, nr;
    vector<tp> query;
    vector<int> num;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A;
        arr[i] = arr[i - 1] + A;
    }

    for (int i = 0; i <= N; i++)
        arr[i] += N + 1;

    cin >> M;
    S = sqrt(M);

    for (int i = 1; i <= M; i++) {
        cin >> A >> B;
        query.push_back({A - 1, B, i});
    }

    sort(query.begin(), query.end(), [S](tp a, tp b) {
        int af = a[0] / S, bf = b[0] / S;
        if (af == bf)
            return a[1] / S < b[1] / S;
        return af < bf;
    });

    SegTree tree(N * 2 + 1);

    for (int i = query[0][0]; i <= query[0][1]; i++) {
        dq[arr[i]].push_back(i);
        if (dq[arr[i]].size() >= 2)
            tree.update(arr[i], dq[arr[i]].back() - dq[arr[i]].front());
    }

    ans[query[0][2]] = tree.query(1, N * 2 + 1);
    nl = query[0][0], nr = query[0][1];

    for (int i = 1; i < M; i++) {
        l = query[i][0], r = query[i][1];
        while (nl > l) {
            nl--;
            dq[arr[nl]].push_front(nl);
            if (dq[arr[nl]].size() >= 2)
                tree.update(arr[nl], dq[arr[nl]].back() - dq[arr[nl]].front());
        }
        while (nr < r) {
            nr++;
            dq[arr[nr]].push_back(nr);
            if (dq[arr[nr]].size() >= 2)
                tree.update(arr[nr], dq[arr[nr]].back() - dq[arr[nr]].front());
        }
        while (nl < l) {
            dq[arr[nl]].pop_front();
            if (dq[arr[nl]].size() == 1)
                tree.update(arr[nl], 0);
            else if (dq[arr[nl]].size() >= 2)
                tree.update(arr[nl], dq[arr[nl]].back() - dq[arr[nl]].front());
            nl++;
        }
        while (nr > r) {

            dq[arr[nr]].pop_back();
            if (dq[arr[nr]].size() == 1)
                tree.update(arr[nr], 0);
            else if (dq[arr[nr]].size() >= 2)
                tree.update(arr[nr], dq[arr[nr]].back() - dq[arr[nr]].front());
            nr--;
        }
        ans[query[i][2]] = tree.query(1, N * 2 + 1);
    }

    for (int i = 1; i <= M; i++)
        cout << ans[i] << '\n';

    return 0;
}
