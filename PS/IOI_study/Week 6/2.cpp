#include <bits/stdc++.h>
#define int long long
#define MAX 1000

using namespace std;

vector<bool> get_primes(int N) {
    vector<bool> primes(N + 1);
    fill(primes.begin(), primes.end(), true);
    primes[0] = false, primes[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (!primes[i])
            continue;
        for (int j = i * 2; j <= N; j += i)
            primes[j] = false;
    }

    return primes;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q, A, B;
    vector<bool> primes = get_primes(MAX);

    int sm[MAX + 1];
    sm[0] = 0;

    for (int i = 1; i <= MAX; i++) {
        sm[i] = sm[i - 1];
        if (primes[i])
            sm[i]++;
    }

    cin >> Q;
    while (Q--) {
        cin >> A >> B;
        cout << sm[B] - sm[A - 1] << '\n';
    }

    return 0;
}