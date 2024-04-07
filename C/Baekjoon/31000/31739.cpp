#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int N, M, K, T, P, r, c, s, res_1 = 0, res_2 = 0;
bool checked[11] = {};

vector<tuple<int, int, int>> can_go[11];

void dfs(int n, int sm, int ds)
{
    checked[n] = true;
    if (ds > T)
    {
        checked[n] = false;
        return;
    }

    res_1 = max(res_1, sm);

    for (tuple<int, int, int> i : can_go[n])
    {
        if (!checked[get<2>(i)])
            dfs(get<2>(i), sm + get<1>(i), ds + get<0>(i));
    }
    checked[n] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K >> T >> P;

    vector<int> arr[N][M];
    vector<pair<int, int>> mos;
    int arr_dt[N][M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            arr_dt[i][j] = 0;
    }

    for (int i = 0; i < K; i++)
    {
        cin >> r >> c >> s;
        arr[r - 1][c - 1].push_back(s);

        arr_dt[r - 1][c - 1] += 1;
        if (arr_dt[r - 1][c - 1] == 1)
            mos.push_back({r - 1, c - 1});
    }

    for (int i = 0; i < mos.size(); i++)
    {
        for (int j = i + 1; j < mos.size(); j++)
        {
            int val = abs(mos[i].first - mos[j].first) + abs(mos[i].second - mos[j].second);
            can_go[i].push_back({val, arr_dt[mos[j].first][mos[j].second], j});
            can_go[j].push_back({val, arr_dt[mos[i].first][mos[i].second], i});
        }
    }

    for (int i = 0; i < mos.size(); i++)
    {
        for (int i = 0; i < mos.size(); i++)
            checked[i] = false;
        dfs(i, arr_dt[mos[i].first][mos[i].second], 0);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int val = 0;
            for (int x = 0; x < N; x++)
            {
                for (int y = 0; y < M; y++)
                {
                    int d = abs(x - i) + abs(y - j);
                    for (int k : arr[x][y])
                    {
                        if (P >= k * d)
                            val++;
                    }
                }
            }
            res_2 = max(res_2, val);
        }
    }

    cout << res_1 << ' ' << res_2;
}