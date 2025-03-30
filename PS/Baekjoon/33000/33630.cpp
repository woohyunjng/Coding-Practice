#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
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

int H[MAX], A[MAX], C[MAX], F[MAX], tree_seg[MAX * 4];

vector<Node> tree_lichao;
vector<vector<pair<int, Line>>> st;

void update_seg(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree_seg[n] = min(INF, v);
    else {
        int m = s + e >> 1;
        update_seg(n << 1, s, m, x, v), update_seg(n << 1 | 1, m + 1, e, x, v);
        tree_seg[n] = min(tree_seg[n << 1], tree_seg[n << 1 | 1]);
    }
}

int query_seg(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return INF;
    else if (l <= s && e <= r)
        return tree_seg[n];
    else {
        int m = s + e >> 1;
        return min(
            query_seg(n << 1, s, m, l, r),
            query_seg(n << 1 | 1, m + 1, e, l, r));
    }
}

void update_lichao(int n, Line v) {
    st.back().push_back({n, tree_lichao[n].line});

    int s = tree_lichao[n].s, e = tree_lichao[n].e, m = s + e >> 1;
    Line low = tree_lichao[n].line, high = v;

    if (low.get(s) > high.get(s))
        swap(low, high);
    if (low.get(e) <= high.get(e)) {
        tree_lichao[n].line = low;
        return;
    }

    if (low.get(m) < high.get(m)) {
        tree_lichao[n].line = low;
        if (tree_lichao[n].r == -1) {
            tree_lichao[n].r = tree_lichao.size();
            tree_lichao.push_back(Node(m + 1, e, Line(0, INF)));
        }
        update_lichao(tree_lichao[n].r, high);
    } else {
        tree_lichao[n].line = high;
        if (tree_lichao[n].l == -1) {
            tree_lichao[n].l = tree_lichao.size();
            tree_lichao.push_back(Node(s, m, Line(0, INF)));
        }
        update_lichao(tree_lichao[n].l, low);
    }
}

int query_lichao(int n, int v) {
    if (n == -1)
        return INF;
    int s = tree_lichao[n].s, e = tree_lichao[n].e, m = s + e >> 1;

    if (v <= m)
        return min(tree_lichao[n].line.get(v), query_lichao(tree_lichao[n].l, v));
    return min(tree_lichao[n].line.get(v), query_lichao(tree_lichao[n].r, v));
}

void rollback_lichao() {
    for (pair<int, Line> i : st.back())
        tree_lichao[i.first].line = i.second;
    st.pop_back();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T, X, V, ans;
    vector<int> arr;

    cin >> N >> T;
    for (int i = 1; i <= N; i++)
        cin >> H[i];
    for (int i = 1; i < N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> C[i];
    for (int i = 1; i < N; i++)
        cin >> F[i], F[i] += F[i - 1];

    if (T == 1) {
        fill(tree_seg + 1, tree_seg + N * 4, INF), update_seg(1, 1, N, H[1], 0), V = H[1];
        for (int i = 1; i < N; i++) {
            X = query_seg(1, 1, N, H[i], H[i]) + A[i] + F[i - 1], V = max(V, H[i + 1]);
            for (int j = 0; H[i + 1] + j * j <= V; j++)
                X = min(X, j * C[i + 1] + query_seg(1, 1, N, H[i + 1] + j * j, H[i + 1] + (j + 1) * (j + 1) - 1) + F[i]);
            X -= F[i];
            update_seg(1, 1, N, H[i + 1], min(query_seg(1, 1, N, H[i + 1], H[i + 1]), X));
            if (H[i + 1] > H[i])
                update_seg(1, 1, N, H[i], INF);
        }

        ans = query_seg(1, 1, N, H[N], H[N]) + F[N - 1];
    } else {
        tree_lichao.push_back(Node(1, 1'000'000'000, Line(0, INF))), X = 0;
        st.push_back({}), update_lichao(0, Line(H[1], 0));
        arr.push_back(H[1]);

        for (int i = 1; i < N; i++) {
            while (!arr.empty() && arr.back() < H[i + 1])
                rollback_lichao(), arr.pop_back();
            X = min(X + A[i], query_lichao(0, C[i + 1]) + F[i] - C[i + 1] * H[i + 1]);
            st.push_back({}), update_lichao(0, Line(H[i + 1], X - F[i]));
            arr.push_back(H[i + 1]);
        }
        ans = X;
    }

    cout << ans << '\n';

    return 0;
}