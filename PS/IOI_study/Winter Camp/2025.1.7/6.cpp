#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000000

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

struct Node {
    int l, r, val;
    Node() { l = r = -1, val = 0; }
    Node(int l, int r, int val) : l(l), r(r), val(val) {}
};

vector<Node> tree;
vector<int> root;

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

int query(int n, int s, int e, int l, int r) {
    if (n == -1 || r < s || e < l)
        return 0;
    if (l <= s && e <= r)
        return tree[n].val;
    int m = s + e >> 1;
    return query(tree[n].l, s, m, l, r) + query(tree[n].r, m + 1, e, l, r);
}

vector<pr> star[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, C, D, X = 0;
    vector<tp> arr;
    vector<int> xComp, yComp;
    Node node;

    cin >> N >> Q;

    while (N--) {
        cin >> A >> B >> C;
        arr.push_back({A, B, C});
        xComp.push_back(A), yComp.push_back(B);
    }

    sort(xComp.begin(), xComp.end()), sort(yComp.begin(), yComp.end());
    xComp.erase(unique(xComp.begin(), xComp.end()), xComp.end());
    yComp.erase(unique(yComp.begin(), yComp.end()), yComp.end());

    for (int i = 0; i < arr.size(); i++) {
        arr[i][0] = lower_bound(xComp.begin(), xComp.end(), arr[i][0]) - xComp.begin() + 1;
        arr[i][1] = lower_bound(yComp.begin(), yComp.end(), arr[i][1]) - yComp.begin() + 1;
        star[arr[i][0]].push_back({arr[i][1], arr[i][2]});
    }

    tree.push_back(Node()), root.push_back(0);
    N = yComp.size();
    init(0, 1, N);

    for (int i = 1; i <= xComp.size(); i++) {
        node = Node(tree[root[i - 1]].l, tree[root[i - 1]].r, tree[root[i - 1]].val);
        root.push_back(tree.size()), tree.push_back(node);

        for (pr j : star[i])
            update(root[i], 1, N, j.first, j.second);
    }

    while (Q--) {
        cin >> A >> B >> C >> D;
        A = (A ^ X) % MOD + 1, B = (B ^ X) % MOD + 1, C = (C ^ X) % MOD + 1, D = (D ^ X) % MOD + 1;
        if (A > B)
            swap(A, B);
        if (C > D)
            swap(C, D);

        A = lower_bound(xComp.begin(), xComp.end(), A) - xComp.begin() + 1;
        B = upper_bound(xComp.begin(), xComp.end(), B) - xComp.begin();
        C = lower_bound(yComp.begin(), yComp.end(), C) - yComp.begin() + 1;
        D = upper_bound(yComp.begin(), yComp.end(), D) - yComp.begin();

        X = query(root[B], 1, N, C, D) - query(root[A - 1], 1, N, C, D);
        cout << X << '\n';
    }

    return 0;
}