#include <bits/stdc++.h>
using namespace std;

const int MAX = 20001;

vector<int> adj[MAX], rev[MAX], st;
int cnt, D[MAX];
bool chk[MAX];

void dfs1(int node) {
    chk[node] = true;
    for (int i : adj[node])
        if (!chk[i])
            dfs1(i);
    st.push_back(node);
}

void dfs2(int node) {
    chk[node] = true;
    for (int i : rev[node])
        if (!chk[i])
            dfs2(i);
    D[node] = cnt;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    bool ans = true;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        X = X < 0 ? ((-X - 1) << 1 | 1) : ((X - 1) << 1);
        Y = Y < 0 ? ((-Y - 1) << 1 | 1) : ((Y - 1) << 1);

        adj[X ^ 1].push_back(Y), rev[Y].push_back(X ^ 1);
        adj[Y ^ 1].push_back(X), rev[X].push_back(Y ^ 1);
    }

    for (int i = 0; i < (M << 1); i++)
        if (!chk[i])
            dfs1(i);
    fill(chk, chk + (M << 1), false);
    while (!st.empty()) {
        X = st.back(), st.pop_back();
        if (chk[X])
            continue;
        cnt++, dfs2(X);
    }

    for (int i = 0; i < M; i++)
        ans &= D[i << 1] != D[i << 1 | 1];
    cout << (ans ? "^_^" : "OTL") << '\n';

    return 0;
}