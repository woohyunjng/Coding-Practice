#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;
typedef priority_queue<pr, vector<pr>, greater<pr>> pr_pq;

const int MAX = 400000;

vector<int> adj[MAX];
int X[MAX];

pr_pq dfs(int node) {
    pr_pq pq, tmp;
    pr K, R;

    for (int i : adj[node]) {
        tmp = dfs(i);
        if (tmp.size() > pq.size())
            swap(tmp, pq);
        while (!tmp.empty())
            K = tmp.top(), tmp.pop(), pq.push(K);
    }

    if (X[node] >= 0)
        R = {0, X[node]};
    else {
        R = {-X[node], X[node]};
        while (!pq.empty() && R[1] <= 0)
            K = pq.top(), pq.pop(), R[0] = max(R[0], K[0] - R[1]), R[1] += K[1];
    }
    while (!pq.empty() && pq.top()[0] <= R[0] + R[1])
        K = pq.top(), pq.pop(), R[1] += K[1];
    if (R[1] > 0)
        pq.push(R);

    return pq;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, P, ans = 0;
    pr K;

    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> P;
        adj[P].push_back(i);
    }

    X[0] = S;

    pr_pq res = dfs(0);
    ans = res.top()[1];

    cout << ans - S << '\n';

    return 0;
}