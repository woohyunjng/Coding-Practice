#include <bits/stdc++.h>
#define int long long

#define MAX 400000

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;

int R[MAX], H[MAX], A[MAX], B[MAX], ans[MAX], tree[MAX * 4], num[MAX];
vector<int> arr[MAX], queries[MAX];

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = max(tree[n], v);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return max(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, SX, SY, X;
    vector<int> Xcomp, Ycomp;

    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> R[i] >> H[i], Xcomp.push_back(-R[i]), Ycomp.push_back(H[i]);
    for (int i = 1; i <= Q; i++)
        cin >> A[i] >> B[i], Xcomp.push_back(-A[i]), Ycomp.push_back(B[i]);

    sort(Xcomp.begin(), Xcomp.end()), Xcomp.erase(unique(Xcomp.begin(), Xcomp.end()), Xcomp.end()), SX = Xcomp.size();
    sort(Ycomp.begin(), Ycomp.end()), Ycomp.erase(unique(Ycomp.begin(), Ycomp.end()), Ycomp.end()), SY = Ycomp.size();

    for (int i = 1; i <= N; i++) {
        R[i] = lower_bound(Xcomp.begin(), Xcomp.end(), -R[i]) - Xcomp.begin() + 1;
        H[i] = lower_bound(Ycomp.begin(), Ycomp.end(), H[i]) - Ycomp.begin() + 1;
        arr[R[i]].push_back(i);
    }

    for (int i = 1; i <= Q; i++) {
        A[i] = lower_bound(Xcomp.begin(), Xcomp.end(), -A[i]) - Xcomp.begin() + 1;
        B[i] = lower_bound(Ycomp.begin(), Ycomp.end(), B[i]) - Ycomp.begin() + 1;
        queries[A[i]].push_back(i);
    }

    for (int i = 1; i <= SX; i++) {
        sort(arr[i].begin(), arr[i].end(), [&](int x, int y) { return H[x] < H[y]; });
        for (int j : arr[i]) {
            num[j] = query(1, 1, SY, 1, H[j]) + 1;
            update(1, 1, SY, H[j], num[j]);
        }
        for (int j : queries[i])
            ans[j] = query(1, 1, SY, 1, B[j]);
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}