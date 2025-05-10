#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 16;

int dp[MAX];
vector<int> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    int N, K, X, Y, Z, ans = 0;

    cin >> S, N = S.size(), K = X = 0;
    for (char i : S)
        K += i == 'S', X = X * 2 + (i == 'S');

    queue<int> q;
    q.push(X), dp[X] = 1;

    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N - 1; j++) {
            X = (((i & (1 << j)) >> j) ^ 1) | ((((i & (1 << (j + 1))) >> (j + 1)) ^ 1) << 1);
            Y = i & ((1 << j) - 1), Z = i & ((1 << N) - (1 << (j + 2)));

            adj[i].push_back((Y << 2) | X | Z), adj[i].push_back(Y | (Z >> 2) | (X << (N - 2)));
        }
    }

    while (!q.empty()) {
        X = q.front(), q.pop();
        for (int i : adj[X])
            if (!dp[i])
                dp[i] = dp[X] + 1, q.push(i);
    }

    cout << dp[0] - 1 << '\n';

    return 0;
}