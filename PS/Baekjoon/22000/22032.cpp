#include "monkey.h"
#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 500001;

vector<pr> arr[2][MAX], adj[MAX];
int dp[MAX], in[MAX];

int max_bananas(vector<signed> A, vector<signed> B,
                vector<pair<signed, signed>> _P) {
    int N = A.size(), M = _P.size(), S[2], X, ans = 0;
    vector<pr> P;

    for (int i = 0; i < M; i++) {
        P.push_back({_P[i].first - 1, _P[i].second - 1});
        for (int j = 0; j < 2; j++)
            arr[j][P[i][j]].push_back({P[i][j ^ 1], i});
    }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < N; j++)
            sort(arr[i][j].begin(), arr[i][j].end());

    for (int i = 0; i < M; i++)
        for (int j = 0; j < 2; j++) {
            X = lower_bound(arr[j][P[i][j]].begin(), arr[j][P[i][j]].end(), pr{P[i][j ^ 1] + 1, 0}) - arr[j][P[i][j]].begin();
            if (X == arr[j][P[i][j]].size())
                continue;
            X = arr[j][P[i][j]][X][1], in[X]++;
            adj[i].push_back({X, j == 0 ? B[P[X][1]] : A[P[X][0]]});
        }

    queue<int> q;
    for (int i = 0; i < M; i++)
        if (in[i] == 0)
            q.push(i);

    while (!q.empty()) {
        X = q.front(), q.pop();
        dp[X] = max(dp[X], (int)A[P[X][0]] + B[P[X][1]]);
        ans = max(ans, dp[X]);

        for (pr i : adj[X]) {
            dp[i[0]] = max(dp[i[0]], dp[X] + i[1]);
            if (!--in[i[0]])
                q.push(i[0]);
        }
    }

    return ans;
}
