#include <bits/stdc++.h>
#define int long long

#define MAX 400100
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

int A[MAX];

void solve() {
    int N, res = -1, X;
    bool flag = true;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];

        if (min_prime_factor[A[i]] == A[i]) {
            if (res == -1 || res == A[i])
                res = A[i];
            else
                flag = false;
        }
    }

    if (res == -1)
        res = 2;

    for (int i = 1; i <= N; i++) {
        if (min_prime_factor[A[i]] == A[i])
            continue;
        if (A[i] / min_prime_factor[A[i]] >= res)
            A[i] /= min_prime_factor[A[i]];
        else {
            X = A[i] / min_prime_factor[A[i]];
            A[i] = A[i] / X * (X - 1) / 2;
        }
        flag = flag && (A[i] >= res);
    }

    cout << (flag ? res : -1) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    linear_sieve(400000);

    while (T--)
        solve();

    return 0;
}