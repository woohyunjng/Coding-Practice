#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

vector<bool> get_primes(int N)
{
    vector<bool> primes(N + 1);
    fill(primes.begin(), primes.end(), true);
    primes[0] = false, primes[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (!primes[i])
            continue;
        for (int j = i * 2; j <= N; j += i)
            primes[j] = false;
    }

    return primes;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<bool> primes = get_primes(N);
    vector<int> sum;
    sum.push_back(0);

    for (int i = 1; i <= N; i++)
    {
        if (primes[i])
            sum.push_back(sum.back() + i);
    }

    int i = 0, j = 1, res = 0;

    while (j < sum.size())
    {
        if (sum[j] - sum[i] > N)
            i++;
        else if (sum[j] - sum[i] < N)
            j++;
        else
        {
            res++;
            j++;
        }
    }

    cout << res;

    return 0;
}