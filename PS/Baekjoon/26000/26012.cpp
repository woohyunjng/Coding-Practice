#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 20'000'001;
const int MAX = 1'001;

int min_prime_factor[MAX_NUM], G[MAX], assign[MAX];
bool chk[MAX];
vector<int> adj[MAX];

bool dfs(int node) {
    for (int i : adj[node]) {
        if (chk[i])
            continue;
        chk[i] = true;
        if (assign[i] == -1 || dfs(assign[i])) {
            assign[i] = node;
            return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans = 0, K[2];
    bool one_chk = false;
    vector<int> P[2], primes;

    for (int i = 2; i < MAX_NUM; i++) {
        if (min_prime_factor[i] == 0)
            min_prime_factor[i] = i, primes.push_back(i);

        for (int p : primes) {
            if (i * p >= MAX_NUM)
                break;
            min_prime_factor[i * p] = p;
            if (i % p == 0)
                break;
        }
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X;
        if (X == 1 && one_chk)
            continue;
        P[X & 1].push_back(X), one_chk |= X == 1;
    }

    K[0] = P[0].size(), K[1] = P[1].size();
    N = K[0] + K[1];

    for (int i = 0; i < K[0]; i++)
        for (int j = 0; j < K[1]; j++) {
            if (min_prime_factor[P[0][i] + P[1][j]] != P[0][i] + P[1][j])
                continue;
            adj[i].push_back(j);
        }

    fill(assign, assign + MAX, -1);
    for (int i = 0; i < K[0]; i++) {
        fill(chk, chk + MAX, false);
        ans += dfs(i);
    }

    cout << N - ans << '\n';

    return 0;
}