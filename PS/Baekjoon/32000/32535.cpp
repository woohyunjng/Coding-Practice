#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200000;
typedef array<int, 3> tp;

int A[MAX], tree[MAX * 4], cnt[MAX * 4];
vector<int> idx[MAX];
vector<tp> arr[MAX];

void init(int n, int s, int e) {
    tree[n] = cnt[n] = 0;
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        cnt[n] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
    }

    if (cnt[n] > 0)
        tree[n] = e - s + 1;
    else if (s == e)
        tree[n] = 0;
    else
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans = 0, val;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        idx[i].push_back(0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        idx[A[i]].push_back(i);
    }
    for (int i = 1; i <= N; i++)
        idx[i].push_back(N + 1);

    for (int i = 0; i < (1ll << K); i++) {
        init(1, 1, N), val = 0;
        for (int j = 1; j <= N; j++)
            arr[j].clear();

        for (int j = 0; j < K; j++) {
            if (!(i & (1ll << j)))
                continue;
            for (int k = 1; k <= N; k++) {
                if (idx[k].size() <= 2 + j)
                    continue;
                for (int l = 1; l + 1 + j < idx[k].size(); l++) {
                    arr[idx[k][l - 1] + 1].push_back({idx[k][l + j], idx[k][l + j + 1] - 1, 1});
                    arr[idx[k][l] + 1].push_back({idx[k][l + j], idx[k][l + j + 1] - 1, -1});
                }
            }
        }

        for (int j = 1; j <= N; j++) {
            for (tp k : arr[j])
                update(1, 1, N, k[0], k[1], k[2]);
            val += query(1, 1, N, 1, N);
        }

        ans += val * (__builtin_popcount(i) % 2 ? 1 : -1);
    }

    cout << ans << '\n';

    return 0;
}