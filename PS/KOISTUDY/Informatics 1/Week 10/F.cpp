#include <bits/stdc++.h>
#define int long long

using namespace std;

int comb(int N, int K)
{
    if (N == 1 || N == K || K == 0)
        return 1;
    return comb(N - 1, K - 1) + comb(N - 1, K);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    cout << comb(N, K);

    return 0;
}