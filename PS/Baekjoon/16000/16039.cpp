#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 110;
const int MAX_K = 100100;

vector<int> adj[MAX];
pr dq[MAX_K];
int K, H[MAX], S[MAX], L[MAX], dp[MAX_K], dq_L, dq_R;

void dfs(int node) {
    int X, Y, Z, V;

    adj[node].push_back(0);
    sort(adj[node].begin(), adj[node].end(), [&](int x, int y) { return L[x] < L[y]; });

    vector<int> tmp(K + 1, 0);

    for (int i = 0; i < adj[node].size(); i++) {
        X = adj[node][i], Y = 0, Z = (i + 1 == (int)adj[node].size()) ? H[node] : L[adj[node][i + 1]] - 1;
        if (X != 0)
            dfs(X);
        dq_L = dq_R = 0;
        if (L[X] > Z)
            continue;
        for (int j = L[X]; j <= K; j++) {
            for (; Y <= j - L[X]; Y++) {
                V = dp[Y] - S[node] * Y;
                while (dq_L < dq_R && dq[dq_R - 1][1] < V)
                    dq_R--;
                dq[dq_R++] = {Y, V};
            }
            while (dq[dq_L][0] < j - Z)
                dq_L++;
            tmp[j] = max(tmp[j], dq[dq_L][1] + S[node] * j);
        }
    }

    for (int i = 0; i <= K; i++)
        dp[i] = tmp[i];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;

    while (true) {
        cin >> N >> K;
        if (N == 0)
            break;

        for (int i = 1; i <= N; i++)
            cin >> H[i];
        for (int i = 1; i <= N; i++)
            cin >> S[i];
        for (int i = 2; i <= N; i++)
            cin >> X, adj[X].push_back(i);
        for (int i = 2; i <= N; i++)
            cin >> L[i];

        dfs(1);
        cout << dp[K] << '\n';

        for (int i = 1; i <= N; i++)
            adj[i].clear();
        for (int i = 0; i <= K; i++)
            dp[i] = 0;
    }

    return 0;
}