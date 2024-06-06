#include <bits/stdc++.h>
#define MAX_LONG_LONG 9223372036854775807
#define int long long

using namespace std;

int f[21][300000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, Q, n, x, k;
    cin >> M;

    for (int i = 1; i <= M; i++)
        cin >> f[0][i];

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= M; j++)
            f[i][j] = f[i - 1][f[i - 1][j]];
    }

    cin >> Q;
    while (Q--)
    {
        cin >> n >> x;
        k = 0;

        while (n)
        {
            if (n & 1)
                x = f[k][x];
            n >>= 1;
            k++;
        }

        cout << x << '\n';
    }

    return 0;
}