#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 500001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int CCW(pr X, pr Y, pr Z) { // X-Y-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (Y[0] - X[0]) * (Z[1] - X[1]) - (Z[0] - X[0]) * (Y[1] - X[1]);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

struct Line {
    int A, B;
    int get(int X) { return A * X + B; }

    Line(int A, int B) : A(A), B(B) {}
};

struct Node {
    int s, e, l = -1, r = -1;
    Line line;

    Node(int s, int e, Line line) : s(s), e(e), line(line) {}
};

vector<Node> tree;
int A[MAX], B[MAX];

void update(int n, Line v) {
    int s = tree[n].s, e = tree[n].e, m = s + e >> 1;
    Line low = tree[n].line, high = v;

    if (low.get(s) > high.get(s))
        swap(low, high);
    if (low.get(e) <= high.get(e)) {
        tree[n].line = high;
        return;
    }

    if (low.get(m) < high.get(m)) {
        tree[n].line = high;
        if (tree[n].r == -1) {
            tree[n].r = tree.size();
            tree.push_back(Node(m + 1, e, Line(0, -INF)));
        }
        update(tree[n].r, low);
    } else {
        tree[n].line = low;
        if (tree[n].l == -1) {
            tree[n].l = tree.size();
            tree.push_back(Node(s, m, Line(0, -INF)));
        }
        update(tree[n].l, high);
    }
}

int query(int n, int v) {
    if (n == -1)
        return -INF;
    int s = tree[n].s, e = tree[n].e, m = s + e >> 1;

    if (v <= m)
        return max(tree[n].line.get(v), query(tree[n].l, v));
    return max(tree[n].line.get(v), query(tree[n].r, v));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, ans = 0;
    vector<pr> arr, upper, lower, hull;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    for (int i = 0; i < N; i++)
        arr.push_back({A[i], B[i]});
    sort(arr.begin(), arr.end());

    for (pr i : arr) {
        while (upper.size() >= 2 && CCW(upper[(int)upper.size() - 2], upper[(int)upper.size() - 1], i) >= 0)
            upper.pop_back();
        upper.push_back(i);
    }

    reverse(arr.begin(), arr.end());
    for (pr i : arr) {
        while (lower.size() >= 2 && CCW(lower[(int)lower.size() - 2], lower[(int)lower.size() - 1], i) >= 0)
            lower.pop_back();
        lower.push_back(i);
    }

    hull = upper;
    for (int i = 1; i + 1 < lower.size(); i++)
        hull.push_back(lower[i]);

    N = hull.size();
    for (int i = 0; i < N; i++)
        A[i] = hull[i][0], B[i] = hull[i][1];

    tree.push_back(Node(-MAX, MAX, {0, -INF}));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            update(0, {(A[i] - B[i]) - (A[j] - B[j]), A[i] * B[j] - B[i] * A[j]});

    cin >> Q;
    while (Q--) {
        cin >> X;
        cout << query(0, X) << '\n';
    }

    return 0;
}