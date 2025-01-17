#include <bits/stdc++.h>
#define int long long

#define MAX 5100
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef array<int, 2> pr;

vector<pr> adj[MAX], rev[MAX];
int dis[MAX][2], sm[MAX], dp[MAX][MAX], val[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, B, S, R, X, Y, Z;
    pr K;

    cin >> N >> B >> S >> R;

    while (R--) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Z, Y}), rev[Y].push_back({Z, X});
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    fill(&dis[0][0], &dis[N + 1][2], INF), dis[B + 1][0] = dis[B + 1][1] = 0;

    pq.push({0, B + 1});
    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (dis[K[1]][0] < K[0])
            continue;
        for (pr i : rev[K[1]])
            if (dis[i[1]][0] > K[0] + i[0])
                dis[i[1]][0] = K[0] + i[0], pq.push({dis[i[1]][0], i[1]});
    }

    pq.push({0, B + 1});
    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (dis[K[1]][1] < K[0])
            continue;
        for (pr i : adj[K[1]])
            if (dis[i[1]][1] > K[0] + i[0])
                dis[i[1]][1] = K[0] + i[0], pq.push({dis[i[1]][1], i[1]});
    }
    for (int i = 1; i <= B; i++)
        val[i] = dis[i][0] + dis[i][1];
    sort(val + 1, val + B + 1);
    for (int i = 1; i <= B; i++)
        sm[i] = sm[i - 1] + val[i];

    for (int i = 1; i <= B; i++)
        dp[1][i] = sm[i] * (i - 1);

    for (int i = 2; i <= S; i++) {
        for (int j = i; j <= B; j++) {
            X = INF;
            for (int k = j; (j - k + 1) * i <= j && k >= i; k--)
                X = min(X, dp[i - 1][k - 1] + (sm[j] - sm[k - 1]) * (j - k));
            dp[i][j] = X;
        }
    }
    cout << dp[S][B] << '\n';

    return 0;
}