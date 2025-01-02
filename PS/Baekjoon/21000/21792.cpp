#include <bits/stdc++.h>
#define int long long

#define MAX 200100
using namespace std;

vector<int> adj[MAX];
int sz[MAX], res[MAX], tmp[MAX], cur[MAX];
bool vst[MAX];

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

void dfs(int node, int par, int dis, int cap) {
    cur[sz[node]] = max(cur[sz[node]], dis);
    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        dfs(i, node, dis + 1, cap);
    }
}

void divide_and_conquer(int node) {
    int cent = get_centroid(node, 0, get_size(node, 0));
    vst[cent] = true, get_size(cent, 0);

    for (int i : adj[cent]) {
        if (vst[i])
            continue;
        dfs(i, cent, 1, sz[cent] - sz[i]);
        for (int j = sz[i]; j >= 1; j--) {
            res[j] = max(res[j], tmp[j] + cur[j] + 1);
            cur[j - 1] = max(cur[j - 1], cur[j]);
            tmp[j] = max(tmp[j], cur[j]), cur[j] = 0;
        }
    }

    fill(&tmp[0], &tmp[sz[cent] + 1], 0);
    for (int i : adj[cent]) {
        if (vst[i])
            continue;
        divide_and_conquer(i);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    fill(res, res + N + 1, 1);
    divide_and_conquer(1);

    for (int i = 1; i <= N; i++) {
        if (i & 1)
            cout << 1 << '\n';
        else
            cout << res[i >> 1] << '\n';
    }

    return 0;
}