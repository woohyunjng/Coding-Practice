#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;

vector<int> adj[MAX];
vector<pr> st;
vector<vector<pr>> bcc;

int depth[MAX], V[MAX];
bool state[MAX];

void dfs(int node, int par) {
    pr K;
    V[node] = depth[node] = depth[par] + 1;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (depth[i] < depth[node])
            st.push_back({node, i});

        if (!depth[i]) {
            dfs(i, node), V[node] = min(V[node], V[i]);
            if (V[i] >= depth[node]) {
                bcc.push_back({});
                while (true) {
                    K = st.back(), st.pop_back();
                    bcc.back().push_back(K);
                    if (K[0] == node && K[1] == i)
                        break;
                }
            }
        } else
            V[node] = min(V[node], depth[i]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, X, Y, ans;
    bool flag;

    cin >> T;
    while (T--) {
        cin >> N >> M, ans = 0;

        bcc.clear(), st.clear();
        for (int i = 1; i <= N; i++)
            adj[i].clear(), depth[i] = V[i] = 0, state[i] = false;

        while (M--) {
            cin >> X >> Y;
            adj[X].push_back(Y), adj[Y].push_back(X);
        }

        for (int i = 1; i <= N; i++)
            if (!depth[i])
                dfs(i, 0);

        for (vector<pr> i : bcc) {
            flag = false;
            for (pr j : i)
                flag |= abs(depth[j[0]] - depth[j[1]]) % 2 == 0;
            if (flag)
                for (pr j : i)
                    state[j[0]] = state[j[1]] = true;
        }

        for (int i = 1; i <= N; i++)
            ans += state[i];

        cout << ans << '\n';
    }
}