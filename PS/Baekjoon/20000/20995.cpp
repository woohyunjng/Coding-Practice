#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;

vector<int> adj[MAX];
int T[MAX], D[MAX], K[MAX], ans;

void dfs(int node, int par) {
    D[node] = T[node] ? -1 : 0;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (T[i] && T[node])
            ans = max(ans, 2);
        dfs(i, node), D[node] += max(0, D[i]);
    }
    D[node] = max(D[node], T[node] ? 1 : 0), ans = max(ans, D[node]);
}

void rrt_dfs(int node, int par, int val) {
    int V = T[node] ? -1 : 0;
    V += max(0, val);

    multiset<int> st;
    st.insert(T[node] ? 1 : 0), st.insert(V);

    for (int i : adj[node]) {
        if (i == par)
            continue;
        V += max(0, D[i]), K[i] = (T[node] ? -1 : 0) + max(0, D[i]);
        st.insert(K[i]);
    }
    ans = max(ans, V);

    for (int i : adj[node]) {
        if (i == par)
            continue;
        st.erase(st.find(K[i]));
        rrt_dfs(i, node, *st.rbegin());
        st.insert(K[i]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;
    bool flag;
    string _S;

    cin >> N, ans = 1;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y, X--, Y--;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    cin >> _S;
    for (int i = 0; i < N; i++)
        T[i] = _S[i] - '0';

    dfs(0, -1), rrt_dfs(0, -1, 0);
    cout << ans << '\n';

    return 0;
}