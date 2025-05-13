#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 200001;

int uf[MAX], V[MAX], parent[MAX], D[MAX];
vector<pr> adj[MAX];
multiset<pr> S[MAX], T[MAX];

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }
void merge(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    uf[max(X, Y)] = min(X, Y);
}

void dfs(int node, int par) {
    parent[node] = par;
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        dfs(i[0], node), D[i[0]] = i[1];
        T[node].insert({V[i[0]], i[1]});
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, Q, A, B, L, P;
    pr X;

    multiset<int> ans;
    multiset<pr>::iterator it;

    cin >> N >> M >> K >> Q;

    vector<tp> edges;
    while (M--) {
        cin >> A >> B >> L;
        edges.push_back({L, A, B});
    }

    sort(edges.begin(), edges.end());
    for (int i = 1; i <= N; i++)
        uf[i] = i;
    for (tp i : edges) {
        if (find(i[1]) == find(i[2]))
            continue;
        merge(i[1], i[2]);
        adj[i[1]].push_back({i[2], i[0]}), adj[i[2]].push_back({i[1], i[0]});
    }

    for (int i = 1; i <= N; i++)
        cin >> V[i];

    dfs(1, 0);

    for (int i = 1; i <= N; i++) {
        it = T[i].begin();
        while (it != T[i].end()) {
            if ((*it)[0] != V[i])
                S[i].insert({(*it)[1], (*it)[0]});
            it = T[i].lower_bound({(*it)[0] + 1, 0});
        }
        if (!S[i].empty())
            ans.insert((*S[i].begin())[0]);
    }

    while (Q--) {
        cin >> A >> B, P = parent[A];

        if (!T[A].empty()) {
            if (!S[A].empty())
                ans.erase(ans.find((*S[A].begin())[0]));

            it = T[A].lower_bound({B, 0});
            if (it != T[A].end() && (*it)[0] == B)
                S[A].erase(S[A].find({(*it)[1], B}));

            it = T[A].lower_bound({V[A], 0});
            if (it != T[A].end() && (*it)[0] == V[A])
                S[A].insert({(*it)[1], V[A]});

            if (!S[A].empty())
                ans.insert((*S[A].begin())[0]);
        }

        if (P) {
            if (!S[P].empty())
                ans.erase(ans.find((*S[P].begin())[0]));

            it = T[P].lower_bound({V[A], 0});
            if (it != T[P].end() && (*it)[0] == V[A] && (*it)[1] == D[A] && V[P] != V[A]) {
                S[P].erase(S[P].find({D[A], V[A]}));
                it = next(T[P].lower_bound({V[A], 0}));
                if (it != T[P].end() && (*it)[0] == V[A])
                    S[P].insert({(*it)[1], V[A]});
            }
            T[P].erase(T[P].find({V[A], D[A]}));

            it = T[P].lower_bound({B, 0});
            if (it != T[P].end() && (*it)[0] == B && V[P] != B)
                S[P].erase(S[P].find({(*it)[1], B}));

            T[P].insert({B, D[A]});
            it = T[P].lower_bound({B, 0});
            if (V[P] != B)
                S[P].insert({(*it)[1], B});

            if (!S[P].empty())
                ans.insert((*S[P].begin())[0]);
        }

        V[A] = B;
        cout << (*ans.begin()) << '\n';
    }

    return 0;
}