#include <iostream>
#define int long long
using namespace std;

signed main()
{
    int a, r, n, mod, bef = 1, res = 0;
    cin >> a >> r >> n >> mod;

    while (n)
    {
        if (n & 1)
            res = (((res * bef) % mod) * (r - 1) + res + bef) % mod;
        bef = (bef * bef % mod) * (r - 1) % mod + 2 * bef % mod;
        n >>= 1;
    }

    res = a * res % mod;
    cout << res;
}