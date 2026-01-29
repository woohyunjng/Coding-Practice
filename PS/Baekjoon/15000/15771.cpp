#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;

const int MAX = 250001;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int l = -1, r = -1;
    pr line;

    Node(pr line = pr{0, -INF}) : line(line) {}
};

int MC, F[MAX], C[MAX], L[MAX],
    dp[MAX], tree[MAX * 4];
vector<Node> lichao;

int calc(pr line, int x) { return line[0] * x + line[1]; }

void update(int n, int s, int e, pr line) {
    pr low = lichao[n].line, high = line;
    if (calc(high, s) <= calc(low, s))
        swap(low, high);
    if (calc(high, e) >= calc(low, e)) {
        lichao[n].line = high;
        return;
    }

    if (s ^ e) {
        int m = s + e >> 1;
        if (calc(high, m) >= calc(low, m)) {
            lichao[n].line = high;
            if (lichao[n].r == -1)
                lichao[n].r = lichao.size(), lichao.push_back(Node());
            update(lichao[n].r, m + 1, e, low);
        } else {
            lichao[n].line = low;
            if (lichao[n].l == -1)
                lichao[n].l = lichao.size(), lichao.push_back(Node());
            update(lichao[n].l, s, m, high);
        }
    }
}

int query(int n, int s, int e, int x) {
    int m = s + e >> 1, res = -INF;
    res = calc(lichao[n].line, x);
    if (x <= m && lichao[n].l != -1)
        res = max(res, query(lichao[n].l, s, m, x));
    else if (x > m && lichao[n].r != -1)
        res = max(res, query(lichao[n].r, m + 1, e, x));
    return res;
}

void init(int n, int s, int e) {
    tree[n] = lichao.size(), lichao.push_back(Node());
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    }
}

void insert(int n, int s, int e, int x, pr line) {
    update(tree[n], 0, MC, line);
    if (s ^ e) {
        int m = s + e >> 1;
        if (x <= m)
            insert(n << 1, s, m, x, line);
        else
            insert(n << 1 | 1, m + 1, e, x, line);
    }
}

int query(int n, int s, int e, int l, int r, int x) {
    if (r < s || e < l)
        return -INF;
    else if (l <= s && e <= r)
        return query(tree[n], 0, MC, x);
    else {
        int m = s + e >> 1;
        return max(
            query(n << 1, s, m, l, r, x),
            query(n << 1 | 1, m + 1, e, l, r, x));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = -INF, S;
    vector<int> comp;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> F[i], F[i] += i, comp.push_back(F[i]);
    for (int i = 1; i <= N; i++)
        cin >> C[i], MC = max(MC, C[i]);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 1; i <= N; i++)
        F[i] = lower_bound(comp.begin(), comp.end(), F[i]) - comp.begin() + 1;

    init(1, 1, S);

    for (int i = 1; i <= N; i++) {
        cin >> L[i], L[i] += i;
        L[i] = lower_bound(comp.begin(), comp.end(), L[i]) - comp.begin() + 1;
    }

    for (int i = 1; i <= N; i++) {
        if (dp[i - 1] >= 0)
            insert(1, 1, S, F[i], pr{comp[F[i] - 1], dp[i - 1]});
        dp[i] = query(1, 1, S, L[i], S, C[i]) - C[i] * i;
    }

    ans = dp[N];
    if (ans < 0)
        cout << "Impossible" << '\n';
    else
        cout << ans << '\n';
}