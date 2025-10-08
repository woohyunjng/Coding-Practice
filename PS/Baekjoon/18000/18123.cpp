#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 31;

vector<int> adj[MAX], cent;
int sz[MAX], val[MAX];

int get_sz(int node, int par) {
    sz[node] = 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        sz[node] += get_sz(i, node);
    }
    return sz[node];
}

void get_cent(int node, int par, int cap) {
    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (sz[i] * 2 >= cap) {
            if (sz[i] * 2 == cap)
                cent.push_back(node);
            get_cent(i, node, cap);
            return;
        }
    }
    cent.push_back(node);
}

void dfs(int node, int par) {
    vector<int> arr;

    sz[node] = 2, val[node] = 0;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), sz[node] += sz[i];
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [](int x, int y) { return val[x] < val[y]; });
    for (int i : arr)
        val[node] <<= sz[i], val[node] |= val[i];
    val[node] <<= 1ll, val[node] |= 1ll;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, U, V, C, ans = 0;
    vector<int> comp;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 1; j < S; j++) {
            cin >> U >> V, U++, V++;
            adj[U].push_back(V), adj[V].push_back(U);
        }

        cent.clear(), get_cent(1, 0, get_sz(1, 0)), V = 0;

        if (cent.size() == 2) {
            adj[cent[0]].erase(find(adj[cent[0]].begin(), adj[cent[0]].end(), cent[1]));
            adj[cent[1]].erase(find(adj[cent[1]].begin(), adj[cent[1]].end(), cent[0]));
            adj[cent[0]].push_back(S + 1), adj[cent[1]].push_back(S + 1), C = S + 1, V = 1;
            adj[S + 1].push_back(cent[0]), adj[S + 1].push_back(cent[1]);
        } else
            C = cent[0];

        dfs(C, 0), U = val[C] << 1 | V;
        comp.push_back(U);

        for (int j = 1; j <= S + 1; j++)
            sz[j] = 0, adj[j].clear();
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
    cout << comp.size() << '\n';

    return 0;
}