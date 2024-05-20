#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, X, Y, K, gcd, lcm;
    cin >> A >> B;
    X = A, Y = B;

    while (X)
    {
        K = X;
        X = Y % X;
        Y = K;
    }

    gcd = Y;
    lcm = A * B / gcd;

    cout << gcd << ' ' << lcm;

    return 0;
}