#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 400000;
const int MOD = 1000000007;

vector<int> adj[2][MAX];
int in[2][MAX], F[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, P, X, Y, ans[2] = {0};
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N >> K >> P;

    F[0] = 1;
    for (int i = 1; i <= K; i++)
        F[i] = F[i - 1] * N % MOD;

    while (P--) {
        cin >> X >> Y;
        adj[0][Y].push_back(X), adj[1][X].push_back(Y);
        in[0][X]++, in[1][Y]++;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < K; j++)
            if (!in[i][j])
                pq.push(j);

        Y = 0, P = i ? N - 1 : K - 1;
        while (!pq.empty()) {
            X = pq.top(), pq.pop(), X = abs(X);
            P = i ? K - 1 - (Y++) : (N - K) + (Y++), ans[i] = (ans[i] + P * F[X]) % MOD;

            for (int j : adj[i][X])
                if (!--in[i][j])
                    pq.push(j);
        }
    }

    cout << (ans[0] - ans[1] + MOD) % MOD << '\n';

    return 0;
}