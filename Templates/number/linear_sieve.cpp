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