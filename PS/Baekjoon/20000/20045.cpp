#include <bits/stdc++.h>
#define int long long

#define MAX 250100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], sm[MAX];

struct Node {
    int l, r, val;
    Node() { l = r = -1, val = 0; }
    Node(int l, int r, int val) : l(l), r(r), val(val) {}
};

vector<Node> tree;

void init(int n, int s, int e) {
    if (s == e)
        return;

    int m = s + e >> 1;
    tree[n].l = tree.size(), tree.push_back(Node());
    tree[n].r = tree.size(), tree.push_back(Node());

    init(tree[n].l, s, m), init(tree[n].r, m + 1, e);
    tree[n].val = tree[tree[n].l].val + tree[tree[n].r].val;
}

void update(int n, int s, int e, int x, int v) {
    tree[n].val += v;
    if (s == e)
        return;

    int m = s + e >> 1;
    if (x <= m) {
        tree.push_back(Node(tree[tree[n].l].l, tree[tree[n].l].r, tree[tree[n].l].val));
        tree[n].l = tree.size() - 1;
        update(tree[n].l, s, m, x, v);
    } else {
        tree.push_back(Node(tree[tree[n].r].l, tree[tree[n].r].r, tree[tree[n].r].val));
        tree[n].r = tree.size() - 1;
        update(tree[n].r, m + 1, e, x, v);
    }
}

int kth_query(int ln, int rn, int s, int e, int k) {
    if (s == e)
        return s;

    int m = s + e >> 1, cnt = tree[tree[rn].l].val - tree[tree[ln].l].val;
    if (cnt >= k)
        return kth_query(tree[ln].l, tree[rn].l, s, m, k);
    else
        return kth_query(tree[ln].r, tree[rn].r, m + 1, e, k - cnt);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, S;
    vector<int> comp, root;
    priority_queue<tp> pq;
    tp P;
    Node node;

    cin >> N >> K;

    comp.push_back(0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i], sm[i] = sm[i - 1] + A[i];
        comp.push_back(sm[i]);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();

    tree.push_back(Node()), root.push_back(0);
    init(0, 1, S);

    for (int i = 0; i <= N; i++) {
        X = lower_bound(comp.begin(), comp.end(), sm[i]) - comp.begin() + 1;
        node = Node(tree[root.back()].l, tree[root.back()].r, tree[root.back()].val);

        root.push_back(tree.size()), tree.push_back(node);
        update(root.back(), 1, S, X, 1);

        if (i) {
            X = kth_query(0, root[i], 1, S, 1) - 1;
            pq.push({sm[i] - comp[X], 1, i});
        }
    }

    while (K--) {
        P = pq.top(), pq.pop();
        cout << P[0] << ' ';
        if (P[1] < P[2]) {
            X = kth_query(0, root[P[2]], 1, S, P[1] + 1) - 1;
            pq.push({sm[P[2]] - comp[X], P[1] + 1, P[2]});
        }
    }
    cout << '\n';

    return 0;
}