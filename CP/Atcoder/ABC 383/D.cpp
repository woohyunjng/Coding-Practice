#include <bits/stdc++.h>
#define int long long

#define MAX 2000100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int min_prime_factor[MAX + 1];
vector<int> primes, primes_sq;

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
    cin.tie(0), cout.tie(0);

    linear_sieve(MAX);

    int N, res = 0, X;
    cin >> N;

    for (int i : primes) {
        X = i * i * i * i * i * i * i * i;
        if (X > N)
            break;
        res++;
    }
    for (int i : primes)
        primes_sq.push_back(i * i);

    for (int i = 0; i < primes.size(); i++) {
        if (primes_sq[i] * primes_sq[i] > N)
            break;
        X = lower_bound(primes_sq.begin(), primes_sq.end(), N / primes_sq[i]) - primes_sq.begin();
        if (primes_sq[X] > N / primes_sq[i])
            X--;
        res += max(0ll, X - i);
    }

    cout << res << '\n';

    return 0;
}