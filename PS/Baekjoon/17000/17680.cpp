#include <bits/stdc++.h>

#define MAX 200000

using namespace std;
typedef array<int, 2> pr;

int C[MAX], order[MAX], parent[MAX], sz[MAX], top[MAX], depth[MAX], tree[MAX], S;
vector<int> adj[MAX];
deque<pr> dq[MAX];

void dfs1(int node) {
    sz[node] = 1, depth[node] = depth[parent[node]] + 1;
    for (int i = 0; i < adj[node].size(); i++) {
        dfs1(adj[node][i]), sz[node] += sz[adj[node][i]];
        if (sz[adj[node][0]] < sz[adj[node][i]])
            swap(adj[node][0], adj[node][i]);
    }
}

void dfs2(int node) {
    for (int i : adj[node]) {
        top[i] = i == adj[node][0] ? top[node] : i;
        dfs2(i);
    }
}

int query(int x) {
    int res = 0;
    while (x)
        res += tree[x], x -= x & (-x);
    return res;
}

void update(int x, int v) {
    while (x <= S)
        tree[x] += v, x += x & (-x);
}

void clear(int x) {
    while (x <= S)
        tree[x] = 0, x += x & (-x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, K, D, res;
    pr X;

    vector<int> comp;
    vector<pr> arr;
    set<int> st;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> C[i], comp.push_back(C[i]);
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i = 1; i <= N; i++)
        C[i] = lower_bound(comp.begin(), comp.end(), C[i]) - comp.begin() + 1;
    S = comp.size();

    for (int i = 1; i < N; i++) {
        cin >> A >> B, order[i] = B, parent[B] = A;
        adj[A].push_back(B);
    }

    top[1] = 1;
    dfs1(1), dfs2(1);

    for (int i = 1; i < N; i++) {
        arr.clear(), A = parent[order[i]], res = 0;
        while (A) {
            arr.push_back({top[A], depth[A] - depth[top[A]] + 1});
            A = parent[top[A]];
        }
        reverse(arr.begin(), arr.end()), A = top[parent[order[i]]];

        for (pr j : arr) {
            K = 0;
            while (!dq[j[0]].empty() && K + dq[j[0]].front()[1] <= j[1]) {
                X = dq[j[0]].front(), dq[j[0]].pop_front(), st.insert(X[0]);
                res += (query(S) - query(X[0])) * X[1], update(X[0], X[1]), K += X[1];
            }

            if (K < j[1]) {
                if (!dq[j[0]].empty()) {
                    X = dq[j[0]].front(), dq[j[0]].pop_front(), st.insert(X[0]);
                    dq[j[0]].push_front({X[0], X[1] + K - j[1]});
                    res += (query(S) - query(X[0])) * (j[1] - K), update(X[0], j[1] - K);
                }
            }

            if (j[0] != A)
                dq[j[0]].push_front({C[order[i]], j[1]});
            else {
                if (A == top[order[i]])
                    j[1]++;
                else
                    dq[top[order[i]]].push_front({C[order[i]], 1});
                dq[A].push_front({C[order[i]], j[1]});
            }
        }

        cout << res << '\n';

        for (int j : st)
            clear(j);
        st.clear();
    }
}