#include <bits/stdc++.h>
#define int long long
#define MAX 100100
#define MAX_VAL 30000

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 4> tp;

class SegTree {
  private:
    int query(int n, int s, int e, int l, int r) {
        if (l <= s && e <= r)
            return tree[n];
        else if (r < s || e < l)
            return 0;
        else {
            int lv = query(n << 1, s, ((s + e) >> 1), l, r);
            int rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
            return lv + rv;
        }
    }

    void update(int n, int s, int e, int l, int r, int val) {
        if (r < s || e < l)
            return;
        else if (l <= s && e <= r) {
            cnt[n] += val;
        } else {
            update(n << 1, s, (s + e) >> 1, l, r, val);
            update(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r, val);
        }

        if (cnt[n] > 0)
            tree[n] = e - s + 1;
        else
            tree[n] = (s == e) ? 0 : tree[n << 1] + tree[n << 1 | 1];
    }

  public:
    int N;
    vector<int> arr, tree, cnt;

    SegTree(int n) : N(n), tree(n * 4 + 1, 0), cnt(n * 4 + 1, 0) {}

    int query(int pos) { return query(1, 1, N, pos, pos); }
    int query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int l, int r, int val) { update(1, 1, N, l, r, val); }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, C, D, res = 0, diff = 0;
    vector<tp> arr;
    SegTree st(MAX_VAL + 1);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B >> C >> D;
        arr.push_back({A, B + 1, D, 1});
        arr.push_back({C, B + 1, D, -1});
    }
    sort(arr.begin(), arr.end());

    st.update(arr[0][1], arr[0][2], arr[0][3]);

    for (int i = 1; i < N * 2; i++) {
        diff = arr[i][0] - arr[i - 1][0];
        res += diff * st.query(1, MAX_VAL);
        st.update(arr[i][1], arr[i][2], arr[i][3]);
    }

    cout << res;

    return 0;
}