#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 100001;

vector<int> adj[MAX];
int A[MAX], S[MAX], dp[MAX], ans = MAX;

void dfs(int node, int par) {
    int R = 0;
    S[node] = A[node];
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), S[node] += S[i], R += dp[i];
    }
    dp[node] = R == 0 ? (S[node] > 0) : R;
}

void rrt(int node, int par, int val) {
    int R = val;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        R += dp[i];
    }
    for (int i : adj[node]) {
        if (i == par)
            continue;
        R -= dp[i], rrt(i, node, R == 0 ? (-S[i] > 0) : R), R += dp[i];
    }
    ans = min(ans, R);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    if (accumulate(A + 1, A + N + 1, 0ll) != 0) {
        cout << -1 << '\n';
        return 0;
    } else if (*max_element(A + 1, A + N + 1) == 0) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    dfs(1, 0), rrt(1, 0, 0), cout << ans + 1 << '\n';

    return 0;
}