#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;

int N, M, dp[MAX], V[MAX];
vector<int> adj[MAX];

priority_queue<int> dfs(int node) {
    priority_queue<int> pq, tmp;
    int X, Y;

    if (node > N)
        pq.push(0), pq.push(0);

    for (int i : adj[node]) {
        tmp = dfs(i), X++, dp[node] += dp[i] + V[i];
        if (tmp.size() > pq.size())
            swap(tmp, pq);
        while (!tmp.empty())
            pq.push(tmp.top()), tmp.pop();
    }

    for (int i = 0; i < adj[node].size(); i++)
        pq.pop();

    X = pq.top(), pq.pop(), Y = pq.top(), pq.pop();
    pq.push(X + V[node]), pq.push(Y + V[node]);

    return pq;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, Y, ans;
    priority_queue<int> pq;

    cin >> N >> M;

    for (int i = 2; i <= N + M; i++)
        cin >> X >> V[i], adj[X].push_back(i);

    pq = dfs(1), ans = dp[1];
    while (!pq.empty())
        ans -= pq.top(), pq.pop();
    cout << ans << '\n';

    return 0;
}