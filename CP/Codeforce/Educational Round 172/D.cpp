#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class SegTree {
  public:
    int N;
    vector<int> tree;

    SegTree(int n) : N(n), tree(n * 2 + 1, -INF) {}

    int query(int l, int r) {
        int res = -INF;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = max(res, tree[l++]);
            if (r & 1)
                res = max(res, tree[--r]);
        }
        return res;
    }

    void update(int pos, int val) {
        for (tree[pos += N - 1] = val; pos > 1; pos >>= 1)
            tree[pos >> 1] = max(tree[pos], tree[pos ^ 1]);
    }
};

int res[MAX], L[MAX], R[MAX];

void solve() {
    int N, X, Y;
    cin >> N;

    vector<tp> arr;
    vector<int> comp;
    multiset<int> st;
    multiset<int>::iterator it;

    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        arr.push_back({L[i], -R[i], i});
        comp.push_back(R[i]);
    }
    sort(arr.begin(), arr.end());
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());

    SegTree tree(comp.size());

    fill(res, res + N + 1, 0);

    for (tp i : arr) {
        it = st.lower_bound(R[i[2]]);
        if (it != st.end()) {
            X = *it;
            Y = tree.query(lower_bound(comp.begin(), comp.end(), R[i[2]]) - comp.begin() + 1, comp.size());
            if (Y != -INF)
                res[i[2]] = X - R[i[2]] + L[i[2]] - Y;
        }
        st.insert(R[i[2]]);
        tree.update(lower_bound(comp.begin(), comp.end(), R[i[2]]) - comp.begin() + 1, L[i[2]]);
    }

    for (int i = 0; i < N; i++) {
        while (i < N - 1 && arr[i][0] == arr[i + 1][0] && arr[i][1] == arr[i + 1][1]) {
            res[arr[i][2]] = res[arr[i + 1][2]] = 0;
            i++;
        }
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}