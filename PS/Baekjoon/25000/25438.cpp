#include "fish.h"

#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 600001;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<pr> V[MAX], dp[MAX][2];
vector<int> D[MAX];
int last[MAX], full[MAX];

int max_weights(signed N, signed M, vector<signed> XC, vector<signed> YC, vector<signed> W) {
    int ans = 0, K, S, Z, MX;
    vector<pr> tmp;

    for (int i = 0; i < M; i++) {
        V[XC[i] + 1].push_back({YC[i] + 1, W[i]});
        V[XC[i] + 2].push_back({YC[i] + 1, 0});
    }

    dp[0][0].push_back({N, 0}), dp[0][1].push_back({0, 0});
    for (int i = 1; i <= N; i++) {
        sort(V[i].begin(), V[i].end()), tmp.clear();
        for (pr j : V[i]) {
            if (!tmp.empty() && tmp.back()[0] == j[0])
                tmp.back()[1] += j[1];
            else
                tmp.push_back(j);
        }
        V[i] = tmp;

        K = S = 0, MX = last[i - 1];
        for (pr j : V[i]) {
            while (K < dp[i - 1][0].size() && dp[i - 1][0][K][0] <= j[0])
                MX = max(MX, dp[i - 1][0][K][1] - (S + (dp[i - 1][0][K][0] == j[0] ? j[1] : 0))), K++;
            S += j[1], dp[i][0].push_back({j[0], MX + S});
        }
        while (K < dp[i - 1][0].size())
            MX = max(MX, dp[i - 1][0][K][1] - S), K++;
        dp[i][0].push_back({N + 1, MX + S});

        K = S = 0, MX = full[i - 1], reverse(V[i].begin(), V[i].end());
        for (pr j : V[i]) {
            while (K < dp[i - 1][1].size() && dp[i - 1][1][K][0] >= j[0])
                MX = max(MX, dp[i - 1][1][K][1] - (S + (dp[i - 1][1][K][0] == j[0] ? j[1] : 0))), K++;
            S += j[1], dp[i][1].push_back({j[0], MX + S});
        }
        while (K < dp[i - 1][1].size())
            MX = max(MX, dp[i - 1][1][K][1] - S), K++;
        dp[i][1].push_back({0, MX + S});

        if (i == 1)
            dp[i][1].clear(), dp[i][1].push_back({0, 0});
        if (i == N)
            dp[i][0].clear(), dp[i][0].push_back({N + 1, 0});

        full[i] = max(full[i - 1], dp[i - 1][0].back()[1]);
        last[i] = max({full[i], last[i - 1], dp[i][1].back()[1]});
    }

    ans = max({dp[N][0].back()[1], dp[N][1].back()[1], last[N], full[N]});
    return ans;
}