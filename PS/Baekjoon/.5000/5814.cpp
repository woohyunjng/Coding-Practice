#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 200001;

int A[MAX], S[MAX], E[MAX], tree[MAX * 4], par[MAX], G[MAX], ans, ans_val = -1;
bool chk[MAX], vst[MAX];
vector<int> adj[MAX];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = 1;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

void clear(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        int m = s + e >> 1;
        if (tree[n << 1] != 0)
            clear(n << 1, s, m, l, r);
        if (tree[n << 1 | 1] != 0)
            clear(n << 1 | 1, m + 1, e, l, r);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    } else {
        int m = s + e >> 1;
        clear(n << 1, s, m, l, r), clear(n << 1 | 1, m + 1, e, l, r);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

int query(int n, int s, int e, int x) {
    if (s == e)
        return s;
    else {
        int m = s + e >> 1;
        if (tree[n << 1] >= x)
            return query(n << 1, s, m, x);
        else
            return query(n << 1 | 1, m + 1, e, x - tree[n << 1]);
    }
}

void dnc(int l, int r, int s, int e) {
    int X, Y;
    if (l == r) {
        X = l, Y = 0;
        while (!vst[par[X]] && par[X] != 0)
            X = par[X], Y++;
        if (ans_val < Y)
            ans = l, ans_val = Y;
    } else {
        int m = s + e >> 1;

        for (int i = e - (r - m) + 1, j = m + 1; i <= e; i++, j++) {
            if (!chk[i])
                continue;
            X = j, vst[X] = true, G[j] = X;
            while (!vst[par[X]] && par[X] != 0)
                X = par[X], G[j] = X, vst[X] = true;
        }
        dnc(l, m, s, e - (r - m));
        for (int i = e - (r - m) + 1, j = m + 1; i <= e; i++, j++) {
            if (!chk[i])
                continue;
            X = j, vst[X] = false;
            while (X != G[j])
                X = par[X], vst[X] = false;
        }

        for (int i = s, j = l; i <= s + (m + 1 - l) - 1; i++, j++) {
            if (!chk[i])
                continue;
            X = j, vst[X] = true, G[j] = X;
            while (!vst[par[X]] && par[X] != 0)
                X = par[X], G[j] = X, vst[X] = true;
        }
        dnc(m + 1, r, s + (m + 1 - l), e);
        for (int i = s, j = l; i <= s + (m + 1 - l) - 1; i++, j++) {
            if (!chk[i])
                continue;
            X = j, vst[X] = false;
            while (X != G[j])
                X = par[X], vst[X] = false;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C, R, X, Y, V, K;
    set<tp> st;
    set<tp>::iterator iter;

    cin >> N >> C >> R, A[N] = R, K = N;
    for (int i = 1; i < N; i++)
        cin >> A[i], chk[i] = A[i] > R;
    init(1, 1, N), V = N;

    for (int i = 1; i <= N; i++)
        st.insert({i, i, i});

    for (int i = 1; i <= C; i++) {
        cin >> S[i] >> E[i], S[i]++, E[i]++;
        X = query(1, 1, N, S[i]);
        Y = E[i] == V ? N : (query(1, 1, N, E[i] + 1) - 1);
        clear(1, 1, N, X + 1, Y);
        V -= E[i] - S[i];

        S[i] = X, E[i] = Y, X = ++K;
        while (true) {
            iter = st.lower_bound({S[i], 0, 0});
            if (iter == st.end() || (*iter)[0] > E[i])
                break;
            Y = (*iter)[2], st.erase(iter);
            par[Y] = X, adj[X].push_back(Y);
        }
        st.insert({S[i], E[i], X});
    }

    dnc(1, N, 1, N - 1);

    cout << ans - 1 << '\n';

    return 0;
}