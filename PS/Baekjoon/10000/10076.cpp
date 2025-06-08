#include <bits/stdc++.h>
#define ll long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 100001;

struct Node {
    int l = -1, r = -1, cnt = 0;
    ll sm = 0;

    Node() : l(-1), r(-1), cnt(0), sm(0ll) {};
    Node(int l, int r, int cnt, ll sm) : l(l), r(r), cnt(cnt), sm(sm) {};
};

int A[MAX], ST, S, D;
ll ans = 0;

vector<Node> tree;
vector<int> root, comp;

void init(int n, int s, int e) {
    if (s ^ e) {
        int m = s + e >> 1;
        tree[n].l = tree.size(), tree.push_back(Node());
        tree[n].r = tree.size(), tree.push_back(Node());
        init(tree[n].l, s, m), init(tree[n].r, m + 1, e);
    }
}

void update(int n, int s, int e, int x, ll v) {
    tree[n].cnt++, tree[n].sm += v;
    if (s == e)
        return;
    int m = s + e >> 1;
    if (x <= m) {
        tree.push_back(Node(tree[tree[n].l].l, tree[tree[n].l].r, tree[tree[n].l].cnt, tree[tree[n].l].sm));
        tree[n].l = tree.size() - 1;
        update(tree[n].l, s, m, x, v);
    } else {
        tree.push_back(Node(tree[tree[n].r].l, tree[tree[n].r].r, tree[tree[n].r].cnt, tree[tree[n].r].sm));
        tree[n].r = tree.size() - 1;
        update(tree[n].r, m + 1, e, x, v);
    }
}

ll get(int l, int r, int k) {
    int st = 1, en = S, md;
    ll res = 0;
    Node ln = tree[root[l - 1]], rn = tree[root[r]];
    k = min(k, r - l + 1);

    while (st < en) {
        md = st + en >> 1;
        if (tree[rn.r].cnt - tree[ln.r].cnt >= k)
            st = md + 1, ln = tree[ln.r], rn = tree[rn.r];
        else
            en = md, res += tree[rn.r].sm - tree[ln.r].sm, k -= tree[rn.r].cnt - tree[ln.r].cnt, ln = tree[ln.l], rn = tree[rn.l];
    }

    res += (ll)comp[st - 1] * min(k, rn.cnt - ln.cnt);
    return res;
}

void dnc(int l, int r, int s, int e) {
    if (l > r)
        return;
    int m = l + r >> 1, opt = s, K;
    ll res = 0, G;

    for (int i = s; i <= e; i++) {
        G = get(min(m, i), max(m, i), max(0, D - abs(m - ST) - abs(i - ST) * 2));
        if (G > res)
            res = G, opt = i;
    }

    ans = max(ans, res);
    dnc(l, m - 1, s, opt), dnc(m + 1, r, opt, e);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N >> ST >> D, ST++;
    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back(A[i]);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 1; i <= N; i++)
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;

    tree.reserve(2000000), root.reserve(N + 1);
    tree.push_back(Node()), root.push_back(0), init(root[0], 1, S);
    for (int i = 1; i <= N; i++) {
        tree.push_back(Node(tree[root.back()].l, tree[root.back()].r, tree[root.back()].cnt, tree[root.back()].sm)), root.push_back(tree.size() - 1);
        update(root.back(), 1, S, A[i], comp[A[i] - 1]);
    }

    dnc(ST, N, 1, ST), dnc(1, ST, ST, N);
    cout << ans << '\n';

    return 0;
}