#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int K, tree[MAX * 2 + 1];

int query(int l, int r) {
    int res = INF;
    for (l += K - 1, r += K; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = min(res, tree[l++]);
        if (r & 1)
            res = min(res, tree[--r]);
    }
    return res;
}

void update(int pos, int val) {
    for (tree[pos += K - 1] = val; pos > 1; pos >>= 1)
        tree[pos >> 1] = min(tree[pos], tree[pos ^ 1]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X, L, R, Y, res = 0;
    vector<tp> arr;
    vector<int> tr;

    cin >> T;
    while (T--) {
        cin >> N >> K, arr.clear(), tr.clear();
        fill(tree, tree + K * 2 + 1, INF);

        for (int i = 1; i <= N; i++)
            cin >> X, arr.push_back({X, 0, 0}), tr.push_back(X);
        sort(tr.begin(), tr.end());

        for (int i = 1; i <= K; i++) {
            cin >> L >> R >> Y;
            Y = upper_bound(tr.begin(), tr.end(), R) - lower_bound(tr.begin(), tr.end(), L) - Y;
            arr.push_back({L, -i, Y});
            arr.push_back({R, i, Y});
        }
        sort(arr.begin(), arr.end()), res = 0;

        for (tp i : arr) {
            if (i[1] < 0)
                update(-i[1], i[2] + res);
            else if (i[1] > 0)
                update(i[1], INF);
            else if (query(1, K) > res)
                res++;
        }

        cout << res << '\n';
    }

    return 0;
}