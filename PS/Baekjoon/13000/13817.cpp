#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

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
    cin.tie(0), cout.tie(0);

    int A, B, X, Y, K;

    linear_sieve(1000000);

    while (cin >> A >> B) {
        if (A == 0 && B == 0)
            break;

        X = 0, Y = 0;
        while (A != 1) {
            K = min_prime_factor[A];
            X += K, Y = K;
            while (A % K == 0)
                A /= K;
        }
        A = Y * 2 - X;

        X = 0, Y = 0;
        while (B != 1) {
            K = min_prime_factor[B];
            X += K, Y = K;
            while (B % K == 0)
                B /= K;
        }
        B = Y * 2 - X;

        cout << (A > B ? "a" : "b") << '\n';
    }

    return 0;
}