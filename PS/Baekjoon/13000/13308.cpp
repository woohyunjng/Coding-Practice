#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<long long, pair<long long, long long>> pl;

struct cmp
{
    bool operator()(pl a, pl b)
    {
        return a.first > b.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N, M, A, B, C;
    cin >> N >> M;

    long long money[N + 1], min_money[N + 1][2501], mn, res = 0x3f3f3f3f3f3f3f3f;
    for (long long i = 1; i <= N; i++)
    {
        cin >> money[i];
        for (long long j = 1; j <= 2500; j++)
        {
            min_money[i][j] = res;
        }
    }

    vector<pair<long long, long long>> arr[N + 1];
    while (M--)
    {
        cin >> A >> B >> C;
        arr[A].push_back(make_pair(C, B));
        arr[B].push_back(make_pair(C, A));
    }

    priority_queue<pl, vector<pl>, greater<pl>> q;
    q.push(make_pair(0, make_pair(1, money[1])));
    min_money[1][money[1]] = 0;

    while (!q.empty())
    {
        pl p = q.top();
        q.pop();

        if (p.second.first == N)
        {
            cout << p.first;
            break;
        }

        if (p.first > min_money[p.second.first][p.second.second])
            continue;

        for (pair<long long, long long> i : arr[p.second.first])
        {
            mn = min(p.second.second, money[i.second]);
            if (i.first * p.second.second + p.first < min_money[i.second][mn])
            {
                min_money[i.second][mn] = i.first * p.second.second + p.first;
                q.push(make_pair(min_money[i.second][mn], make_pair(i.second, mn)));
            }
        }
    }
}