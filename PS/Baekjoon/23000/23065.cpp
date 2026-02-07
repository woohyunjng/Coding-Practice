#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

vector<int> adj[MAX];
int D[MAX], P[MAX];
bool ans_chk = true, chk[MAX];

void dfs(int node, int par) {
    D[node] = D[par] + 1, P[node] = par;
    for (int i : adj[node])
        if (i ^ par)
            dfs(i, node);
}

vector<int> path(int node, int par) {
    vector<int> res, tmp;
    res.push_back(node);
    for (int i : adj[node]) {
        if (i == par)
            continue;
        tmp = path(i, node);
        for (int j : tmp)
            res.push_back(j);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, X;
    vector<int> ans, arr, pth;

    cin >> N >> M;
    if (M != N - 1) {
        cout << "NO" << '\n';
        return 0;
    }

    while (M--) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    for (int i = 1; i <= N; i++)
        if (adj[i].size() == 1)
            chk[i] = true;

    for (int i = 1; i <= N; i++) {
        if (chk[i])
            continue;
        arr = adj[i], adj[i].clear();
        for (int j : arr)
            if (!chk[j])
                adj[i].push_back(j);
    }
    for (int i = 1; i <= N; i++)
        if (!chk[i])
            U = i;
    fill(chk + 1, chk + N + 1, false);

    dfs(U, 0), U = max_element(D + 1, D + N + 1) - D;
    dfs(U, 0), V = max_element(D + 1, D + N + 1) - D;

    if (N == 1)
        ans.push_back(1);
    else if (N == 2)
        ans.push_back(1), ans.push_back(1);
    else if (U == V)
        ans.push_back(U), ans.push_back(U);
    else {
        X = V, arr.clear();
        while (X)
            chk[X] = true, arr.push_back(X), X = P[X];

        for (int i = 0; i < arr.size(); i++) {
            ans.push_back(arr[i]);
            for (int j : adj[arr[i]]) {
                if (chk[j])
                    continue;
                ans_chk &= adj[j].size() == 1, ans.push_back(j), ans.push_back(arr[i]);
            }
        }

        X = ans.size();
        if (arr.size() & 1)
            for (int i = 0; i < X; i++)
                ans.push_back(ans[i]);
        else
            for (int i = X - 1; i >= 0; i--)
                ans.push_back(ans[i]);
    }

    if (ans_chk) {
        cout << "YES" << '\n';
        cout << ans.size() << '\n';
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
    } else
        cout << "NO" << '\n';

    return 0;
}