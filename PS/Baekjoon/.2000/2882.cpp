#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX_NUM = 8000000;

int N, K, min_prime_factor[MAX_NUM + 1];
vector<int> primes;

int get(int X) {
    for (int i = K - 1; i >= 0; i--) {
        if (X == primes[i] % N)
            X = 0;
        else {
            X = (X + primes[i] / (N - 1)) % N;
            if (X <= primes[i] % (N - 1))
                X++;
        }
    }
    return X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A;

    cin >> N >> K >> A, A--;

    for (int i = 2; i < MAX_NUM; i++) {
        if (min_prime_factor[i] == 0)
            min_prime_factor[i] = i, primes.push_back(i);
        for (int j : primes) {
            if (i * j > MAX_NUM)
                break;
            min_prime_factor[i * j] = j;
            if (i % j == 0)
                break;
        }
    }

    for (int i = 0; i < K; i++) {
        if (A == 0)
            A = (A + primes[i]) % N;
        else if (A <= primes[i] % (N - 1))
            A = (A + N * MAX_NUM - primes[i] / (N - 1) - 1) % N;
        else
            A = (A + N * MAX_NUM - primes[i] / (N - 1)) % N;
    }

    cout << get((A + 1) % N) + 1 << ' ' << get((A - 1 + N) % N) + 1 << '\n';

    return 0;
}