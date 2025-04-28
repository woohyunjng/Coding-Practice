#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 4> ftp;

const int MAX = 300001;
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

vector<Node> tree_lichao;
vector<vector<pair<int, Line>>> st;

void update_lichao(int n, Line v) {
    st.back().push_back({n, tree_lichao[n].line});

    int s = tree_lichao[n].s, e = tree_lichao[n].e, m = s + e >> 1;
    Line low = tree_lichao[n].line, high = v;

    if (low.get(s) > high.get(s))
        swap(low, high);
    if (low.get(e) <= high.get(e)) {
        tree_lichao[n].line = high;
        return;
    }

    if (low.get(m) < high.get(m)) {
        tree_lichao[n].line = high;
        if (tree_lichao[n].r == -1) {
            tree_lichao[n].r = tree_lichao.size();
            tree_lichao.push_back(Node(m + 1, e, Line(0, -INF)));
        }
        update_lichao(tree_lichao[n].r, low);
    } else {
        tree_lichao[n].line = low;
        if (tree_lichao[n].l == -1) {
            tree_lichao[n].l = tree_lichao.size();
            tree_lichao.push_back(Node(s, m, Line(0, -INF)));
        }
        update_lichao(tree_lichao[n].l, high);
    }
}

int query_lichao(int n, int v) {
    if (n == -1)
        return -INF;
    int s = tree_lichao[n].s, e = tree_lichao[n].e, m = s + e >> 1;

    if (v <= m)
        return max(tree_lichao[n].line.get(v), query_lichao(tree_lichao[n].l, v));
    return max(tree_lichao[n].line.get(v), query_lichao(tree_lichao[n].r, v));
}

void rollback_lichao() {
    for (pair<int, Line> i : st.back())
        tree_lichao[i.first].line = i.second;
    st.pop_back();
}

vector<Line> tree[MAX * 4];

int ans[MAX], X[MAX], Y[MAX], L[MAX], V[MAX];
bool chk[MAX];

void update(int n, int s, int e, int l, int r, Line line) {
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        tree[n].push_back(line);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, line), update(n << 1 | 1, m + 1, e, l, r, line);
    }
}

void dnc(int n, int s, int e) {
    int m = s + e >> 1;

    for (Line i : tree[n])
        st.push_back({}), update_lichao(0, i);

    if (s ^ e)
        dnc(n << 1, s, m), dnc(n << 1 | 1, m + 1, e);
    else
        ans[s] = query_lichao(0, V[s]);

    for (int i = 0; i < tree[n].size(); i++)
        rollback_lichao();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C = 1, T, K;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> T, X[i] = -INF, Y[i] = -INF;
        if (T == 1)
            cin >> X[i] >> Y[i], L[i] = i;
        else if (T == 2)
            cin >> K, X[i] = K;
        else
            cin >> Y[i];
    }

    vector<ftp> upd;

    for (int i = 1; i <= N; i++) {
        chk[i] = true;
        if (X[i] == -INF && Y[i] != -INF)
            V[C++] = Y[i];
        else if (X[i] != -INF && Y[i] == -INF)
            chk[X[i]] = true, upd.push_back({L[X[i]], C - 1, X[X[i]], Y[X[i]]});
        else
            chk[i] = false, L[i] = C;
    }

    for (int i = 1; i <= N; i++) {
        if (chk[i])
            continue;
        upd.push_back({L[i], C - 1, X[i], Y[i]});
    }

    N = C - 1;

    for (ftp i : upd)
        update(1, 1, N, i[0], i[1], Line(i[2], i[3]));

    tree_lichao.push_back(Node(-1'000'000'000, 1'000'000'000, Line(0, -INF)));
    dnc(1, 1, N);

    for (int i = 1; i <= N; i++) {
        if (ans[i] == -INF)
            cout << "EMPTY\n";
        else
            cout << ans[i] << '\n';
    }

    return 0;
}