#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;

vector<int> adj[MAX], rev[MAX], scc[MAX], st;
int cnt, grp[MAX];
bool chk[MAX];

void dfs1(int node) {
    chk[node] = true;
    for (int i : adj[node]) {
        if (!chk[i])
            dfs1(i);
    }
    st.push_back(node);
}

void dfs2(int node) {
    chk[node] = true;
    for (int i : rev[node]) {
        if (!chk[i])
            dfs2(i);
    }
    scc[cnt].push_back(node), grp[node] = cnt;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, U, V;
    vector<int> ans;

    cin >> T;
    while (T--) {
        cin >> N >> M;
        while (M--) {
            cin >> U >> V;
            adj[U].push_back(V), rev[V].push_back(U);
        }

        for (int i = 0; i < N; i++)
            if (!chk[i])
                dfs1(i);

        fill(chk, chk + N, false);
        while (!st.empty()) {
            V = st.back(), st.pop_back();
            if (!chk[V])
                cnt++, dfs2(V);
        }

        fill(chk, chk + N, false);
        for (int i = 1; i <= cnt; i++) {
            for (int j : scc[i])
                for (int k : adj[j])
                    if (grp[j] != grp[k])
                        chk[grp[k]] = true;
        }

        for (int i = 1; i <= cnt; i++)
            if (!chk[i])
                ans.push_back(i);

        if (ans.size() != 1)
            cout << "Confused\n";
        else {
            sort(scc[ans[0]].begin(), scc[ans[0]].end());
            for (int i : scc[ans[0]])
                cout << i << '\n';
        }
        cout << '\n';

        for (int i = 0; i < N; i++)
            adj[i].clear(), rev[i].clear(), chk[i] = false, scc[i].clear();
        st.clear(), ans.clear(), cnt = 0;
    }

    return 0;
}