#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 3> tp;

const int MAX = 250001;

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

void clear() {
    tree.clear();
}

void update(int n, Line v) {
    int s = tree[n].s, e = tree[n].e, m = s + e >> 1;
    Line low = tree[n].line, high = v;

    if (low.get(s) < high.get(s))
        swap(low, high);
    if (low.get(e) >= high.get(e)) {
        tree[n].line = low;
        return;
    }

    if (low.get(m) > high.get(m)) {
        tree[n].line = low;
        if (tree[n].r == -1) {
            tree[n].r = tree.size();
            tree.push_back(Node(m + 1, e, Line(0, 0)));
        }
        update(tree[n].r, high);
    } else {
        tree[n].line = high;
        if (tree[n].l == -1) {
            tree[n].l = tree.size();
            tree.push_back(Node(s, m, Line(0, 0)));
        }
        update(tree[n].l, low);
    }
}

int query(int n, int v) {
    if (n == -1)
        return 0;
    int s = tree[n].s, e = tree[n].e, m = s + e >> 1;

    if (v <= m)
        return max(tree[n].line.get(v), query(tree[n].l, v));
    return max(tree[n].line.get(v), query(tree[n].r, v));
}

int W[MAX], H[MAX], V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);

    int N, S = 0, sW = 0, ans = 0;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> H[i], V[i] = W[i] * H[i], S += V[i];
        if (W[i] < H[i])
            swap(W[i], H[i]);
        arr.push_back(i), sW += W[i];
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return W[x] < W[y]; });

    tree.push_back(Node(1, 1'000'000, Line(0, 0)));
    for (int i : arr) {
        ans = max(ans, V[i] + query(0, W[i]));
        update(0, {-W[i], V[i] + W[i] * (sW - W[i])});
    }

    ans -= S, ans = max(0ll, ans);
    cout << ans << '\n';
}