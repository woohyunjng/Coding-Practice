#include <bits/stdc++.h>
#define int long long

#define MAX 11000000
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

    int L, R, res = 0;
    string S, P;

    cin >> L >> R;
    cin >> P;

    linear_sieve(MAX);

    for (int i = L - 1; i < R; i++) {
        S = to_string(primes[i]);
        if (S.find(P) != string::npos)
            res++;
    }

    cout << res;

    return 0;
}