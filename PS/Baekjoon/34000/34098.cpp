#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 4001;

int deg[MAX], out[MAX], D[MAX], cnt;
bool vst[MAX], chk[MAX];

vector<pr> adj[MAX];
vector<int> st, sadj[MAX], rsadj[MAX];

void dfs1(int node) {
    vst[node] = true;
    for (int i : sadj[node])
        if (!vst[i])
            dfs1(i);
    st.push_back(node);
}

void dfs2(int node) {
    D[node] = cnt;
    for (int i : rsadj[node])
        if (!D[i])
            dfs2(i);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, U, V;
    bool flag, flag2;

    cin >> T;
    while (T--) {
        cin >> N >> M;
        fill(deg, deg + N, 0);

        for (int i = 0; i < M; i++) {
            cin >> U >> V, U--, V--, out[i] = V;
            adj[U].push_back({V, i}), adj[V].push_back({U, i});
            deg[U]++, deg[V]++;
        }

        for (int i = 0; i < N; i++) {
            for (pr j : adj[i])
                chk[j[0]] = true;
            if (deg[i] >= 2) {
                for (pr j : adj[i])
                    for (pr k : adj[j[0]]) {
                        if (j[1] == k[1])
                            continue;
                        U = j[1] << 1 | (out[j[1]] != j[0]), V = k[1] << 1 | (out[k[1]] != k[0]);
                        if (deg[i] - 1 - chk[k[0]] == 0)
                            continue;
                        sadj[U ^ 1].push_back(V), sadj[V ^ 1].push_back(U);
                        rsadj[U].push_back(V ^ 1), rsadj[V].push_back(U ^ 1);
                    }
            }
            if (deg[i] >= 3) {
                for (int j = 0; j < adj[i].size(); j++)
                    for (int k = j + 1; k < adj[i].size(); k++) {
                        U = adj[i][j][1] << 1 | (out[adj[i][j][1]] != adj[i][j][0]);
                        V = adj[i][k][1] << 1 | (out[adj[i][k][1]] != adj[i][k][0]);
                        sadj[U ^ 1].push_back(V), sadj[V ^ 1].push_back(U);
                        rsadj[U].push_back(V ^ 1), rsadj[V].push_back(U ^ 1);
                    }
            }
            for (pr j : adj[i])
                chk[j[0]] = false;
        }

        cnt = 0, flag = true;
        for (int i = 0; i < M << 1; i++)
            if (!vst[i])
                dfs1(i);
        while (!st.empty()) {
            V = st.back(), st.pop_back();
            if (!D[V])
                cnt++, dfs2(V);
        }

        for (int i = 0; i < M; i++)
            flag &= D[i << 1] != D[i << 1 | 1];

        if (!flag)
            cout << -1 << '\n';
        else {
            for (int i = 0; i < M; i++)
                cout << (D[i << 1] > D[i << 1 | 1]) << ' ';
            cout << '\n';
        }

        for (int i = 0; i < N; i++)
            deg[i] = 0, adj[i].clear();
        for (int i = 0; i < M << 1; i++)
            vst[i] = false, D[i] = 0, sadj[i].clear(), rsadj[i].clear();
    }

    return 0;
}