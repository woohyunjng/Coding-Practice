#include <bits/stdc++.h>
#define int long long

#define MAX 300000
using namespace std;

int N, tree[MAX * 4], A[MAX];

int merge(int X, int Y) {
    if (A[X] < A[Y])
        return Y;
    return X;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = s;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

vector<int> ans;

void dnc(int l, int r, int v) {
    if (l > r)
        return;
    int x = query(1, 1, N, l, r);
    bool flag = false;
    flag |= x != l && A[x - 1] < A[x];
    flag |= x != r && A[x + 1] < A[x];

    if (!flag) {
        while (x + 1 != r && A[x + 1] == A[x])
            x++;
        flag |= x != r && A[x + 1] < A[x];
    }

    flag &= (A[x] + r - l) > v;

    if (!flag)
        return;
    ans.push_back(x);
    dnc(l, x - 1, max(v - r + x - 1, A[x])), dnc(x + 1, r, max(v - x + l - 1, A[x]));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    init(1, 1, N);

    dnc(1, N, 0);

    if (N == 1)
        ans.push_back(1);

    sort(ans.begin(), ans.end());
    if (ans.empty()) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}