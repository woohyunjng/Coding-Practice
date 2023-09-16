#include <iostream>
#include <utility>
using namespace std;

typedef long long int lli;

bool check(pair<lli, lli> x, pair<lli, lli> y, pair<lli, lli> z)
{
    return (x.first - y.first + z.first) * y.first + (x.second - y.second + z.second) * y.second == x.first * z.first + x.second * z.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    lli N, x, y, res = 0;
    cin >> N;

    pair<lli, lli> P[N];
    for (lli i = 0; i < N; i++)
    {
        cin >> P[i].first >> P[i].second;
    }

    for (lli i = 0; i < N - 2; i++)
    {
        for (lli j = i + 1; j < N - 1; j++)
        {
            for (lli k = j + 1; k < N; k++)
            {
                if (check(P[i], P[j], P[k]) || check(P[j], P[k], P[i]) || check(P[k], P[i], P[j]))
                    res++;
            }
        }
    }

    cout << res;
}
