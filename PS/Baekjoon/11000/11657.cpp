#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C;
    bool cycle = false;
    tuple<int, int, int> X;
    cin >> N >> M;

    vector<tuple<int, int, int>> arr[N + 1];
    while (M--)
    {
        cin >> A >> B >> C;
        arr[A].push_back({A, B, C});
    }

    queue<tuple<int, int, int>> q;
    long long dp[N + 1];
    for (int i = 0; i <= N; i++)
        dp[i] = 9223372036854775807;
    dp[1] = 0;

    for (tuple<int, int, int> i : arr[1])
        q.push(i);

    for (int i = 0; i < N; i++)
    {
        A = q.size();
        while (A--)
        {
            X = q.front();
            q.pop();
            if (get<2>(X) + dp[get<0>(X)] < dp[get<1>(X)])
            {
                if (i == N - 1)
                    cycle = true;
                dp[get<1>(X)] = get<2>(X) + dp[get<0>(X)];
                for (tuple<int, int, int> i : arr[get<1>(X)])
                {
                    q.push(i);
                }
            }
        }
    }

    if (cycle)
        cout << -1;
    else
    {
        for (int i = 2; i <= N; i++)
        {
            cout << (dp[i] < 9223372036854775807 ? dp[i] : -1) << '\n';
        }
    }
}