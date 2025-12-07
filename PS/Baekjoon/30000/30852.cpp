#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;
typedef long long ll;

const int MAX = 1000001;

struct Node {
    int l = -1, r = -1, cnt = 0;
    ll sum = 0;

    Node() : l(-1), r(-1), cnt(0), sum(0) {};
    Node(int l, int r, int cnt, ll val) : l(l), r(r), cnt(cnt), sum(val) {};
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

void update(int n, int s, int e, int x, ll v) {
    tree[n].cnt++, tree[n].sum += v;
    if (s == e)
        return;
    int m = s + e >> 1;
    if (x <= m) {
        tree.push_back(Node(tree[tree[n].l].l, tree[tree[n].l].r, tree[tree[n].l].cnt, tree[tree[n].l].sum));
        tree[n].l = (int)tree.size() - 1;
        update(tree[n].l, s, m, x, v);
    } else {
        tree.push_back(Node(tree[tree[n].r].l, tree[tree[n].r].r, tree[tree[n].r].cnt, tree[tree[n].r].sum));
        tree[n].r = (int)tree.size() - 1;
        update(tree[n].r, m + 1, e, x, v);
    }
}

int A[MAX], C[MAX], N;

ll calc(int L, int R, int M, int K) {
    R = min(R, L + K - 1 + M);
    ll ans = 0;
    int PL = root[L - 1], PR = root[R], s = 1, e = N, m;

    while (s < e) {
        m = s + e >> 1;
        if (tree[tree[PR].l].cnt - tree[tree[PL].l].cnt >= K)
            PL = tree[PL].l, PR = tree[PR].l, e = m;
        else {
            K -= tree[tree[PR].l].cnt - tree[tree[PL].l].cnt, ans += (ll)tree[tree[PR].l].sum - tree[tree[PL].l].sum;
            PL = tree[PL].r, PR = tree[PR].r, s = m + 1;
        }
    }
    if (K)
        ans += tree[PR].sum - tree[PL].sum;
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, S, E, M, L, R;
    vector<pr> comp;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back({A[i], i});

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());

    tree.reserve(20 * N), root.reserve(N + 1);
    tree.push_back(Node()), root.push_back(0), init(root.back(), 1, N);
    for (int i = 1; i <= N; i++) {
        tree.push_back(Node(tree[root.back()].l, tree[root.back()].r, tree[root.back()].cnt, tree[root.back()].sum)), root.push_back(tree.size() - 1);
        update(root.back(), 1, N, (int)(lower_bound(comp.begin(), comp.end(), (pr){A[i], i}) - comp.begin()) + 1, A[i]);
    }

    while (Q--) {
        cin >> S >> E >> M >> L >> R;
        cout << (ll)calc(S, E, M, R) - calc(S, E, M, L - 1) << '\n';
    }

    return 0;
}