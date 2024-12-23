#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define INF 5000000000000000

using namespace std;
typedef pair<int, int> pr;

int N, sz[MAX], res[MAX], dis[MAX];
bool vst[MAX];

vector<pr> adj[MAX];
vector<int> arr[MAX];

int get_size(int node, int parent) {
    int res = 1;
    for (int i : arr[node])
        dis[i] = dis[i ^ 1] = INF;
    for (pr i : adj[node]) {
        if (i.first == parent || vst[i.first])
            continue;
        res += get_size(i.first, node);
    }
    return sz[node] = res;
}

int get_centroid(int node, int parent, int cap) {
    for (pr i : adj[node]) {
        if (i.first == parent || vst[i.first])
            continue;
        if (sz[i.first] * 2 > cap)
            return get_centroid(i.first, node, cap);
    }
    return node;
}

void dfs(int node, int parent, int depth) {
    for (int i : arr[node]) {
        res[i >> 1] = min(res[i >> 1], depth + dis[i ^ 1]);
        dis[i] = min(dis[i], depth);
    }

    for (pr i : adj[node]) {
        if (i.first == parent || vst[i.first])
            continue;
        dfs(i.first, node, depth + i.second);
    }
}

void divide_and_conquer(int node) {
    int cent = get_centroid(node, -1, get_size(node, -1));
    vst[cent] = true;

    for (int i : arr[cent])
        dis[i] = 0;

    for (pr i : adj[cent]) {
        if (vst[i.first])
            continue;
        dfs(i.first, cent, i.second);
    }

    for (pr i : adj[cent]) {
        if (vst[i.first])
            continue;
        divide_and_conquer(i.first);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, D;

    cin >> N >> Q;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y >> D;
        adj[X].push_back({Y, D}), adj[Y].push_back({X, D});
    }

    for (int i = 1; i <= Q; i++) {
        cin >> X >> Y;
        while (X--)
            cin >> D, arr[D].push_back(2 * i);
        while (Y--)
            cin >> D, arr[D].push_back(2 * i + 1);
    }

    fill(res + 1, res + Q + 1, INF);
    divide_and_conquer(0);

    for (int i = 1; i <= Q; i++)
        cout << res[i] << '\n';

    return 0;
}