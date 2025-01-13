#include "evolution.h"

#include <bits/stdc++.h>

#define MAX 500100

using namespace std;

int dp[MAX][2], X = 1, parent[MAX];
vector<int> child[MAX];
multiset<int> dpst[MAX][2];

void dfs(int node) {
    multiset<int>::iterator it;
    int X = dp[node][0], Y = dp[node][1];

    if (parent[node]) {
        dpst[parent[node]][0].erase(dpst[parent[node]][0].find(X));
        dpst[parent[node]][1].erase(dpst[parent[node]][1].find(Y));
    }

    if (!dpst[node][0].empty())
        dp[node][0] = *dpst[node][0].rbegin();
    if (dpst[node][1].size() == 1) {
        dp[node][1] = *dpst[node][1].rbegin();
        dp[node][0] = max(dp[node][0], dp[node][1]);
    } else if (dpst[node][1].size() > 1) {
        dp[node][1] = max(*dpst[node][1].rbegin(), *next(dpst[node][1].rbegin()) + 1);
        dp[node][0] = max(dp[node][0], *dpst[node][1].rbegin() + *next(dpst[node][1].rbegin()) + 1);
        if (dpst[node][1].size() > 2)
            dp[node][0] = max(dp[node][0], *next(dpst[node][1].rbegin()) + *next(next(dpst[node][1].rbegin())) + 2);
    }

    dpst[parent[node]][0].insert(dp[node][0]);
    dpst[parent[node]][1].insert(dp[node][1]);

    if (node != 1 && (dp[node][0] != X || dp[node][1] != Y))
        dfs(parent[node]);
}

void init() {}

void observation(int P) {
    child[P].push_back(++X), parent[X] = P;
    dpst[P][0].insert(0), dpst[P][1].insert(0);
    dfs(P);
}

int analyze(int R) { return dp[R][0]; }