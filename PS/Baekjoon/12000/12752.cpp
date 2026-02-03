#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;
const int MAX_K = 5;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<pr> adj[MAX];
int dp[MAX][1 << MAX_K];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, M, U, V, W, ans = INF;
    vector<int> arr;

    cin >> N >> K >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j < (1 << K); j++)
            dp[i][j] = INF;

    for (int i = 0; i < K; i++) {
        cin >> V;
        dp[V][1 << i] = 0;
    }

    while (M--) {
        cin >> U >> V >> W;
        adj[U].push_back({V, W}), adj[V].push_back({U, W});
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr X;

    for (int i = 1; i < (1 << K); i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < (1 << K); k++) {
                if ((i & k) != k)
                    continue;
                for (pr l : adj[j])
                    dp[j][i] = min(dp[j][i], dp[j][k] + dp[l[0]][i ^ k] + l[1]);
            }
            pq.push({dp[j][i], j});
        }
        while (!pq.empty()) {
            X = pq.top(), pq.pop();
            if (X[0] != dp[X[1]][i])
                continue;
            for (pr l : adj[X[1]]) {
                if (X[0] + l[1] >= dp[l[0]][i])
                    continue;
                dp[l[0]][i] = X[0] + l[1], pq.push(pr{X[0] + l[1], l[0]});
            }
        }
    }

    for (int i = 1; i <= N; i++)
        ans = min(dp[i][(1 << K) - 1], ans);
    cout << ans << '\n';

    return 0;
}