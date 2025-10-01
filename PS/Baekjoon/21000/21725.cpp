#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 3> tp;

const int MAX = 200001;

vector<int> adj[MAX];
int S[MAX], C[MAX], uf[MAX], sz[MAX];

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }

void dfs(int node) {
    for (int i : adj[node])
        S[i] += S[node], dfs(i);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, Y, Z;
    vector<tp> ans;

    cin >> N >> M, K = N;
    for (int i = 1; i <= N; i++)
        uf[i] = i, sz[i] = 1;

    while (M--) {
        cin >> X >> Y >> Z;
        if (X == 1) {
            K++, adj[K].push_back(find(Y)), adj[K].push_back(find(Z));
            sz[K] = sz[find(Y)] + sz[find(Z)];
            uf[find(Y)] = uf[find(Z)] = uf[K] = K;
        } else
            C[Y] -= Z, S[find(Y)] += Z / sz[find(Y)];
    }

    dfs(K), M = 0;

    for (int i = 1; i <= N; i++) {
        S[i] += C[i];
        if (S[i] > 0) {
            if (M == 0)
                M = i;
            else
                ans.push_back({i, M, S[i]}), S[M] += S[i], S[i] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (S[i] >= 0)
            continue;
        ans.push_back({M, i, -S[i]}), S[M] += S[i], S[i] = 0;
    }

    cout << ans.size() << '\n';
    for (tp i : ans)
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';

    return 0;
}