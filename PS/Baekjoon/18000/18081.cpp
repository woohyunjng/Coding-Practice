#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;
const int MAX_H = 30;

int K, RT,
    P[MAX], L[MAX], R[MAX],
    dp[MAX][MAX_H], D[MAX],
    ans[MAX];

void update(int node) {
    dp[node][0] = (!ans[node] && !dp[L[node]][0] && !dp[R[node]][0]) ? 0 : MAX;
    dp[node][1] = min(dp[L[node]][0] + dp[R[node]][0] + 1, MAX);

    for (int i = D[node]; i >= 2; i--) {
        dp[node][i] = MAX;
        for (int l = min(i - 1, D[L[node]]); l >= i - 2; l--)
            for (int r = min(i - 1, D[R[node]]); r >= i - 2; r--) {
                if (l == i - 2 && r == i - 2)
                    continue;
                dp[node][i] = min(dp[node][i], dp[L[node]][l] + dp[R[node]][r] + 1);
            }
    }
}

void dfs(int node) {
    if (L[node] != 0)
        dfs(L[node]), D[node] = max(D[node], D[L[node]]);
    if (R[node] != 0)
        dfs(R[node]), D[node] = max(D[node], D[R[node]]);
    D[node]++, update(node);
}

void travel(int node, int x) {
    if (x < node)
        travel(L[node], x);
    else if (x > node)
        travel(R[node], x);
    update(node);
}

void solve(int node) {
    int V = MAX;
    ans[node] = 1, travel(RT, node);
    if ((*min_element(dp[RT], dp[RT] + D[RT] + 1)) <= K) {
        if (L[node] != 0)
            solve(L[node]);
        if (R[node] != 0)
            solve(R[node]);
    } else
        ans[node] = 0, travel(RT, node);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, V;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> P[i], P[i] = P[i] == -1 ? 0 : P[i];
        if (P[i] == 0)
            RT = i;
        if (P[i] != 0 && P[i] > i)
            L[P[i]] = i;
        else if (P[i] != 0 && P[i] < i)
            R[P[i]] = i;
    }

    for (int i = 0; i <= N; i++)
        for (int j = 0; j < MAX_H; j++)
            dp[i][j] = MAX;
    dp[0][0] = 0, dfs(RT), solve(RT);

    for (int i = 1; i <= N; i++)
        cout << ans[i];
    cout << '\n';

    return 0;
}