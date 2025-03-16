#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 300000;
const int MOD = 1000000007;

vector<pr> adj[MAX];
int N, sz[MAX], dp[MAX], ans;

int comb(int val) { return val * (val - 1) / 2 % MOD; }

set<pr> dfs(int node, int par) {
    set<pr> res, val;
    set<pr>::iterator iter;

    pr K;
    int X, Y;

    res.insert({node, node}), dp[node] = comb(node) + comb(N - 1 - node);

    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;

        val = dfs(i[0], node);
        ans = ((comb(N) - dp[i[0]] + MOD) % MOD * i[1] % MOD + ans) % MOD;

        if (res.size() < val.size())
            swap(res, val), swap(dp[node], dp[i[0]]);
        for (pr j : val) {
            K = j, iter = res.lower_bound(j);
            X = iter == res.begin() ? -1 : (*prev(iter))[1];
            Y = iter == res.end() ? N : (*iter)[0];

            dp[node] = (dp[node] - comb(Y - X - 1) + comb(K[0] - X - 1) + comb(K[1] - K[0] + 1) + comb(Y - K[1] - 1) + MOD) % MOD;

            iter = res.lower_bound(j);
            if (iter != res.begin() && (*prev(iter))[1] + 1 == K[0]) {
                X = (*prev(iter))[0], Y = (*prev(iter))[1];
                dp[node] = (dp[node] - comb(Y - X + 1) - comb(K[1] - K[0] + 1) + comb(K[1] - X + 1) + MOD) % MOD;
                K = {(*prev(iter))[0], K[1]}, res.erase(prev(iter));
            }
            iter = res.lower_bound(j);
            if (iter != res.end() && K[1] + 1 == (*iter)[0]) {
                X = (*iter)[0], Y = (*iter)[1];
                dp[node] = (dp[node] - comb(Y - X + 1) - comb(K[1] - K[0] + 1) + comb(Y - K[0] + 1) + MOD) % MOD;
                K = {K[0], (*iter)[1]}, res.erase(iter);
            }

            res.insert(K);
        }
        val.clear();
    }

    return res;
}

signed maintenance_costs_sum(vector<signed> U, vector<signed> V, vector<signed> W) {
    N = U.size() + 1;

    for (int i = 0; i < N - 1; i++) {
        adj[U[i]].push_back({V[i], W[i]});
        adj[V[i]].push_back({U[i], W[i]});
    }

    dfs(0, -1);

    return ans;
}