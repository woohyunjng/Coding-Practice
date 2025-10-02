#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int min_prime_factor[MAX];
vector<int> primes;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    for (int i = 2; i < MAX; i++) {
        if (min_prime_factor[i] == 0)
            min_prime_factor[i] = i, primes.push_back(i);

        for (int p : primes) {
            if (i * p >= MAX)
                break;
            min_prime_factor[i * p] = p;
            if (i % p == 0)
                break;
        }
    }

    int N, A, B;

    cin >> N;
    while (N--) {
        cin >> A >> B;
        A = lower_bound(primes.begin(), primes.end(), A) - primes.begin();
        B = upper_bound(primes.begin(), primes.end(), B) - primes.begin() - 1;

        if (A > B || (B - A + 1) % 2 == 0)
            cout << -1 << '\n';
        else
            cout << primes[(A + B) / 2] << '\n';
    }

    return 0;
}