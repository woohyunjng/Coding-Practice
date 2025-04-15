#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int D[MAX], A[MAX], tree[MAX * 4], lazy[MAX * 4];
vector<int> arr[MAX];

void init(int n, int s, int e) {
    lazy[n] = tree[n] = 0;
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] += v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = min(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return MAX;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return min(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    bool ans;

    vector<int> comp;

    cin >> T;
    while (T--) {
        cin >> N, ans = true, comp.clear();
        init(1, 1, N);

        for (int i = 1; i <= N; i++)
            cin >> A[i], arr[i].clear(), comp.push_back(A[i]);

        sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
        for (int i = 1; i <= N; i++) {
            A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;
            D[i] = arr[A[i]].size(), arr[A[i]].push_back(i);
        }

        function<void(int, int, int)> modify = [&](int t, int d, int v) {
            if (t >= arr[d].size())
                return;
            else if (t + 1 == arr[d].size())
                update(1, 1, N, arr[d][t], N, v);
            else
                update(1, 1, N, arr[d][t], arr[d][t + 1] - 1, v);
        };

        for (int i = N; i >= 1; i--) {
            modify(D[i], A[i], 1), modify(D[i] + 1, A[i], -1);
            ans &= query(1, 1, N, i, N) > 0;
        }

        cout << (ans ? "non-boring" : "boring") << '\n';
    }

    return 0;
}