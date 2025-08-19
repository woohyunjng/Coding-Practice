#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

vector<int> adj[MAX];
int depth[MAX], S[MAX], parent[MAX];
bool vst[MAX], chk[MAX];

void dfs(int node, int par) {
    int cnt = 0;
    parent[node] = par, S[node] = 0;
    for (int i : adj[node]) {
        if (depth[i] != -1)
            continue;
        depth[i] = depth[node] + 1, dfs(i, node);
        S[node] += S[i], cnt++;
    }
    chk[node] = cnt > 1, S[node] += chk[node];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, RT;
    bool flag;

    cin >> N >> M;

    while (M--) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    fill(depth, depth + N, -1), depth[0] = 0, dfs(0, -1);
    RT = max_element(depth, depth + N) - depth;
    fill(depth, depth + N, -1), depth[RT] = 0, dfs(RT, -1);

    if (S[RT] == 0) {
        cout << N * 2 << '\n';
        for (int i = 0; i < N * 2; i++) {
            for (int j = 0; j < N; j++) {
                if ((depth[j] & 1) == (i & 1))
                    cout << (parent[j] == -1 ? j : parent[j]) << ' ';
                else
                    cout << j << ' ';
            }
            cout << '\n';
        }
        return 0;
    }

    V = -1;
    for (int i = 0; i < N; i++) {
        if (S[i] != 1 || !chk[i] || i == RT)
            continue;
        if (V == -1 || depth[V] < depth[i])
            V = i;
    }

    flag = false;
    for (int i = 0; i < N; i++) {
        if (parent[i] != V || flag)
            continue;

        RT = i, flag = true;
        for (int j : adj[i])
            flag &= j != parent[V];
    }

    fill(depth, depth + N, -1), depth[RT] = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (parent[j] == RT || (parent[j] != -1 && vst[parent[j]]))
                vst[j] = true, depth[j] = depth[parent[j]] + 1;

    adj[RT].erase(find(adj[RT].begin(), adj[RT].end(), V)), adj[RT].insert(adj[RT].begin(), V);
    if (flag)
        adj[V].erase(find(adj[V].begin(), adj[V].end(), parent[V])), adj[V].insert(adj[V].begin(), parent[V]);
    else
        partition(adj[V].begin(), adj[V].end(), [&](int x) { return parent[x] == V; });
    dfs(RT, -1);

    cout << N * 6 << '\n';
    for (int i = 0; i < N * 6; i++) {
        for (int j = 0; j < N; j++) {
            if (i % 3 == 0) {
                if (!vst[j] && depth[j] <= 2)
                    cout << RT << ' ';
                else if (depth[j] & 1)
                    cout << j << ' ';
                else
                    cout << (parent[j] == -1 ? j : parent[j]) << ' ';
            } else if (i % 3 == 1) {
                if ((depth[j] & 1) && (depth[j] > 1 || !vst[j]))
                    cout << parent[j] << ' ';
                else
                    cout << j << ' ';
            } else {
                if (j == RT || (vst[j] && depth[j] == 1))
                    cout << RT << ' ';
                else
                    cout << j << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
