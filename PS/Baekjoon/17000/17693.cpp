#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define MAX 1000400
#define MOD 1000000007

using namespace std;
typedef array<int, 2> pr;

int S, val[MAX * 2], num[MAX * 2], C[MAX];
vector<int> tree[MAX * 2], adj[MAX];

void query(int l, int r, int v) {
    for (l += S - 1, r += S; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            for (int i : tree[l])
                adj[i].push_back(v), adj[v].push_back(i);
            while (tree[l].size() > 1)
                tree[l].pop_back();
            l++;
        }
        if (r & 1) {
            r--;
            for (int i : tree[r])
                adj[i].push_back(v), adj[v].push_back(i);
            while (tree[r].size() > 1)
                tree[r].pop_back();
        }
    }
}

void update(int x, int v) {
    for (tree[x += S - 1].push_back(v); x > 1; x >>= 1)
        tree[x >> 1].push_back(v);
}

bool dfs(int node, int par) {
    for (int i : adj[node]) {
        if (i == par || C[i] == 3 - C[node])
            continue;
        if (C[i] == C[node])
            return false;
        C[i] = 3 - C[node];
        if (!dfs(i, node))
            return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans = 1;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> X >> Y, val[X] = Y, num[X] = i;
    S = N << 1;

    for (int i = 1; i <= (N << 1); i++) {
        if (!val[i])
            continue;
        query(i, val[i], num[i]);
        update(val[i], num[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (C[i])
            continue;
        C[i] = 1;
        ans = ((dfs(i, 0) ? ans : 0) << 1) % MOD;
    }

    cout << ans << '\n';

    return 0;
}