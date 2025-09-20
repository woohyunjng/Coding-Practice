#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int par[MAX][2], U[MAX], V[MAX], T[MAX], S[MAX], C[MAX], SC[MAX], D[MAX], cnt, ans[MAX];
bool vst[MAX], chk[MAX];
vector<int> con[MAX], adj[MAX], rev[MAX], st;

// S -> indegree가 0인가? 1 : 0
// C -> indegree 값

int find(int T, int X) { return X == par[X][T] ? X : par[X][T] = find(T, par[X][T]); }
void merge(int T, int X, int Y) {
    X = find(T, X), Y = find(T, Y);
    if (X == Y)
        return;
    if (X > Y)
        swap(X, Y);
    par[Y][T] = X;
    if (T == 1) {
        C[Y]--, C[X] = C[X] + C[Y];
        S[X] = C[X] == 0, S[Y] = 0;
    }
}

void dfs1(int node) {
    vst[node] = true;
    for (int i : adj[node]) {
        if (vst[i])
            continue;
        dfs1(i);
    }
    st.push_back(node);
}

void dfs2(int node) {
    SC[node] = cnt;
    for (int i : rev[node]) {
        if (SC[i])
            continue;
        dfs2(i);
    }
}

void dnc(int l, int r, vector<int> &arr) {
    if (l == r) {
        for (int i : arr)
            T[D[i]] = l, merge(0, U[D[i]], V[D[i]]);
        return;
    }

    int m = l + r >> 1, X, Y;
    vector<int> lv, rv, ct, nodes;

    for (int i : arr) {
        if (i > m)
            continue;
        X = find(0, U[D[i]]), Y = find(0, V[D[i]]);
        adj[X].push_back(Y), rev[Y].push_back(X);
        nodes.push_back(X), nodes.push_back(Y);
    }

    cnt = 0;
    sort(nodes.begin(), nodes.end()), nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    for (int i : nodes) {
        if (vst[i])
            continue;
        dfs1(i);
    }

    while (!st.empty()) {
        X = st.back(), st.pop_back();
        if (SC[X])
            continue;
        cnt++, dfs2(X);
    }

    for (int i : arr) {
        if (i > m) {
            rv.push_back(i);
            continue;
        }
        X = find(0, U[D[i]]), Y = find(0, V[D[i]]);
        if (SC[X] == SC[Y])
            lv.push_back(i);
        else
            rv.push_back(i);
    }

    for (int i : nodes) {
        adj[i].clear(), rev[i].clear();
        vst[i] = false, SC[i] = 0;
    }

    dnc(l, m, lv), dnc(m + 1, r, rv);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, val = 0, X, Y;
    vector<int> arr;

    cin >> N >> M, val = N;
    for (int i = 1; i <= N; i++) {
        par[i][0] = par[i][1] = i;
        S[i] = 1, C[i] = 0;
    }
    for (int i = 1; i <= M; i++)
        cin >> U[i] >> V[i], arr.push_back(i);

    cin >> Q, X = 1;
    for (int i = M; i >= M - Q + 1; i--)
        cin >> D[i], chk[D[i]] = true;
    for (int i = M - Q; i >= 1; i--) {
        while (chk[X])
            X++;
        D[i] = X++;
    }

    dnc(1, M + 1, arr);

    for (int i = 1; i <= M; i++)
        if (T[i] <= M)
            con[T[i]].push_back(i);

    ans[0] = val;
    for (int i = 1; i <= M; i++) {
        X = find(1, V[D[i]]), val -= S[X];
        C[X]++, S[X] = C[X] == 0, val += S[X];

        for (int j : con[i]) {
            X = find(1, U[j]), Y = find(1, V[j]);
            if (X == Y)
                val -= S[X], C[X]--, S[X] = C[X] == 0, val += S[X];
            else {
                val -= S[X] + S[Y], merge(1, X, Y);
                val += S[find(1, X)];
            }
        }
        ans[i] = val;
    }

    for (int i = M - 1; i >= M - Q; i--)
        cout << ans[i] << '\n';

    return 0;
}