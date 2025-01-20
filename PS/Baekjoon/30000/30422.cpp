#include <bits/stdc++.h>
#define int long long

#define MAX (1 << 20)
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef array<int, 2> pr;

int A[MAX], up[MAX][2], down[MAX][2], cnt[MAX][3], depth[MAX];
vector<int> dis[MAX];
vector<pr> adj[MAX];

int get_num(int node, int par) {
    if (node == par)
        return 1;
    return (node & ((1 << (depth[node] - depth[par])) - 1)) | (1 << (depth[node] - depth[par]));
}

int bit_num(int X) {
    int res = 0;
    while (X)
        X >>= 1, res++;
    return res;
}

int get_base(int num, int par) {
    int X = bit_num(num) - 1;
    num &= (1 << X) - 1;
    return num | (par << X);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z, res = 0;
    cin >> N >> M;

    for (int i = 2; i <= (1 << N) - 1; i++) {
        cin >> A[i];
        adj[i].push_back({A[i], i >> 1});
    }

    while (M--) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Z, Y});
    }

    for (int i = (1 << N) - 1; i >= 1; i--) {
        depth[i] = bit_num(i) - 1;
        cnt[i][2] = (1 << (N - depth[i])) - 1;
        up[i >> 1][i & 1] = (up[i][0] + up[i][1] + A[i] * cnt[i][2]) % MOD;
        dis[i].resize(cnt[i][2] + 1, INF);
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    for (int i = 1; i <= (1 << N) - 1; i++) {
        pq.push({0, i}), dis[i][1] = 0;
        while (!pq.empty()) {
            K = pq.top(), pq.pop();
            if (dis[i][get_num(K[1], i)] < K[0])
                continue;

            for (pr j : adj[K[1]]) {
                if (depth[j[1]] >= depth[i] && j[0] + K[0] < dis[i][get_num(j[1], i)]) {
                    dis[i][get_num(j[1], i)] = j[0] + K[0];
                    pq.push({j[0] + K[0], j[1]});
                }
            }
        }

        for (int j = 2; j <= cnt[i][2]; j++) {
            X = get_base(j, i);
            if (i > 1)
                dis[i][j] = min(dis[i][j], dis[i >> 1][get_num(X, i >> 1)] + A[i]);
            Y = (X >> (depth[X] - depth[i] - 1)) & 1;
            if (dis[i][j] < INF)
                down[i][Y] = (down[i][Y] + dis[i][j]) % MOD, cnt[i][Y]++;
        }
    }

    for (int i = 1; i <= (1 << N) - 1; i++)
        res = (res + up[i][0] * (cnt[i][1] + 1) + up[i][1] * (cnt[i][0] + 1) + down[i][0] * (cnt[i << 1 | 1][2] + 1) + down[i][1] * (cnt[i << 1][2] + 1)) % MOD;
    cout << res << '\n';

    return 0;
}