#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 700001;

int R[MAX][3], B[MAX][3], LQ[MAX], RQ[MAX], ans[MAX],
    tree[MAX * 4];
vector<int> queries[MAX];
vector<pr> arr, val[MAX];

void dnc(int l, int r, vector<int> &rval, vector<int> &bval) {
    if (l == r)
        return;

    int m = l + r >> 1, XR = 0, XB = 0;
    vector<int> rarr, barr;

    for (int i : rval)
        if (R[i][1] <= m)
            rarr.push_back(i);
    for (int i : bval)
        if (B[i][1] > m)
            barr.push_back(i);

    for (int i : rarr)
        if (R[i][2] > R[XR][2])
            XR = i;
    for (int i : barr)
        if (B[i][2] > B[XB][2])
            XB = i;

    for (int i : rarr)
        arr.push_back({i, XB});
    for (int i : barr)
        arr.push_back({XR, i});

    rarr.clear(), barr.clear();
    for (int i : rval)
        if (R[i][1] <= m)
            rarr.push_back(i);
    for (int i : bval)
        if (B[i][1] <= m)
            barr.push_back(i);
    dnc(l, m, rarr, barr);

    rarr.clear(), barr.clear();
    for (int i : rval)
        if (R[i][1] > m)
            rarr.push_back(i);
    for (int i : bval)
        if (B[i][1] > m)
            barr.push_back(i);
    dnc(m + 1, r, rarr, barr);
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = 0;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, SX, SY;
    vector<int> compX, compY, rval, bval;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> R[i][0] >> R[i][1] >> R[i][2], rval.push_back(i);
        compX.push_back(R[i][0]), compY.push_back(R[i][1]);
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i][0] >> B[i][1] >> B[i][2], bval.push_back(i);
        compX.push_back(B[i][0]), compY.push_back(B[i][1]);
    }

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> LQ[i] >> RQ[i];
        compX.push_back(LQ[i]), compX.push_back(RQ[i]);
    }

    sort(compX.begin(), compX.end()), compX.erase(unique(compX.begin(), compX.end()), compX.end()), SX = compX.size();
    sort(compY.begin(), compY.end()), compY.erase(unique(compY.begin(), compY.end()), compY.end()), SY = compY.size();

    for (int i = 1; i <= N; i++) {
        R[i][0] = lower_bound(compX.begin(), compX.end(), R[i][0]) - compX.begin() + 1;
        R[i][1] = lower_bound(compY.begin(), compY.end(), R[i][1]) - compY.begin() + 1;
        B[i][0] = lower_bound(compX.begin(), compX.end(), B[i][0]) - compX.begin() + 1;
        B[i][1] = lower_bound(compY.begin(), compY.end(), B[i][1]) - compY.begin() + 1;
    }

    for (int i = 1; i <= Q; i++) {
        LQ[i] = lower_bound(compX.begin(), compX.end(), LQ[i]) - compX.begin() + 1;
        RQ[i] = lower_bound(compX.begin(), compX.end(), RQ[i]) - compX.begin() + 1;
        queries[LQ[i]].push_back(i);
    }

    dnc(1, SY, rval, bval);

    for (pr i : arr)
        val[R[i[0]][0]].push_back({B[i[1]][0], R[i[0]][2] + B[i[1]][2]});

    init(1, 1, SX);
    for (int i = 1; i <= SX; i++) {
        for (int j : queries[i])
            ans[j] = max(ans[j], query(1, 1, SX, RQ[j] + 1, SX));
        for (pr j : val[i])
            update(1, 1, SX, j[0], j[1]);
    }

    init(1, 1, SX);
    for (int i = SX; i >= 1; i--) {
        for (int j : queries[i])
            ans[j] = max(ans[j], query(1, 1, SX, 1, RQ[j] - 1));
        for (pr j : val[i])
            update(1, 1, SX, j[0], j[1]);
    }

    for (int i = 1; i <= Q; i++)
        cout << (ans[i] == 0 ? -1 : ans[i]) << '\n';

    return 0;
}