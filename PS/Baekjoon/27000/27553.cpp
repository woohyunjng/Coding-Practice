#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 18;
const int INF = 0x3f3f3f3f3f3f3f3f;

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

vector<Node> tree[MAX];

void update(int t, int n, Line v) {
    int s = tree[t][n].s, e = tree[t][n].e, m = s + e >> 1;
    Line low = tree[t][n].line, high = v;

    if (low.get(s) < high.get(s))
        swap(low, high);
    if (low.get(e) >= high.get(e)) {
        tree[t][n].line = low;
        return;
    }

    if (low.get(m) > high.get(m)) {
        tree[t][n].line = low;
        if (tree[t][n].r == -1) {
            tree[t][n].r = tree[t].size();
            tree[t].push_back(Node(m + 1, e, Line(0, 0)));
        }
        update(t, tree[t][n].r, high);
    } else {
        tree[t][n].line = high;
        if (tree[t][n].l == -1) {
            tree[t][n].l = tree[t].size();
            tree[t].push_back(Node(s, m, Line(0, 0)));
        }
        update(t, tree[t][n].l, low);
    }
}

int query(int t, int n, int v) {
    if (n == -1)
        return 0;
    int s = tree[t][n].s, e = tree[t][n].e, m = s + e >> 1;

    if (v <= m)
        return max(tree[t][n].line.get(v), query(t, tree[t][n].l, v));
    return max(tree[t][n].line.get(v), query(t, tree[t][n].r, v));
}

int N, V[MAX], dis[MAX][MAX], dp[MAX][1 << MAX], S[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int M, Q, X, Y, Z;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> V[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (i != j)
                dis[i][j] = INF;
        for (int j = 0; j < (1 << N); j++)
            dp[i][j] = INF;
        dp[i][1 << i] = 0;
    }

    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < N; j++)
            if (i & (1 << j))
                S[i] += V[j];

    while (M--) {
        cin >> X >> Y >> Z, X--, Y--;
        dis[Y][X] = Z;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);

    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            if (!(i & (1 << j)))
                continue;
            for (int k = 0; k < N; k++) {
                if (i == j || !(i & (1 << k)) || dis[j][k] == INF)
                    continue;
                dp[j][i] = min(dp[j][i], dp[k][i ^ (1 << j)] + dis[j][k] * S[i ^ (1 << j)]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        tree[i].push_back(Node(1, 1'000'000'000, Line(0, -INF)));
        for (int j = 0; j < (1 << N); j++) {
            if (!(j & (1 << i)) || dp[i][j] == INF)
                continue;
            update(i, 0, Line(S[j], -dp[i][j]));
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> X >> Y, Y--;
        cout << query(Y, 0, X) << '\n';
    }
}