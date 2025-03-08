#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 3> tp;

const int MAX = 300000;
const int MAX_LOG = 32;

vector<tp> adj[MAX];
int A[MAX], depth[MAX], cnt[MAX_LOG], sz;
bool ans = true, chk[MAX];

void dfs(int node, int par) {
    depth[node] = depth[par] + 1, sz++;
    for (int i = 0; i < MAX_LOG; i++)
        if (A[node] >> i & 1)
            cnt[i]++;

    for (tp i : adj[node]) {
        if (i[2] == par)
            continue;
        else if (depth[i[0]] == 0)
            A[i[0]] = A[node] ^ i[1], dfs(i[0], i[2]);
        else {
            if ((A[node] ^ A[i[0]]) != i[1])
                ans = false;
        }
    }
}

void xor_graph(int node, int val) {
    chk[node] = true, A[node] ^= val;
    for (tp i : adj[node]) {
        if (chk[i[0]])
            continue;
        xor_graph(i[0], val);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z;

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z, i}), adj[Y].push_back({X, Z, i});
    }

    for (int i = 1; i <= N; i++) {
        if (depth[i])
            continue;
        fill(cnt, cnt + MAX_LOG, 0), sz = X = 0, dfs(i, 0);
        for (int j = 0; j < MAX_LOG; j++)
            if (cnt[j] * 2 > sz)
                X |= 1 << j;
        xor_graph(i, X);
    }

    if (!ans)
        cout << -1 << '\n';
    else {
        for (int i = 1; i <= N; i++)
            cout << A[i] << ' ';
        cout << '\n';
    }

    return 0;
}