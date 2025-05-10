#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 100000;

vector<int> adj[MAX];
vector<pr> ans;
int S[MAX];

void dfs(int node, int par) {
    S[node] = 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), S[node] += S[i];
    }
}

bool chk_cent_tree(int node, int par) {
    bool res = true;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (S[i] * 2 > S[node])
            res = false;
        res &= chk_cent_tree(i, node);
    }
    return res;
}

int get_cent(int node, int par, int cap) {
    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (S[i] * 2 > cap)
            return get_cent(i, node, cap);
    }
    return node;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, R;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y, ans.push_back({X, Y});
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs(1, 0), R = get_cent(1, 0, N), dfs(R, 0);

    if (!chk_cent_tree(R, 0)) {
        cout << -1 << '\n';
        return 0;
    }

    for (pr i : ans)
        cout << i[0] << ' ' << i[1] << '\n';

    return 0;
}