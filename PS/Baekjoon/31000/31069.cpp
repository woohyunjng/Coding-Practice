#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

typedef array<int, 2> pr;

vector<pr> adj[MAX], cadj[MAX];
vector<int> vc[MAX], comp[MAX], badj[MAX], ans, arr;

list<int>::iterator pos[MAX];

int P[MAX], D[MAX], L[MAX], S[MAX], C[MAX], PC[MAX], F[MAX], cnt;
bool ans_chk = true, chk[MAX];

void dfs1(int node, int par) {
    P[node] = par, D[node] = D[par] + 1, L[node] = node;
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        if (!D[i[0]]) {
            dfs1(i[0], node);
            if (D[L[node]] > D[L[i[0]]])
                L[node] = L[i[0]];
        } else if (D[i[0]] < D[node]) {
            if (D[L[node]] > D[i[0]])
                L[node] = i[0];
        }
    }
}

void dfs2(int node, int par) {
    for (pr i : adj[node]) {
        if (P[i[0]] == node) {
            if (D[L[i[0]]] >= D[node])
                PC[i[0]] = C[i[1]] = ++cnt;
            else
                PC[i[0]] = C[i[1]] = PC[node];
            dfs2(i[0], node);
        } else if (D[i[0]] < D[node])
            C[i[1]] = PC[node];
    }
}

void dfs3(int node, int par) {
    P[node] = par, D[node] = D[par] + 1, L[node] = node;
    arr.push_back(node);

    for (int i : badj[node]) {
        if (i == par)
            continue;
        if (!D[i]) {
            dfs3(i, node);
            if (D[L[node]] > D[L[i]])
                L[node] = L[i];
        } else if (D[L[node]] > D[i])
            L[node] = i;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, PV = -1, U, EU, V, ST = 0;
    list<int> lst;

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> U >> V;
        adj[U].push_back({V, i}), adj[V].push_back({U, i});
    }

    dfs1(1, 0), dfs2(1, 0);

    for (int i = 1; i <= N; i++) {
        for (pr j : adj[i])
            vc[i].push_back(C[j[1]]);
        sort(vc[i].begin(), vc[i].end()), vc[i].erase(unique(vc[i].begin(), vc[i].end()), vc[i].end());
        ans_chk &= vc[i].size() <= 2;
        for (int j : vc[i])
            comp[j].push_back(i);
    }

    for (int i = 1; i <= cnt && ans_chk; i++) {
        for (int j : comp[i])
            for (int k : vc[j])
                if (k != i)
                    cadj[i].push_back({k, j});
        sort(cadj[i].begin(), cadj[i].end()), cadj[i].erase(unique(cadj[i].begin(), cadj[i].end()), cadj[i].end());
        ans_chk &= (cadj[i].size() <= 2);
        if (cadj[i].size() <= 1)
            ST = i;
    }

    if (!ans_chk) {
        cout << -1 << '\n';
        return 0;
    }

    while (ST != -1) {
        U = V = -1, chk[ST] = true;
        for (pr i : cadj[ST]) {
            if (chk[i[0]])
                continue;
            V = i[0], U = i[1];
        }
        if (PV == -1) {
            for (int i : comp[ST])
                if (i != U)
                    PV = i;
        }
        EU = U;
        if (EU == -1)
            for (int i : comp[ST])
                if (i != PV)
                    EU = i;
        badj[PV].clear(), badj[EU].clear(), arr.clear(), lst.clear();
        for (int i : comp[ST])
            P[i] = D[i] = L[i] = S[i] = 0, badj[i].clear(), F[i] = ST;
        badj[PV].push_back(EU), badj[EU].push_back(PV);
        for (int i : comp[ST])
            for (pr j : adj[i])
                if (F[j[0]] == ST)
                    badj[i].push_back(j[0]);

        dfs3(PV, 0);
        for (int i : arr) {
            if (i == PV || i == EU)
                pos[i] = lst.insert(lst.end(), i);
            else {
                if (S[L[i]] == 1)
                    S[P[i]] = 0, pos[i] = lst.insert(next(pos[P[i]]), i);
                else
                    S[P[i]] = 1, pos[i] = lst.insert(pos[P[i]], i);
            }
        }
        for (int i : lst)
            ans.push_back(i);
        if (U != -1)
            ans.pop_back();
        ST = V, PV = U;
    }

    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}