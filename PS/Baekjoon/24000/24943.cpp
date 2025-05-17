#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

const int MAX = 200001;

vector<int> adj[MAX];
int C[MAX], CA[MAX], CB[MAX];
tp V[MAX];

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

    tp cur = V[node];
    while (!res.empty() && (cur[2] * res.top()[1] <= res.top()[2] * cur[1]))
        cur = merge(cur, res.top()), res.pop();
    res.push(cur);

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    tp X, Y;

    cin >> N >> M, N--, M--;

    cin >> CA[0];
    for (int i = 1; i <= N; i++) {
        cin >> CA[i], adj[i - 1].push_back(i);
        V[i] = {0, CA[i] - CA[i - 1], 1};
    }

    cin >> CB[0];
    for (int i = 1; i <= M; i++) {
        cin >> CB[i], adj[i == 1 ? 0 : i + N - 1].push_back(i + N);
        V[i + N] = {0, CB[i] - CB[i - 1], 1};
    }
    V[0] = {0, CA[0] + CB[0], 1};

    pq res = dfs(0, -1);
    X = res.top(), res.pop();
    while (!res.empty())
        X = merge(X, res.top()), res.pop();

    for (int i = 0; i < N; i++)
        X[0] -= CA[i];
    for (int i = 0; i < M; i++)
        X[0] -= CB[i];

    cout << X[0] << '\n';

    return 0;
}