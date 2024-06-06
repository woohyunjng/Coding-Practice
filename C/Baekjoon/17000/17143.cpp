#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

tp arr[110][110], before_arr[110][110];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int R, C, M, r, c, go_x, go_y, s, d, z, res = 0;
    cin >> R >> C >> M;

    while (M--)
    {
        cin >> r >> c >> s >> d >> z;
        arr[r][c] = {s, d, z};
    }

    for (int i = 1; i <= C; i++)
    {
        for (int j = 1; j <= R; j++)
        {
            if (get<2>(arr[j][i]))
            {
                res += get<2>(arr[j][i]);
                arr[j][i] = {0, 0, 0};
                break;
            }
        }

        for (int x = 1; x <= R; x++)
        {
            for (int y = 1; y <= C; y++)
            {
                before_arr[x][y] = arr[x][y];
                arr[x][y] = {0, 0, 0};
            }
        }

        for (int x = 1; x <= R; x++)
        {
            for (int y = 1; y <= C; y++)
            {
                s = get<0>(before_arr[x][y]), d = get<1>(before_arr[x][y]), z = get<2>(before_arr[x][y]);
                if (!z)
                    continue;

                go_x = x, go_y = y;
                if (d == 1)
                {
                    s %= 2 * R - 2;
                    go_x -= s;
                    if (go_x <= 0)
                    {
                        d = 2;
                        go_x = 2 - go_x;
                    }
                    if (go_x > R)
                    {
                        d = 1;
                        go_x = R * 2 - go_x;
                    }
                }
                else if (d == 2)
                {
                    s %= 2 * R - 2;
                    go_x += s;
                    if (go_x > R)
                    {
                        d = 1;
                        go_x = R * 2 - go_x;
                    }
                    if (go_x <= 0)
                    {
                        d = 2;
                        go_x = 2 - go_x;
                    }
                }
                else if (d == 3)
                {

                    s %= 2 * C - 2;
                    go_y += s;
                    if (go_y > C)
                    {
                        d = 4;
                        go_y = C * 2 - go_y;
                    }
                    if (go_y <= 0)
                    {
                        d = 3;
                        go_y = 2 - go_y;
                    }
                }
                else
                {
                    s %= 2 * C - 2;
                    go_y -= s;
                    if (go_y <= 0)
                    {
                        d = 3;
                        go_y = 2 - go_y;
                    }
                    if (go_y > C)
                    {
                        d = 4;
                        go_y = C * 2 - go_y;
                    }
                }

                if (get<2>(arr[go_x][go_y]) < z)
                    arr[go_x][go_y] = {s, d, z};
            }
        }
    }

    cout << res;

    return 0;
}