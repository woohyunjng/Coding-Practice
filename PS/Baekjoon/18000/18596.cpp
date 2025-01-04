#include <bits/stdc++.h>
#define int long long

#define MAX 100100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> adj[MAX];
int A[MAX], B[MAX];

struct Node {
    int sm, A, B;
    Node(int sm, int A, int B) : sm(sm), A(A), B(B) {}
    bool operator<(const Node &n) const {
        bool res;
        if (sm >= 0 && n.sm >= 0)
            res = A >= n.A;
        else if (sm < 0 && n.sm < 0)
            res = B >= n.B;
        else
            res = sm >= 0;
        return !res;
    }

    Node operator+(const Node &n) const {
        if (A <= A + B + n.A)
            return {sm + n.sm, A, B + n.A + n.B};
        else
            return {sm + n.sm, A + B + n.A, n.B};
    }
};

typedef priority_queue<Node> pq;

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

    Node cur = {-A[node] + B[node], -A[node], B[node]};
    while (!res.empty() && cur < res.top())
        cur = cur + res.top(), res.pop();
    res.push(cur);

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, U, V;
    Node X = {0, 0, 0};

    cin >> T;
    while (T--) {
        cin >> N;

        for (int i = 1; i <= N; i++)
            adj[i].clear();

        for (int i = 2; i <= N; i++)
            cin >> A[i] >> B[i];

        for (int i = 1; i < N; i++) {
            cin >> U >> V;
            adj[U].push_back(V), adj[V].push_back(U);
        }

        pq res = dfs(1, -1);
        X = res.top(), res.pop();
        while (!res.empty())
            X = X + res.top(), res.pop();
        cout << -X.A << '\n';
    }

    return 0;
}