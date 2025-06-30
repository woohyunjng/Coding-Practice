#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;
const int MAX_LOG = 20;

vector<int> adj[MAX];
int N, R, M, parent[MAX][MAX_LOG], ans[MAX], S[MAX], D[MAX], V[MAX][2];

void dfs(int node) {
    S[node] = 1;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        D[i] = D[node] + 1, dfs(i);
        S[node] += S[i];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> R >> M;

    for (int i = 2; i <= N; i++)
        cin >> parent[i][0], adj[parent[i][0]].push_back(i);
    dfs(1);

    int X, A = (M + 1) / 2, B = R + 1 - A;

    for (int i = 1; i <= N; i++) {
        if (D[i] >= R + 1) {
            X = i;
            for (int j = 0; j < MAX_LOG; j++)
                if ((R + 1) & (1 << j))
                    X = parent[X][j];
            ans[X] += S[i] * (S[i] - 1) / 2;
            if (M >= R + 1)
                ans[X] += (N - S[X]) * S[i];
        }

        if (D[i] >= A) {
            X = i;
            for (int j = 0; j < MAX_LOG; j++)
                if (A & (1 << j))
                    X = parent[X][j];
            V[X][0] += S[i], V[X][1] += S[i] * S[i];
        }

        ans[i] += (N - S[i]) * (N - S[i] - 1) / 2;
    }

    for (int i = 1; i <= N; i++) {
        A = V[i][0] * V[i][0] - V[i][1], A /= 2, X = i;
        for (int j = 0; j < MAX_LOG; j++)
            if (B & (1 << j))
                X = parent[X][j];
        ans[X] += A;
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';

    return 0;
}