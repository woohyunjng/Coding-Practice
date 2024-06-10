#include <bits/stdc++.h>
#define MAX 1000001
#define MOD 1000000007
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int fac[1001000];

int pow_(int N, int K)
{
    int res = 1;
    while (K)
    {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1;
        N = N * N % MOD;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fac[0] = 1;
    for (int i = 1; i <= MAX; i++)
        fac[i] = fac[i - 1] * i % MOD;

    int N, K;
    cin >> N >> K;
    cout << fac[N] * pow_(fac[N - K] * fac[K] % MOD, MOD - 2) % MOD << '\n';

    return 0;
}