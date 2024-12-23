#include <bits/stdc++.h>
#define int long long

#define MAX 100100
using namespace std;

int N, C[MAX], sz[MAX];
bool vst[MAX];
map<int, int> dis;
vector<int> adj[MAX];

int get_size(int node, int pr) {
    int res = 1;
    for (int i : adj[node]) {
        if (i == pr || vst[i])
            continue;
        res += get_size(i, node);
    }
    return sz[node] = res;
}

int get_centroid(int node, int pr, int cap) {
    for (int i : adj[node]) {
        if (i == pr || vst[i])
            continue;
        if (sz[i] * 2 > cap)
            return get_centroid(i, node, cap);
    }
    return node;
}

int dfs(int node, int pr, int depth) {
    int res = N + 1;
    if (dis.find(C[node]) != dis.end())
        res = depth + dis[C[node]], dis[C[node]] = min(dis[C[node]], depth);
    else
        dis[C[node]] = depth;
    for (int i : adj[node]) {
        if (i == pr || vst[i])
            continue;
        res = min(res, dfs(i, node, depth + 1));
    }
    return res;
}

int divide_and_conquer(int node) {
    int cent = get_centroid(node, 0, get_size(node, 0)), res = N + 1;
    vst[cent] = true, dis.clear();

    dis[C[cent]] = 0;
    for (int i : adj[cent]) {
        if (vst[i])
            continue;
        res = min(res, dfs(i, cent, 1));
    }

    for (int i : adj[cent]) {
        if (vst[i])
            continue;
        res = min(res, divide_and_conquer(i));
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, Y;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> C[i];
    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    cout << divide_and_conquer(1) << '\n';

    return 0;
}