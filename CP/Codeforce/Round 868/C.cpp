#include <bits/stdc++.h>
#define int long long

#define MAX 10000010
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

    int T, N, A, B, res;
    cin >> T;

    set<int> prime_factors;
    map<int, int> prime_cnt;

    priority_queue<int> pq;

    linear_sieve(10000000);

    while (T--) {
        cin >> N;
        prime_factors.clear(), prime_cnt.clear();

        for (int i = 1; i <= N; i++) {
            cin >> A;
            while (A > 1) {
                if (prime_factors.find(min_prime_factor[A]) == prime_factors.end())
                    prime_factors.insert(min_prime_factor[A]);
                prime_cnt[min_prime_factor[A]]++;
                A /= min_prime_factor[A];
            }
        }

        for (int p : prime_factors)
            pq.push(prime_cnt[p]);

        res = 0;
        while (!pq.empty()) {
            A = pq.top(), pq.pop();

            if (A == 1) {
                res += (pq.size() + 1) / 3;
                break;
            }
            if (A > 2)
                pq.push(A - 2);
            res++;
        }

        while (!pq.empty())
            pq.pop();

        cout << res << '\n';
    }

    return 0;
}