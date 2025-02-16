#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 300000;
const int MOD = 1000000007;

vector<pr> adj[MAX];
priority_queue<pr, vector<pr>, greater<pr>> pq;

int N, ans = 0, sz[MAX];
bool vst[MAX];

int get_size(int node, int par) {
    sz[node] = 1;
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        sz[node] += get_size(i[0], node);
    }
    return sz[node];
}

int get_cent(int node, int par, int cap) {
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        if (sz[i[0]] * 2 > cap)
            return get_cent(i[0], node, cap);
    }
    return node;
}

void dfs(int node, int par, int mx, int sm) {
    pq.push({mx, sm});
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        dfs(i[0], node, max(mx, i[1]), (sm + i[1]) % MOD);
    }
}

void dnc(int node) {
    int cent = get_cent(node, -1, get_size(node, -1));
    vst[cent] = true;

    for (pr i : adj[cent]) {
        if (vst[i[0]])
            continue;
        dfs(i[0], cent, i[1], i[1]);
    }

    pr K;
    int sm[2] = {0, 0};

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        ans += K[0] * (sm[1] * K[1] % MOD + sm[0]) % MOD, ans %= MOD;
        ans += K[0] * K[1] % MOD, ans %= MOD;
        sm[0] = (sm[0] + K[1]) % MOD, sm[1]++;
    }

    for (pr i : adj[cent]) {
        if (vst[i[0]])
            continue;
        dfs(i[0], cent, i[1], i[1]);
        sm[0] = sm[1] = 0;

        while (!pq.empty()) {
            K = pq.top(), pq.pop();
            ans -= K[0] * (sm[1] * K[1] % MOD + sm[0]) % MOD, ans = (ans + MOD) % MOD;
            sm[0] = (sm[0] + K[1]) % MOD, sm[1]++;
        }
    }

    for (pr i : adj[cent]) {
        if (vst[i[0]])
            continue;
        dnc(i[0]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, Y, Z;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z}), adj[Y].push_back({X, Z});
    }

    dnc(1);
    cout << ans << '\n';

    return 0;
}