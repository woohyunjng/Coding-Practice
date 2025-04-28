#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 300001;

int parent[2][MAX], G[MAX], sz[MAX];

vector<int> arr[MAX];
set<pr> adj[MAX];
set<int> st[MAX];

int find(int T, int X) { return X == parent[T][X] ? X : parent[T][X] = find(T, parent[T][X]); } // 0 -> cycle 1 -> tree
void uni(int T, int X, int Y) {                                                                 // X를 Y 집합에 넣기
    X = find(T, X), Y = find(T, Y);
    if (X == Y)
        return;
    parent[T][X] = Y;
}

vector<int> find_reachable(vector<int> R, vector<int> U, vector<int> V, vector<int> C) {
    int N = R.size(), M = C.size(), X, Y, K, Z;
    vector<int> ans(N, 0);

    queue<int> q;
    set<pr>::iterator iter;

    for (int i = 0; i < M; i++) {
        if (R[U[i]] == C[i])
            arr[U[i]].push_back(V[i]);
        else
            adj[U[i]].insert({C[i], V[i]});

        if (R[V[i]] == C[i])
            arr[V[i]].push_back(U[i]);
        else
            adj[V[i]].insert({C[i], U[i]});
    }

    for (int i = 0; i < N; i++) {
        if (!arr[i].empty())
            G[i] = arr[i].back(), arr[i].pop_back();
        else
            G[i] = i;
        q.push(i), st[i].insert(R[i]), sz[i] = 1;
        parent[0][i] = i, parent[1][i] = i;
    }

    while (!q.empty()) {
        K = q.front(), q.pop();
        if (K == G[K])
            continue;

        if (find(1, G[K]) != find(1, K))
            uni(1, K, G[K]);
        else {
            X = G[K];
            while (X != K) {
                if (sz[X] > sz[K])
                    swap(st[X], st[K]), swap(adj[X], adj[K]), swap(arr[X], arr[K]);

                for (int i : st[X]) {
                    if (st[K].find(i) != st[K].end())
                        continue;
                    iter = adj[K].lower_bound({i, 0});
                    while (iter != adj[K].end() && (*iter)[0] == i)
                        arr[X].push_back((*iter)[1]), iter = adj[K].erase(iter);
                    st[K].insert(i);
                }

                for (pr i : adj[X]) {
                    if (st[K].find(i[0]) != st[K].end())
                        arr[K].push_back(i[1]);
                    else
                        adj[K].insert(i);
                }

                for (int i : arr[X])
                    arr[K].push_back(i);

                st[X].clear(), adj[X].clear(), arr[X].clear(), sz[K] += sz[X], sz[X] = 0;

                uni(0, X, K), Y = G[X], G[X] = K;
                st[X].clear(), X = Y;
            }

            while (!arr[K].empty() && find(0, arr[K].back()) == K)
                arr[K].pop_back();

            if (!arr[K].empty())
                G[K] = arr[K].back(), arr[K].pop_back();
            else
                G[K] = K;

            q.push(K);
        }
    }

    set<int> mn;

    X = MAX;
    for (int i = 0; i < N; i++) {
        if (i == find(0, i) && i == find(1, i) && sz[i] < X)
            X = min(X, sz[i]), mn.clear(), mn.insert(i);
        else if (i == find(0, i) && i == find(1, i) && sz[i] == X)
            mn.insert(find(0, i));
    }

    for (int i = 0; i < N; i++)
        ans[i] = mn.find(find(0, i)) != mn.end();

    return ans;
}