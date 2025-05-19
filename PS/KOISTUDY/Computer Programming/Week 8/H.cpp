#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

vector<int> tree[MAX * 2];
int N, A[MAX];

void init() {
    for (int i = 1; i <= N; i++)
        tree[i + N - 1].push_back(A[i]);
    for (int i = N - 1; i >= 1; i--) {
        tree[i].resize(tree[i << 1].size() + tree[i << 1 | 1].size());
        merge(tree[i << 1].begin(), tree[i << 1].end(), tree[i << 1 | 1].begin(), tree[i << 1 | 1].end(), tree[i].begin());
    }
}

int query(int l, int r, int x) {
    int ret = 0;
    for (l += N - 1, r += N - 1; l <= r; l >>= 1, r >>= 1) {
        if (l & 1)
            ret += upper_bound(tree[l].begin(), tree[l].end(), x) - tree[l].begin(), l++;
        if (!(r & 1))
            ret += upper_bound(tree[r].begin(), tree[r].end(), x) - tree[r].begin(), r--;
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, L, R, K, st, en, md, ans;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    init();

    while (Q--) {
        cin >> L >> R >> K;
        st = -1e8, en = 1e8;
        while (st <= en) {
            md = st + en >> 1;
            if (query(L, R, md) >= K)
                ans = md, en = md - 1;
            else
                st = md + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}