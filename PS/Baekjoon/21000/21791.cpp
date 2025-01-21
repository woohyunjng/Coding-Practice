#include <bits/stdc++.h>
#define int long long

#define MAX 6000
#define MAX_Q 3000000
#define INF 2000000000
using namespace std;

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
                tree.push_back(Node((s + e >> 1) + 1, e, Line(0, 0)));
            }
            update(tree[n].r, low);
        } else {
            tree[n].line = low;
            if (tree[n].l == -1) {
                tree[n].l = tree.size();
                tree.push_back(Node(s, (s + e >> 1), Line(0, 0)));
            }
            update(tree[n].l, high);
        }
    }

    int query(int n, int x) {
        if (n == -1)
            return 0;
        int s = tree[n].s, e = tree[n].e;
        if (x <= s + e >> 1)
            return max(tree[n].line.get(x), query(tree[n].l, x));
        return max(tree[n].line.get(x), query(tree[n].r, x));
    }

  public:
    vector<Node> tree;
    void init(int s, int e) {
        tree.push_back(Node(s, e, Line(0, 0)));
    }

    LiChaoTree(int s, int e) { init(s, e); }

    void update(Line v) { update(0, v); }
    int query(int x) { return query(0, x); }
};

int T[MAX], A[MAX], B[MAX], C[MAX], dp[MAX][MAX], val[MAX][MAX][2], P[MAX_Q], K[MAX_Q], V[MAX_Q][2], ans[MAX_Q];
vector<int> arr[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, Z, Xs, Ys, XT, YT;
    vector<int> Xcomp, Ycomp;

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> A[i] >> B[i] >> C[i], C[i] /= 2;
        Xcomp.push_back(A[i] + T[i]), Ycomp.push_back(-A[i] + T[i]);
        if (A[i] <= B[i])
            Xcomp.push_back(B[i] * 2 - A[i] + T[i]);
        else
            Ycomp.push_back(-B[i] * 2 + A[i] + T[i]);
    }

    sort(Xcomp.begin(), Xcomp.end()), Xcomp.erase(unique(Xcomp.begin(), Xcomp.end()), Xcomp.end()), Xs = Xcomp.size();
    sort(Ycomp.begin(), Ycomp.end()), Ycomp.erase(unique(Ycomp.begin(), Ycomp.end()), Ycomp.end()), Ys = Ycomp.size();

    for (int i = 1; i <= N; i++) {
        if (A[i] <= B[i]) {
            X = lower_bound(Xcomp.begin(), Xcomp.end(), A[i] + T[i]) - Xcomp.begin() + 1;
            Y = lower_bound(Xcomp.begin(), Xcomp.end(), B[i] * 2 - A[i] + T[i]) - Xcomp.begin() + 1;
            Z = lower_bound(Ycomp.begin(), Ycomp.end(), -A[i] + T[i]) - Ycomp.begin() + 1;
            for (int j = X; j < Y; j++)
                val[j][Z][0] = max(val[j][Z][0], C[i]);
        } else {
            X = lower_bound(Ycomp.begin(), Ycomp.end(), -A[i] + T[i]) - Ycomp.begin() + 1;
            Y = lower_bound(Ycomp.begin(), Ycomp.end(), -B[i] * 2 + A[i] + T[i]) - Ycomp.begin() + 1;
            Z = lower_bound(Xcomp.begin(), Xcomp.end(), A[i] + T[i]) - Xcomp.begin() + 1;
            for (int j = X; j < Y; j++)
                val[Z][j][1] = max(val[Z][j][1], C[i]);
        }
    }

    for (int i = Xs; i >= 1; i--)
        for (int j = Ys; j >= 1; j--) {
            X = 0, Y = 0;
            if (i < Xs)
                X = dp[i + 1][j] + val[i][j][0] * (Xcomp[i] - Xcomp[i - 1]);
            if (j < Ys)
                Y = dp[i][j + 1] + val[i][j][1] * (Ycomp[j] - Ycomp[j - 1]);
            dp[i][j] = max(X, Y);
        }

    for (int i = 1; i <= Q; i++) {
        cin >> X >> Y;
        P[i] = lower_bound(Xcomp.begin(), Xcomp.end(), X + Y) - Xcomp.begin() + 1;
        V[i][0] = P[i] <= Xcomp.size() ? (Xcomp[P[i] - 1] - X - Y) : 0;

        K[i] = lower_bound(Ycomp.begin(), Ycomp.end(), X - Y) - Ycomp.begin() + 1;
        V[i][1] = K[i] <= Ycomp.size() ? (Ycomp[K[i] - 1] - X + Y) : 0;

        arr[P[i]][K[i]].push_back(i);
    }

    LiChaoTree lichao(0, INF);

    for (int i = 1; i <= Xs; i++) {
        lichao.tree.clear(), lichao.init(0, INF);
        for (int j = Ys; j >= 1; j--) {
            lichao.update(Line(val[i - 1][j][0], dp[i][j]));
            for (int k : arr[i][j])
                ans[k] = max(ans[k], lichao.query(V[k][0]));
        }
    }

    for (int i = 1; i <= Ys; i++) {
        lichao.tree.clear(), lichao.init(0, INF);
        for (int j = Xs; j >= 1; j--) {
            lichao.update(Line(val[j][i - 1][1], dp[j][i]));
            for (int k : arr[j][i])
                ans[k] = max(ans[k], lichao.query(V[k][1]));
        }
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}