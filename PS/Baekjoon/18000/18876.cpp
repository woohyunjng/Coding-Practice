#include <bits/stdc++.h>
#define int long long

#define MAX 10100
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][2], min_prime_factor[MAX + 1];
vector<int> primes;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, MOD, X, res;
    cin >> N >> MOD;

    for (int i = 2; i <= N; i++) {
        if (min_prime_factor[i] == 0) {
            min_prime_factor[i] = i;
            primes.push_back(i);
        }

        for (int p : primes) {
            if (i * p > N)
                break;
            min_prime_factor[i * p] = p;
            if (i % p == 0)
                break;
        }
    }

    for (int i = 0; i <= N; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= primes.size(); i++) {
        for (int j = 0; j <= N; j++) {
            X = primes[i - 1];
            dp[j][i & 1] = dp[j][i & 1 ^ 1];
            while (X <= j)
                dp[j][i & 1] = (dp[j][i & 1] + dp[j - X][i & 1 ^ 1] * X) % MOD, X *= primes[i - 1];
            if (j == N)
                res = dp[j][i & 1];
        }
    }

    cout << res << '\n';

    return 0;
}