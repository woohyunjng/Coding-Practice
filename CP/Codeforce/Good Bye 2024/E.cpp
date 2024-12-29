#include <bits/stdc++.h>
#define int long long

#define MAX 200100
using namespace std;

vector<int> adj[MAX];
int sz[MAX], dp[2][MAX], able[MAX], val[MAX];
bool leaf[MAX], vst[MAX];

int get_size(int node, int par) {
    int res = 1;
    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        res += get_size(i, node);
    }
    return sz[node] = res;
}

int get_centroid(int node, int par, int cap) {
    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        if (sz[i] * 2 > cap)
            return get_centroid(i, node, cap);
    }
    return node;
}

int get_unable(int node, int par) {
    int res = able[node] == 0;
    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        res += get_unable(i, node);
    }
    return res;
}

int get_be_able(int node, int par) {
    int res = val[par] && !leaf[node];
    val[node] = (able[node] - leaf[par]) > 0;

    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        res += get_be_able(i, node);
    }
    return res;
}

int divide_and_conquer(int node) {
    int cent = get_centroid(node, -1, get_size(node, -1)), full = 0, res = 0;
    vst[cent] = true;

    full = able[cent] == 0;
    for (int i : adj[cent]) {
        if (vst[i])
            continue;
        val[cent] = able[cent] > 0;
        dp[0][i] = get_unable(i, cent), dp[1][i] = get_be_able(i, cent);
        full += dp[0][i];
    }

    for (int i : adj[cent]) {
        if (vst[i])
            continue;
        res += dp[1][i] * (full - dp[0][i]);
        if (able[i] > 0 && !leaf[cent])
            res += dp[0][i];
    }

    for (int i : adj[cent]) {
        if (vst[i])
            continue;
        res += divide_and_conquer(i);
    }

    return res;
}

void solve() {
    int N, U, V, res = 0, cnt = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        adj[i].clear(), vst[i] = false;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    for (int i = 1; i <= N; i++)
        leaf[i] = adj[i].size() == 1, cnt += leaf[i];

    for (int i = 1; i <= N; i++) {
        able[i] = leaf[i] ? 2 : 0;
        for (int j : adj[i])
            able[i] += leaf[j];
    }

    res = (N - cnt) * cnt;
    res += divide_and_conquer(1);

    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}