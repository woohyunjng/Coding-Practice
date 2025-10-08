#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int N, A[MAX], D[MAX], ans;

struct Node {
    int l = -1, r = -1, val = 0;

    Node() : l(-1), r(-1), val(0) {};
    Node(int l, int r, int val) : l(l), r(r), val(val) {};
};

vector<Node> tree;
vector<int> root;

void init(int n, int s, int e) {
    if (s ^ e) {
        int m = s + e >> 1;
        tree[n].l = tree.size(), tree.push_back(Node());
        tree[n].r = tree.size(), tree.push_back(Node());

        init(tree[n].l, s, m), init(tree[n].r, m + 1, e);
    }
}

int query(int n, int s, int e, int v) {
    if (s == e)
        return A[s];
    else {
        int m = s + e >> 1;
        if (v <= tree[tree[n].l].val)
            return query(tree[n].l, s, m, v);
        else
            return query(tree[n].r, m + 1, e, v - tree[tree[n].l].val);
    }
}

void update(int n, int s, int e, int x, int v) {
    tree[n].val += v;
    if (s == e)
        return;
    int m = s + e >> 1;
    if (x <= m) {
        tree.push_back(Node(tree[tree[n].l].l, tree[tree[n].l].r, tree[tree[n].l].val));
        tree[n].l = (int)tree.size() - 1;
        update(tree[n].l, s, m, x, v);
    } else {
        tree.push_back(Node(tree[tree[n].r].l, tree[tree[n].r].r, tree[tree[n].r].val));
        tree[n].r = (int)tree.size() - 1;
        update(tree[n].r, m + 1, e, x, v);
    }
}

void dnc(int l, int r) {
    int x, vl = root[l - 1], vr = root[r], val = (l + r >> 1) - l + 1, s = 1, e = N, m;
    if (l >= r)
        return;
    ans += r - l + 1;

    while (s ^ e) {
        m = s + e >> 1;
        if (tree[tree[vr].l].val - tree[tree[vl].l].val >= val)
            vr = tree[vr].l, vl = tree[vl].l, e = m;
        else
            val -= tree[tree[vr].l].val - tree[tree[vl].l].val, vr = tree[vr].r, vl = tree[vl].r, s = m + 1;
    }

    x = A[s];
    dnc(l, x - 1), dnc(x + 1, r);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], D[A[i]] = i;

    tree.push_back(Node()), root.push_back(0), init(root[0], 1, N);

    for (int i = 1; i <= N; i++) {
        tree.push_back(Node(tree[root.back()].l, tree[root.back()].r, tree[root.back()].val)), root.push_back((int)tree.size() - 1);
        update(root.back(), 1, N, D[i], 1);
    }

    dnc(1, N);

    cout << ans << '\n';

    return 0;
}