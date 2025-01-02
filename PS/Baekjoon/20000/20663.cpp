#include <bits/stdc++.h>
#define int long long

#define MAX 200100

using namespace std;
typedef pair<int, int> pr;

vector<pr> adj[MAX], arr;
int K, sz[MAX], tree[MAX];
bool vst[MAX];

void update(int n, int val) {
    n++;
    for (; n < MAX; n += n & -n)
        tree[n] += val;
}

int query(int n) {
    n++;
    if (n < 0)
        return 0;
    int res = 0;
    for (; n; n -= n & -n)
        res += tree[n];
    return res;
}

int get_size(int node, int par) {
    int res = 1;
    for (pr i : adj[node]) {
        if (i.first == par || vst[i.first])
            continue;
        res += get_size(i.first, node);
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

void dfs(int node, int par, int depth, int mx) {
    arr.push_back({mx, depth});
    for (pr i : adj[node]) {
        if (i.first == par || vst[i.first])
            continue;
        dfs(i.first, node, depth + 1, max(mx, i.second));
    }
}

int divide_and_conquer(int node) {
    int cent = get_centroid(node, 0, get_size(node, 0)), res = 0;
    vst[cent] = true;

    arr.clear(), dfs(cent, 0, 0, 0);
    sort(arr.begin(), arr.end());
    for (pr i : arr) {
        res += query(i.first - i.second - K);
        update(i.second, 1);
    }
    for (pr i : arr)
        update(i.second, -1);

    for (pr i : adj[cent]) {
        if (vst[i.first])
            continue;
        arr.clear(), dfs(i.first, cent, 1, i.second);
        sort(arr.begin(), arr.end());
        for (pr j : arr) {
            res -= query(j.first - j.second - K);
            update(j.second, 1);
        }
        for (pr j : arr)
            update(j.second, -1);
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

    int N, A, B, C;
    cin >> N >> K;

    for (int i = 1; i < N; i++) {
        cin >> A >> B >> C;
        adj[A].push_back({B, C}), adj[B].push_back({A, C});
    }

    cout << divide_and_conquer(1) * 2 << '\n';

    return 0;
}