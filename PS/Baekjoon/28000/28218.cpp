#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

bool arr[1000][1000], dp[1000][1000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, Q, B, C, x, y;
    bool checked = false;
    cin >> N >> M >> K;

    char A;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A;
            if (A == '.')
                arr[i][j] = true;
            else
                arr[i][j] = false;
        }
    }

    dp[N - 1][M - 1] = false;
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = M - 1; j >= 0; j--)
        {
            if (!arr[i][j])
                continue;
            vector<pr> next;
            next.push_back({i + 1, j});
            next.push_back({i, j + 1});
            for (int k = 1; k <= K; k++)
                next.push_back({i + k, j + k});

            checked = false;
            for (pr k : next)
            {
                x = k.first, y = k.second;
                if (!arr[x][y] || dp[x][y])
                    continue;
                checked = true;
            }
            dp[i][j] = checked;
        }
    }

    cin >> Q;
    while (Q--)
    {
        cin >> B >> C;
        if (dp[--B][--C])
            cout << "First\n";
        else
            cout << "Second\n";
    }

    return 0;
}