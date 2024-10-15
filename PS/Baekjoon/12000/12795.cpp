#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

struct Line {
    int A, B;
    int get(int X) { return A * X + B; }

    Line(int A, int B) : A(A), B(B) {}
};

struct Node {
    int l = -1, r = -1, s, e;
    Line line;

    Node(int s, int e, Line line) : s(s), e(e), line(line) {}
};

class LiChaoTree {
  private:
    void init(int s, int e) {
        tree.push_back(Node(s, e, Line(0, -INF)));
    }

    void update(int n, Line v) {
        int s = tree[n].s, e = tree[n].e;
        Line low = tree[n].line, high = v;

        if (low.get(s) > high.get(s))
            swap(low, high);
        if (low.get(e) <= high.get(e)) {
            tree[n].line = high;
            return;
        }

        if (low.get(s + e >> 1) < high.get(s + e >> 1)) {
            tree[n].line = high;
            if (tree[n].r == -1) {
                tree[n].r = tree.size();
                tree.push_back(Node((s + e >> 1) + 1, e, Line(0, -INF)));
            }
            update(tree[n].r, low);
        } else {
            tree[n].line = low;
            if (tree[n].l == -1) {
                tree[n].l = tree.size();
                tree.push_back(Node(s, (s + e >> 1), Line(0, -INF)));
            }
            update(tree[n].l, high);
        }
    }

    int query(int n, int x) {
        if (n == -1)
            return -INF;
        int s = tree[n].s, e = tree[n].e;
        if (x <= s + e >> 1)
            return max(tree[n].line.get(x), query(tree[n].l, x));
        return max(tree[n].line.get(x), query(tree[n].r, x));
    }

  public:
    vector<Node> tree;

    LiChaoTree(int s, int e) { init(s, e); }

    void update(Line v) { update(0, v); }
    int query(int x) { return query(0, x); }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, T, A, B;
    cin >> Q;

    LiChaoTree tree(-2e12, 2e12);

    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> A >> B;
            tree.update(Line(A, B));
        } else {
            cin >> A;
            cout << tree.query(A) << '\n';
        }
    }

    return 0;
}