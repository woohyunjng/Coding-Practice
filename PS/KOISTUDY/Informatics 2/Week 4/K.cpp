#include <bits/stdc++.h>
#define int long long

#define MAX 1500100
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

int euler_phi(int N) {
    int res = N, K;
    while (N > 1) {
        K = min_prime_factor[N];

        res /= K;
        res *= K - 1;

        while (N % K == 0)
            N /= K;
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, res = -1;
    double min_val = INF;
    string X, Y;

    cin >> N;

    linear_sieve(N);

    for (int i = 2; i <= N; i++) {
        K = euler_phi(i);
        X = to_string(K), Y = to_string(i);
        sort(X.begin(), X.end()), sort(Y.begin(), Y.end());

        if (X == Y) {
            if ((double)i / K < min_val) {
                cout << i << "ang\n";
                min_val = (double)i / K;
                res = i;
            }
        }
    }

    cout << res;

    return 0;
}