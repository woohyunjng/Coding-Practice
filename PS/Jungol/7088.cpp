#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 600000;

int N, A[MAX];
vector<int> tree[MAX * 4];

void init() {
    for (int i = 1; i <= N; i++)
        tree[i + N - 1].push_back(A[i]);

    for (int i = N - 1; i > 0; i--) {
        tree[i].resize(tree[i << 1].size() + tree[i << 1 | 1].size());
        merge(tree[i << 1].begin(), tree[i << 1].end(), tree[i << 1 | 1].begin(), tree[i << 1 | 1].end(), tree[i].begin());
    }
}

int query(int l, int r, int k) {
    int res = 0;
    for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res += upper_bound(tree[l].begin(), tree[l].end(), k) - tree[l].begin(), l++;
        if (r & 1)
            --r, res += upper_bound(tree[r].begin(), tree[r].end(), k) - tree[r].begin();
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, X, Y, Z, st, en, md, ans;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    init();

    while (M--) {
        cin >> X >> Y >> Z;
        st = -1000000000, en = 1000000000;

        while (st <= en) {
            md = st + en >> 1;
            if (query(X, Y, md) >= Z)
                ans = md, en = md - 1;
            else
                st = md + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}