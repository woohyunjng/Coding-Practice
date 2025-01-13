#include <bits/stdc++.h>
#define int long long

#define MAX 10010

using namespace std;
typedef array<int, 2> pr;

int sz[MAX];
vector<int> adj[MAX], children[MAX];

int get_size(int node, int par) {
    int res = 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        res += get_size(i, node);
    }
    return sz[node] = res;
}

int get_centroid(int node, int par, int cap) {
    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (sz[i] * 2 > cap)
            return get_centroid(i, node, cap);
    }
    return node;
}

void dfs(int node, int par, int group) {
    children[group].push_back(node);
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node, group);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, cent, cnt;
    pr X, Y;

    vector<int> res;
    priority_queue<pr> pq;

    while (cin >> N) {
        for (int i = 1; i < N; i++)
            cin >> A, adj[A].push_back(i), adj[i].push_back(A);

        cent = get_centroid(0, -1, get_size(0, -1)), cnt = N - 1, A = -1;
        res.push_back(cent);

        for (int i : adj[cent]) {
            dfs(i, cent, i);
            pq.push({(int)children[i].size(), i});
        }

        while (cnt--) {
            X = pq.top(), pq.pop();
            if (X[1] == A) {
                Y = pq.top(), pq.pop();
                pq.push(X), X = Y;
            }

            A = X[1], pq.push({X[0] - 1, X[1]});
            res.push_back(children[A].back()), children[A].pop_back();
        }

        for (int i : res)
            cout << i << ' ';
        cout << '\n';

        res.clear();
        while (!pq.empty())
            pq.pop();
        for (int i = 0; i < N; i++)
            adj[i].clear(), children[i].clear();
    }

    return 0;
}