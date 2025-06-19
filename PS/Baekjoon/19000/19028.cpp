#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 250001;

int par[MAX][2], U[MAX], V[MAX], T[MAX], S[MAX], SC[MAX], cnt;
bool vst[MAX];
vector<int> con[MAX], adj[MAX], rev[MAX], st;

int find(int T, int X) { return X == par[X][T] ? X : par[X][T] = find(T, par[X][T]); }
void merge(int T, int X, int Y) {
    X = find(T, X), Y = find(T, Y);
    if (X == Y)
        return;
    if (X > Y)
        swap(X, Y);
    par[Y][T] = X;
    if (T == 1)
        S[X] += S[Y];
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
            T[i] = l, merge(0, U[i], V[i]);
        return;
    }

    int m = l + r >> 1, X, Y;
    vector<int> lv, rv, ct, nodes;

    for (int i : arr) {
        if (i > m)
            continue;
        X = find(0, U[i]), Y = find(0, V[i]);
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
        X = find(0, U[i]), Y = find(0, V[i]);
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

    int N, M, ans = 0, X, Y;
    vector<int> arr;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        par[i][0] = par[i][1] = i, S[i] = 1;
    for (int i = 1; i <= M; i++)
        cin >> U[i] >> V[i], arr.push_back(i);

    dnc(1, M + 1, arr);

    for (int i = 1; i <= M; i++)
        if (T[i] <= M)
            con[T[i]].push_back(i);

    for (int i = 1; i <= M; i++) {
        for (int j : con[i]) {
            X = find(1, U[j]), Y = find(1, V[j]);
            if (X == Y)
                continue;
            ans += S[X] * S[Y], merge(1, X, Y);
        }
        cout << ans << '\n';
    }

    return 0;
}