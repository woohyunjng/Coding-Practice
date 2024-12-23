#include <bits/stdc++.h>
#define int long long

#define MAX 100100

using namespace std;
typedef pair<int, int> pr;

vector<pr> adj[MAX];
map<int, int> cnt[2], cur;
int sz[MAX];
bool vst[MAX];

int get_sz(int node, int par) {
    int res = 1;
    for (pr i : adj[node]) {
        if (i.first == par || vst[i.first])
            continue;
        res += get_sz(i.first, node);
    }
    return sz[node] = res;
}

int get_centroid(int node, int par, int cap) {
    for (pr i : adj[node]) {
        if (i.first == par || vst[i.first])
            continue;
        if (sz[i.first] * 2 > cap)
            return get_centroid(i.first, node, cap);
    }
    return node;
}

int dfs(int node, int par, int sum) {
    int res = 0;
    if (cur[sum] > 0)
        res = cnt[0][-sum] + cnt[1][-sum];
    else
        res = cnt[1][-sum];

    if (sum == 0 && cur[sum] > 1)
        res++;

    cur[sum]++;
    for (pr i : adj[node]) {
        if (i.first == par || vst[i.first])
            continue;
        res += dfs(i.first, node, sum + i.second);
    }
    cur[sum]--;
    return res;
}

void update_dfs(int node, int par, int sum) {
    if (cur[sum] > 0)
        cnt[1][sum]++;
    else
        cnt[0][sum]++;

    cur[sum]++;
    for (pr i : adj[node]) {
        if (i.first == par || vst[i.first])
            continue;
        update_dfs(i.first, node, sum + i.second);
    }
    cur[sum]--;
}

int divide_and_conquer(int node) {
    int cent = get_centroid(node, -1, get_sz(node, -1)), res = 0;
    vst[cent] = true, cnt[0].clear(), cnt[1].clear(), cur.clear();

    cur[0] = 1;
    for (pr i : adj[cent]) {
        if (vst[i.first])
            continue;
        res += dfs(i.first, cent, i.second);
        update_dfs(i.first, cent, i.second);
    }

    for (pr i : adj[cent]) {
        if (vst[i.first])
            continue;
        res += divide_and_conquer(i.first);
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, D;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y >> D;
        D = D == 1 ? 1 : -1;
        adj[X].push_back({Y, D}), adj[Y].push_back({X, D});
    }

    cout << divide_and_conquer(1) << '\n';

    return 0;
}