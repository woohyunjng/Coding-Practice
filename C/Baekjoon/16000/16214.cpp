#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

typedef long long ll;

ll pow(ll A, ll B, ll MOD)
{
    if (!B)
        return 1;
    if (B % 2)
        return (pow(A, B - 1, MOD) * A) % MOD;

    ll half = pow(A, (ll)(B / 2), MOD);
    return (half * half) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        ll N, M, K;
        cin >> N >> M;
        K = M;

        stack<ll> arr;

        while (N % K)
        {
            arr.push(K);
            ll val = K;

            for (ll i = 2; i <= (ll)sqrt(K) + 1; i++)
            {
                if (K % i)
                    continue;

                val = (ll)(val * (i - 1) / i);
                while (!(K % i))
                    K /= i;
            }

            if (K > 1)
                val = (ll)(val * (K - 1) / K);
            K = val;
        }

        ll res = 1, i = 0;
        while (arr.size() > 1)
        {
            i = arr.top();
            arr.pop();
            res = pow(N % i, res, i) + i;
        }
        cout << pow(N, res, M) << '\n';
    }
}