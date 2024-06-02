#include <bits/stdc++.h>
#define int long long

using namespace std;

int combination[30][30];

int comb(int N, int K)
{
    if (N == 0 || N == 1 || N == K || K == 0)
        return combination[N][K] = 1;

    if (combination[N][K])
        return combination[N][K];
    return combination[N][K] = comb(N - 1, K - 1) + comb(N - 1, K);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << comb(i, j) << ' ';
        }
        cout << '\n';
    }

    return 0;
}