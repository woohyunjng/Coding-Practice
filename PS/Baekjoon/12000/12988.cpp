#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int P[MAX][MAX], assign[MAX];
bool chk[MAX];
vector<int> adj[MAX];

bool dfs(int node) {
    for (int i : adj[node]) {
        if (chk[i])
            continue;
        chk[i] = true;
        if (assign[i] == -1 || dfs(assign[i])) {
            assign[i] = node;
            return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, ans = 0;
    bool flag;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> K, fill(assign, assign + N + 1, -1), ans = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= K; j++)
                cin >> P[i][j];

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) {
                flag = true;
                for (int k = 1; k <= K; k++)
                    flag &= P[i][k] < P[j][k];
                if (flag)
                    adj[i].push_back(j);
            }

        for (int i = 1; i <= N; i++) {
            fill(chk, chk + MAX, false);
            if (dfs(i))
                ans++;
        }

        cout << N - ans << '\n';
        for (int i = 1; i <= N; i++)
            adj[i].clear();
    }

    return 0;
}