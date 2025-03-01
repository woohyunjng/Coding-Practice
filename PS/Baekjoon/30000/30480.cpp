#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 3> tp;

const int MAX = 400000;

vector<int> adj[MAX];

tp merge(tp A, tp B) { return {A[0] + B[0] + B[2] * A[1], A[1] + B[1], A[2] + B[2]}; }
struct comp {
    bool operator()(tp A, tp B) { return A[2] * B[1] <= B[2] * A[1]; }
};

typedef priority_queue<tp, vector<tp>, comp> pq;

pq dfs(int node, int par) {
    pq res, tmp;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        tmp = dfs(i, node);
        if (tmp.size() > res.size())
            swap(tmp, res);
        while (!tmp.empty())
            res.push(tmp.top()), tmp.pop();
    }

    tp cur = {-node, 1, -node};
    while (!res.empty() && (cur[2] * res.top()[1] <= res.top()[2] * cur[1]))
        cur = merge(cur, res.top()), res.pop();
    res.push(cur);

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, R, U, V;
    tp X, Y;
    cin >> N >> R;

    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    pq res = dfs(R, -1);
    X = res.top(), res.pop();
    while (!res.empty())
        X = merge(X, res.top()), res.pop();

    cout << -X[0] << '\n';

    return 0;
}