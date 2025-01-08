#include <bits/stdc++.h>
#define int long long

#define MAX 100100

using namespace std;
typedef array<int, 3> tp;
typedef array<int, 4> tp4;

int N, tree[MAX * 2];

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

void update(int x, int v) {
    for (tree[x += N - 1] = v; x > 1; x >>= 1)
        tree[x >> 1] = max(tree[x], tree[x ^ 1]);
}

int A[MAX], idx[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, L, R;

    vector<tp> arr;
    vector<int> comp;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back(A[i]);
    sort(comp.begin(), comp.end());

    for (int i = 1; i <= N; i++)
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1, update(i, A[i]);

    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> L >> R, arr.push_back({L, R, i});

    sort(arr.begin(), arr.end(), [&](tp a, tp b) {
        int X, Y;

        if (a[0] == b[0])
            return a[1] < b[1];
        else if (a[0] < b[0]) {
            if (b[1] <= a[1])
                return false;
            else
                X = query(a[0], min(a[1], b[0] - 1)), Y = query(max(a[1] + 1, b[0]), b[1]);
        } else {
            if (a[1] <= b[1])
                return true;
            else
                X = query(max(b[1] + 1, a[0]), a[1]), Y = query(b[0], min(b[1], a[0] - 1));
        }
        return X < Y;
    });

    for (int i = 1; i <= Q; i++)
        cout << arr[i - 1][2] << ' ';
    cout << '\n';

    return 0;
}