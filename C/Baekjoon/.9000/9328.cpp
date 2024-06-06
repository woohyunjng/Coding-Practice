#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

pr go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, H, W, res, x, y, A, arr[110][110];
    bool key[27], checked[110][110];
    string S;
    char K;
    queue<pr> q, q_before;
    vector<pr> doors[27];

    cin >> T;

    while (T--)
    {
        fill(key, key + 27, false);

        res = 0;
        cin >> H >> W;
        for (int i = 1; i <= H; i++)
        {
            cin >> S;
            for (int j = 1; j <= W; j++)
            {
                checked[i][j] = false;
                K = S[j - 1];
                if (K == '*')
                    arr[i][j] = -1;
                else if (K == '.')
                    arr[i][j] = 0;
                else if (K == '$')
                    arr[i][j] = 100;
                else if ('A' <= K && K <= 'Z')
                    arr[i][j] = K - 'A' + 1;
                else if ('a' <= K && K <= 'z')
                    arr[i][j] = K - 'a' + 1 + 26;
            }
        }

        for (int i = 1; i <= 26; i++)
            doors[i].clear();

        cin >> S;
        if (S != "0")
        {
            for (char i : S)
                key[i - 'a' + 1] = true;
        }

        for (int i = 1; i <= W; i++)
        {
            q_before.push({1, i});
            q_before.push({H, i});
        }

        for (int i = 2; i < H; i++)
        {
            q_before.push({i, 1});
            q_before.push({i, W});
        }

        while (!q_before.empty())
        {
            pr K = q_before.front();
            q_before.pop();
            x = K.first, y = K.second;

            if (arr[x][y] == -1)
                continue;

            checked[x][y] = true;
            if (arr[x][y] == 0)
                q.push({x, y});
            else if (arr[x][y] == 100)
            {
                q.push({x, y});
                res++;
            }
            else if (27 <= arr[x][y] && arr[x][y] <= 52)
            {
                q.push({x, y});
                A = arr[x][y] - 26;
                if (!key[A])
                {
                    key[A] = true;
                    for (pr i : doors[A])
                        q.push(i);
                }
            }
            else if (1 <= arr[x][y] && arr[x][y] <= 26)
            {
                if (key[arr[x][y]])
                    q.push({x, y});
                else
                    doors[arr[x][y]].push_back({x, y});
            }
        }

        while (!q.empty())
        {
            pr K = q.front();
            q.pop();

            for (pr k : go)
            {
                x = K.first + k.first, y = K.second + k.second;
                if (x <= 0 || x > H || y <= 0 || y > W || checked[x][y] || arr[x][y] == -1)
                    continue;
                checked[x][y] = true;
                if (arr[x][y] == 0)
                    q.push({x, y});
                else if (arr[x][y] == 100)
                {
                    q.push({x, y});
                    res++;
                }
                else if (27 <= arr[x][y] && arr[x][y] <= 52)
                {
                    q.push({x, y});
                    A = arr[x][y] - 26;
                    if (!key[A])
                    {
                        key[A] = true;
                        for (pr i : doors[A])
                            q.push(i);
                    }
                }
                else if (1 <= arr[x][y] && arr[x][y] <= 26)
                {
                    if (key[arr[x][y]])
                        q.push({x, y});
                    else
                        doors[arr[x][y]].push_back({x, y});
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}