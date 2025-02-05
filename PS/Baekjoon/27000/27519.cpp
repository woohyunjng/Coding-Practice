#include <bits/stdc++.h>
#define int long long

#define MAX 100005
#define MOD 1000000007

using namespace std;

int A[MAX], val[MAX], min_prime_factor[MAX], dp[MAX];
vector<int> primes;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, P;
    cin >> T;

    for (int i = 2; i < MAX; i++) {
        if (min_prime_factor[i] == 0) {
            min_prime_factor[i] = i;
            primes.push_back(i);
        }

        for (int p : primes) {
            if (i * p >= MAX)
                break;
            min_prime_factor[i * p] = p;
            if (i % p == 0)
                break;
        }
    }
    P = primes.size();

    dp[0] = 1;
    for (int i = 0; i < P; i++) {
        for (int j = primes[i]; j < MAX; j++) {
            if (j >= primes[i])
                dp[j] = (dp[j] + dp[j - primes[i]]) % MOD;
        }
    }

    while (T--) {
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}