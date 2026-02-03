#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 500001;

struct Node {
    int l = -1, r = -1, val = 0;
    Node(int l = -1, int r = -1, int val = 0) : l(l), r(r), val(val) {}
};

int L[MAX], R[MAX], A[MAX], V[MAX];
vector<Node> tree;
vector<int> in[MAX];

void init(int n, int s, int e) {
    if (s ^ e) {
        int m = s + e >> 1;
        tree.push_back(Node()), tree[n].l = (int)tree.size() - 1, init(tree[n].l, s, m);
        tree.push_back(Node()), tree[n].r = (int)tree.size() - 1, init(tree[n].r, m + 1, e);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (s == e)
        tree[n].val += v;
    else {
        int m = s + e >> 1;
        if (x <= m) {
            tree.push_back(Node(tree[tree[n].l].l, tree[tree[n].l].r, tree[tree[n].l].val));
            tree[n].l = (int)tree.size() - 1, update(tree[n].l, s, m, x, v);
        } else {
            tree.push_back(Node(tree[tree[n].r].l, tree[tree[n].r].r, tree[tree[n].r].val));
            tree[n].r = (int)tree.size() - 1, update(tree[n].r, m + 1, e, x, v);
        }
        tree[n].val = tree[tree[n].l].val + tree[tree[n].r].val;
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n].val;
    else {
        int m = s + e >> 1;
        return query(tree[n].l, s, m, l, r) + query(tree[n].r, m + 1, e, l, r);
    }
}

int walk(int nl, int nr, int s, int e, int x) {
    if (s == e)
        return s;
    else {
        int m = s + e >> 1, k = tree[tree[nr].l].val - tree[tree[nl].l].val;
        if (k >= x)
            return walk(tree[nl].l, tree[nr].l, s, m, x);
        else
            return walk(tree[nl].r, tree[nr].r, m + 1, e, x - k);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, S, X, Y;
    bool ans;

    vector<pr> arr, st;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i], in[L[i]].push_back(i);
        arr.push_back({R[i], i});
    }

    sort(arr.begin(), arr.end());
    for (int i = 1; i <= N; i++)
        R[arr[i - 1][1]] = i;

    V[0] = tree.size(), tree.push_back(Node()), init(V[0], 1, N);
    for (int i = 1; i <= N; i++) {
        V[i] = tree.size(), tree.push_back(Node(tree[V[i - 1]].l, tree[V[i - 1]].r, tree[V[i - 1]].val));
        for (int j : in[i])
            update(V[i], 1, N, R[j], 1);
    }

    cin >> Q;
    while (Q--) {
        cin >> M, ans = true;
        for (int i = 1; i <= M; i++)
            cin >> A[i];
        sort(A + 1, A + M + 1), st.clear(), st.push_back({0, N + 1});

        for (int i = 1; i <= M; i++) {
            X = lower_bound(arr.begin(), arr.end(), pr{A[i], 0}) - arr.begin() + 1, S = 0;
            while (!st.empty() && st.back()[1] < X)
                st.pop_back();
            while (!st.empty() && X <= N) {
                Y = query(V[A[i]], 1, N, X, st.back()[1]) -
                    query(V[st.back()[0]], 1, N, X, st.back()[1]);
                if (S + Y < A[i])
                    S += Y, X = st.back()[1] + 1, st.pop_back();
                else {
                    Y = S + Y - A[i];
                    Y = A[i] - S + query(V[A[i]], 1, N, 1, X - 1) -
                        query(V[st.back()[0]], 1, N, 1, X - 1);
                    S = A[i], X = walk(V[st.back()[0]], V[A[i]], 1, N, Y);
                    break;
                }
            }
            while (!st.empty() && st.back()[1] <= X)
                st.pop_back();
            st.push_back({A[i], X}), ans &= S == A[i];
        }

        cout << ans << '\n';
    }

    return 0;
}