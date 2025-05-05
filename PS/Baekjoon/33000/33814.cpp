#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;
const int MOD = 99'999'989;

int V[MAX], S[MAX], P[MAX], dp[MAX][2], cnt, ans;
vector<int> adj[MAX];
vector<pr> go[MAX];

int dnc(int l, int r, int v) {
    int X = ++cnt, Y, Z, K, G = S[r - 1] - S[l - 1] + v;

    for (int i = l; i < r; i++) {
        if (go[i].empty())
            continue;
        Y = go[i].back()[0], Z = go[i].back()[1], go[i].pop_back();
        K = dnc(i, Y, Z), G += Z - (S[Y - 1] - S[i - 1]), i = Y - 1;
        adj[K].push_back(X), adj[X].push_back(K);
    }
    P[X] = G & 1;

    return X;
}

void dfs(int node, int par) {
    int X, Y;

    dp[node][P[node]]++;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), X = dp[node][0], Y = dp[node][1];
        dp[node][0] = (X * dp[i][0] + Y * dp[i][1]) % MOD;
        dp[node][1] = (X * dp[i][1] + Y * dp[i][0]) % MOD;
    }
    ans = (ans + dp[node][0] + MOD) % MOD, dp[node][0] = (dp[node][0] + 1) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, Y;
    string s;
    char C;

    cin >> N >> s;
    for (int i = 1; i <= N; i++)
        V[i] = s[i - 1] == '-', S[i] = S[i - 1] + V[i];

    cin >> K;
    while (K--) {
        cin >> X >> Y >> C;
        if (X > Y)
            swap(X, Y);
        go[X].push_back({Y, C == '-'});
    }

    for (int i = 1; i <= N; i++)
        sort(go[i].begin(), go[i].end());

    dnc(1, N, V[N]), dfs(1, 0);
    cout << ans << '\n';

    return 0;
}