#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 400001;
const int MOD = 998244353;

int A[MAX], parity[MAX], depth[MAX], parent[MAX], uf[MAX], S[MAX];
bool vst[MAX];
vector<int> adj[MAX], arr[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    else if (depth[X] > depth[Y])
        swap(X, Y);
    uf[Y] = X, parity[X] |= parity[Y];
}

void dfs(int node, int par) {
    int X;

    vst[node] = true, parent[node] = par;
    for (int i : adj[node]) {
        if (i == par)
            continue;

        if (!vst[i])
            depth[i] = depth[node] + 1, dfs(i, node);
        else if (depth[i] < depth[node]) {
            X = node, parity[find(i)] |= (depth[node] - depth[i]) % 2 == 0;
            while (find(X) != find(i))
                uni(X, parent[X]), X = find(X);
        }
    }
}

void solve() {
    int N, M, V, X, Y, ans = 1;
    set<int> st;

    cin >> N >> M >> V, V %= MOD;
    for (int i = 1; i <= N; i++)
        cin >> A[i], uf[i] = i;

    for (int i = 1; i <= M; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs(1, 0);

    for (int i = 1; i <= N; i++) {
        S[find(i)] += A[i] == -1;
        arr[find(i)].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        if (find(i) != i)
            continue;

        if (parity[i]) {
            for (int j : arr[i])
                if (A[j] != -1 && A[j] != 0)
                    ans = 0;
        } else {
            st.clear();
            for (int j : arr[i])
                if (A[j] != -1)
                    st.insert(A[j]);

            if (st.empty() && S[i] != 0)
                ans = ans * V % MOD;
            else if (st.size() > 1)
                ans = 0;
        }
    }

    cout << ans << '\n';

    for (int i = 1; i <= N; i++) {
        parity[i] = depth[i] = parent[i] = S[i] = 0;
        vst[i] = false, uf[i] = i;
        arr[i].clear(), adj[i].clear();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}