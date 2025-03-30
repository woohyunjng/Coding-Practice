#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 500001;

vector<pr> adj[MAX];

int K, val, dp[MAX], mx[MAX], A[MAX], depth[MAX], mx_len[MAX];
bool chk[MAX];

int dfs1(int node, int par) {
    int X, V = A[node];
    chk[node] |= A[node];
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        depth[i[0]] = depth[node] + i[1];
        X = dfs1(i[0], node), V += X;
        if (X < K && X > 0)
            val += i[1] * 2, chk[node] = true;
    }
    return V;
}

void dfs2(int node, int par, int mx_depth) {
    if (!chk[node])
        dp[node] = mx_depth;
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        if (chk[node])
            dfs2(i[0], node, i[1]);
        else
            dfs2(i[0], node, mx_depth + i[1]);
        if (chk[i[0]])
            mx_len[node] = max(mx_len[node], mx_len[i[0]] + i[1]);
    }
    if (!chk[node])
        mx_len[node] = 0;
}

void dfs3(int node, int par, int len) {
    multiset<int> st;
    int X;
    st.insert(0);

    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        if (chk[i[0]])
            st.insert(mx_len[i[0]] + i[1]);
    }

    mx[node] = max(len, *st.rbegin());

    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        if (chk[i[0]])
            X = mx_len[i[0]] + i[1], st.erase(st.find(X));
        dfs3(i[0], node, i[1] + max(len, *st.rbegin()));
        if (chk[i[0]])
            st.insert(mx_len[i[0]] + i[1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, Z;

    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z}), adj[Y].push_back({X, Z});
    }

    for (int i = 0; i < K; i++)
        cin >> X, A[X] = 1, Y = X;

    dfs1(1, 0), dfs2(Y, 0, 0), dfs3(Y, 0, 0);

    for (int i = 1; i <= N; i++)
        cout << val + dp[i] * 2 - mx[i] << '\n';

    return 0;
}