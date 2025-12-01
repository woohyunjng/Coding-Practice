#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 3> tp;

const int MAX = 1000001;

vector<int> adj[MAX];
int B[MAX];
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

    int N, K;
    tp P;

    cin >> N >> K;
    for (int i = 0; i < K; i++)
        for (int j = 0; j <= N; j++)
            cin >> B[i * (N + 1) + j];

    V[0] = {0, 0, 1};
    for (int i = 0; i < K; i++) {
        V[0][1] += B[i * (N + 1)];
        for (int j = 1; j <= N; j++) {
            V[i * (N + 1) + j] = {0, B[i * (N + 1) + j] - B[i * (N + 1) + j - 1], B[i * (N + 1) + j]};
            adj[j == 1 ? 0 : i * (N + 1) + j - 1].push_back(i * (N + 1) + j);
        }
    }

    pq res = dfs(0, -1);
    P = res.top(), res.pop();
    while (!res.empty())
        P = merge(P, res.top()), res.pop();

    for (int i = 0; i < K; i++)
        for (int j = 1; j <= N; j++)
            P[0] -= B[i * (N + 1) + j - 1] * B[i * (N + 1) + j];

    cout << P[0] << '\n';

    return 0;
}