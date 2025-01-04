#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, res = 0;
    cin >> X;

    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            if (i * j != X)
                res += i * j;

    cout << res << '\n';

    return 0;
}