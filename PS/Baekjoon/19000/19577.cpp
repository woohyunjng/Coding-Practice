#include <bits/stdc++.h>
#define int long long

using namespace std;

int euler_phi(int N)
{
    int res = N;
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i)
            continue;
        while (!(N % i))
            N /= i;
        res /= i;
        res *= i - 1;
    }

    if (N != 1)
    {
        res /= N;
        res *= N - 1;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, res = -1;

    cin >> N;

    for (int i = 1; i * i <= N; i++)
    {
        if (i * euler_phi(i) == N)
        {
            res = i;
            break;
        }
        else if ((N / i) * euler_phi(N / i) == N)
        {
            res = N / i;
            break;
        }
    }
    cout << res;

    return 0;
}