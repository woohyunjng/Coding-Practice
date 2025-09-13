#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 250001;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<pr> tmp_adj[MAX], adj[MAX];
vector<int> tree_adj[MAX], leaves;
int A[MAX], B[MAX], ans[MAX], sz[MAX], fam[MAX], T[MAX][2], D[MAX], G[MAX];
bool vst[MAX], leaf[MAX];

int get_sz(int node, int par) {
    sz[node] = 1;
    for (int i : tree_adj[node]) {
        if (i == par || vst[i])
            continue;
        sz[node] += get_sz(i, node);
    }
    return sz[node];
}

int get_cent(int node, int par, int cap) {
    for (int i : tree_adj[node]) {
        if (i == par || vst[i])
            continue;
        if (sz[i] * 2 > cap)
            return get_cent(i, node, cap);
    }
    return node;
}

void dfs1(int node, int par, int f) {
    fam[node] = f;

    if (leaf[node])
        T[f][0] = min(T[f][0], node), T[f][1] = max(T[f][1], node);

    for (int i : tree_adj[node]) {
        if (i == par || vst[i])
            continue;
        dfs1(i, node, f);
    }
}

void dfs2(int node, int par) {
    D[node] = INF;
    for (int i : tree_adj[node]) {
        if (i == par || vst[i])
            continue;
        dfs2(i, node);
    }
}

void dfs3(int node, int par, int g) {
    fam[node] = -1, G[node] = g;
    for (int i : tree_adj[node]) {
        if (i == par || vst[i])
            continue;
        dfs3(i, node, g);
    }
}

void dnc(int node, vector<int> &arr) {
    int cent = get_cent(node, -1, get_sz(node, -1));

    vector<int> val, num, snt[3], lst;
    int X;

    dfs3(cent, -1, cent);
    for (int i = 0; i < tree_adj[cent].size(); i++) {
        if (vst[tree_adj[cent][i]])
            continue;
        if (val.size() == 3)
            while (true)
                continue;
        T[val.size()][0] = INF, T[val.size()][1] = 0, num.push_back((int)val.size());
        val.push_back(tree_adj[cent][i]), dfs1(tree_adj[cent][i], cent, (int)val.size() - 1);
    }

    for (int i : arr) {
        if (fam[A[i]] == fam[B[i]] && fam[A[i]] != -1)
            snt[fam[A[i]]].push_back(i);
    }

    sort(num.begin(), num.end(), [](int a, int b) { return T[a][0] < T[b][0]; });

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    for (int i = 0; i < num.size(); i++) {
        if (T[num[i]][0] <= T[num[i]][1])
            lst.push_back(T[num[i]][0]), lst.push_back(T[num[i]][1]);
    }
    lst.push_back(cent);

    for (int i : lst) {
        dfs2(cent, -1);
        D[i] = 0, pq.push({0, i});

        while (!pq.empty()) {
            K = pq.top(), pq.pop();
            if (D[K[1]] < K[0])
                continue;

            for (pr j : adj[K[1]]) {
                if (G[j[0]] != cent || D[j[0]] <= D[K[1]] + j[1])
                    continue;
                D[j[0]] = D[K[1]] + j[1], pq.push({D[j[0]], j[0]});
            }
        }

        for (int i : arr)
            ans[i] = min(ans[i], D[A[i]] + D[B[i]]);
    }

    vst[cent] = true;
    for (int i = 0; i < val.size(); i++)
        dnc(val[i], snt[i]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, U, V, C, K = 0;
    vector<int> arr;

    cin >> N;
    for (int i = 2; i <= N; i++) {
        cin >> U >> C;
        tmp_adj[U].push_back({i, C});
    }

    C = N;
    for (int i = 1; i <= N; i++) {
        if (tmp_adj[i].empty())
            leaf[i] = true, leaves.push_back(i);

        if (tmp_adj[i].size() <= 2) {
            for (pr j : tmp_adj[i]) {
                adj[i].push_back(j), adj[j[0]].push_back({i, j[1]});
                tree_adj[i].push_back(j[0]), tree_adj[j[0]].push_back(i);
            }
            tmp_adj[i].clear();
            continue;
        }

        V = i;
        for (int j = 0; j < tmp_adj[i].size() - 1; j++) {
            adj[V].push_back(tmp_adj[i][j]), adj[tmp_adj[i][j][0]].push_back({V, tmp_adj[i][j][1]});
            tree_adj[V].push_back(tmp_adj[i][j][0]), tree_adj[tmp_adj[i][j][0]].push_back(V);

            adj[V].push_back({++C, 0}), adj[C].push_back({V, 0});
            tree_adj[V].push_back(C), tree_adj[C].push_back(V), V = C;
        }

        adj[V].push_back(tmp_adj[i].back()), adj[tmp_adj[i].back()[0]].push_back({V, tmp_adj[i].back()[1]});
        tree_adj[V].push_back(tmp_adj[i].back()[0]), tree_adj[tmp_adj[i].back()[0]].push_back(V);
        tmp_adj[i].clear();
    }

    for (int i = 0; i < leaves.size(); i++) {
        cin >> C, U = leaves[i], V = leaves[(i + 1) % leaves.size()];
        adj[U].push_back({V, C}), adj[V].push_back({U, C});
    }

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> A[i] >> B[i], ans[i] = INF;
        arr.push_back(i);
    }

    dnc(1, arr);

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}