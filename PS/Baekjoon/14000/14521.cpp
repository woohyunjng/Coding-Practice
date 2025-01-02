#include <bits/stdc++.h>

#define MAX 300100

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

int N, S[MAX], sz[MAX];
bool chk[MAX];
ordered_set st[MAX * 2];
vector<int> adj[MAX];

int get_size(int node, int par) {
    int res = 1;
    for (int i : adj[node]) {
        if (i == par || chk[i])
            continue;
        res += get_size(i, node);
    }
    return sz[node] = res;
}

int get_centroid(int node, int par, int cap) {
    for (int i : adj[node]) {
        if (i == par || chk[i])
            continue;
        if (sz[i] * 2 > cap)
            return get_centroid(i, node, cap);
    }
    return node;
}

void dfs_first(int node, int par, int sum, int mn) {
    st[sum + N].insert(mn);

    for (int i : adj[node]) {
        if (i == par || chk[i])
            continue;
        dfs_first(i, node, sum + S[i], min(mn, sum + S[i]));
    }
}

long long dfs(int node, int par, int sum, int mx) {
    long long res = 0;
    if (sum - mx >= 0)
        res += (long long)st[-sum + N].size() - st[-sum + N].order_of_key(-sum);

    for (int i : adj[node]) {
        if (i == par || chk[i])
            continue;
        res += dfs(i, node, sum + S[i], max(mx, sum + S[i]));
    }
    return res;
}

void clear(int node, int par, int sum, int mn) {
    st[sum + N].erase(st[sum + N].find_by_order(st[sum + N].order_of_key(mn)));
    for (int i : adj[node]) {
        if (i == par || chk[i])
            continue;
        clear(i, node, sum + S[i], min(mn, sum + S[i]));
    }
}

long long divide_and_conquer(int node) {
    int cent = get_centroid(node, 0, get_size(node, 0));
    chk[cent] = true;

    long long res = 0;

    st[S[cent] + N].insert(S[cent]);
    for (int i : adj[cent]) {
        if (chk[i])
            continue;
        dfs_first(i, cent, S[cent] + S[i], min(S[cent], S[cent] + S[i]));
    }

    for (int i : adj[cent]) {
        if (chk[i])
            continue;
        clear(i, cent, S[cent] + S[i], min(S[cent], S[cent] + S[i]));
        res += dfs(i, cent, S[i], max(0, S[i]));
        dfs_first(i, cent, S[cent] + S[i], min(S[cent], S[cent] + S[i]));
    }
    res += (long long)st[0 + N].size() - st[0 + N].order_of_key(0);

    st[S[cent] + N].erase(st[S[cent] + N].find_by_order(st[S[cent] + N].order_of_key(S[cent])));
    for (int i : adj[cent]) {
        if (chk[i])
            continue;
        clear(i, cent, S[cent] + S[i], min(S[cent], S[cent] + S[i]));
    }

    for (int i : adj[cent]) {
        if (chk[i])
            continue;
        res += divide_and_conquer(i);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int U, V;
    string T;

    cin >> N >> T;
    for (int i = 1; i <= N; i++)
        S[i] = T[i - 1] == '(' ? 1 : -1;

    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    cout << divide_and_conquer(1) << '\n';

    return 0;
}