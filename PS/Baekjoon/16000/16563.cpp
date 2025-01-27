#include <bits/stdc++.h>
#define int long long
#define MAX 10000000

using namespace std;

int min_prime_factor[MAX + 1];
vector<int> primes;

void linear_sieve(int N) {
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
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N;

    linear_sieve(5000000);

    for (int i = 1; i <= N; i++) {
        cin >> K;
        while (K > 1) {
            cout << min_prime_factor[K] << ' ';
            K /= min_prime_factor[K];
        }
        cout << '\n';
    }

    return 0;
}