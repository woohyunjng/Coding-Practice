#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N, K, X, Y, W;
        cin >> N >> K;

        int D[N + 1], ent[N + 1] = {}, dp[N + 1] = {};
        vector<int> arr[N + 1], buildings;

        for (int i = 1; i <= N; i++)
            cin >> D[i];

        while (K--)
        {
            cin >> X >> Y;
            arr[X].push_back(Y);
            ent[Y]++;
        }

        cin >> W;
        queue<int> q;

        for (int i = 1; i <= N; i++)
        {
            if (!ent[i])
                q.push(i);
        }

        while (q.size())
        {
            int i = q.front();
            dp[i] += D[i];

            if (i == W)
            {
                cout << dp[i] << '\n';
                break;
            }
            buildings.push_back(i);
            q.pop();

            for (int j : arr[i])
            {
                ent[j] -= 1;
                dp[j] = max(dp[i], dp[j]);
                if (!ent[j])
                    q.push(j);
            }
        }
    }
}