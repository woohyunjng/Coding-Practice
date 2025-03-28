#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 400001;

vector<pr> tmp[MAX], adj[MAX];
vector<int> ans;

int K, out[MAX], cnt[MAX], state[MAX], base[MAX], val;
bool chk[MAX];

void dfs(int node, int par) {
    cnt[node]++;
    if (par != -1)
        ans.push_back(par);
    if (node == K && par != -1 && val == 0)
        return;

    pr X = {-1, -1}, Y;
    for (pr i : adj[node]) {
        if (cnt[i[0]] >= 8 || state[i[1]] == 1 || i[1] / 2 == par || chk[i[0]])
            continue;
        Y = i;
        if (state[i[1]] != base[i[1]])
            X = i;
    }
    if (X[0] == -1)
        X = Y;
    val += (state[X[1]] == base[X[1]]) ? 1 : -1;
    state[X[1]] ^= 1, state[X[1] ^ 1] ^= 1;
    dfs(X[0], X[1] / 2);
    return;
}

void erase(int node) {
    chk[node] = true;
    for (pr i : tmp[node]) {
        if (state[i[1]] == 0 || chk[i[0]])
            continue;
        if (--out[i[0]] == 0)
            erase(i[0]);
    }
}

variant<bool, vector<int>> find_journey(
    int N, int M, vector<int> U, vector<int> V) {

    int X, Y;
    vector<int> ret, st;

    for (int i = 0; i < M; i++) {
        tmp[U[i]].push_back({V[i], i << 1});
        tmp[V[i]].push_back({U[i], i << 1 | 1});
        out[U[i]]++, state[i << 1 | 1] = base[i << 1 | 1] = 1;
    }

    for (int i = 0; i < N; i++)
        if (out[i] == 0 && !chk[i])
            erase(i);

    if (chk[0])
        return false;

    K = 0;
    while (true) {
        chk[K] = true, X = 0;
        for (pr i : tmp[K]) {
            if (state[i[1]] == 0 && !chk[i[0]])
                X++;
        }

        if (X == 0)
            return false;
        else if (X >= 2) {
            chk[K] = false;
            break;
        }

        for (pr i : tmp[K]) {
            if (state[i[1]] == 0 && !chk[i[0]])
                Y = i[0], st.push_back(i[1] / 2);
        }
        erase(K), K = Y;
    }

    for (int i = 0; i < N; i++) {
        if (chk[i])
            continue;
        for (pr j : tmp[i]) {
            if (chk[j[0]])
                continue;
            adj[i].push_back(j);
        }
    }

    dfs(K, -1);

    ret = st;
    for (int i : ans)
        ret.push_back(i);
    reverse(st.begin(), st.end());
    for (int i : st)
        ret.push_back(i);

    return ret;
}