#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int H[2000][2000], res[2000][2000], parent[2000000], cur[2000000];
pr go[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pr> sizearr[2000000];

int find(int k)
{
    if (parent[k] != k)
        parent[k] = find(parent[k]);
    return parent[k];
}

int uni(int x, int y)
{
    if (x > y)
        swap(x, y);
    parent[y] = x;
    return y;
}

int getPar(int x, int y) { return 1000 * x + y; }

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, filled = 0, x, y, go_x, go_y, fillnum;
    cin >> N >> M;

    vector<int> arr, sq;
    queue<pr> q;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> H[i][j];
            sq.push_back(H[i][j]);
            parent[getPar(i, j)] = getPar(i, j);
        }
    }
    sort(sq.begin(), sq.end());
    sq.erase(unique(sq.begin(), sq.end()), sq.end());

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            sizearr[lower_bound(sq.begin(), sq.end(), H[i][j]) - sq.begin()].push_back({i, j});
    }
    sort(arr.begin(), arr.end());

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> x;
            cur[getPar(i, j)] += x;
        }
    }

    for (int i = 0; i < sq.size(); i++)
    {
        for (pr j : sizearr[i])
        {
            x = j.first, y = j.second;
            for (pr k : go)
            {
                int go_x = x + k.first, go_y = y + k.second;
                if (go_x <= 0 || go_y <= 0 || go_x > N || go_y > M)
                    continue;
                if (H[go_x][go_y] <= H[x][y])
                {
                    int a = find(getPar(x, y)), b = find(getPar(go_x, go_y));
                    if (a != b)
                    {
                        if (a > b)
                            swap(a, b);
                        filled = uni(a, b);
                        cur[a] += cur[b];
                    }
                }
            }
        }
        for (pr j : sizearr[i])
        {
            x = j.first, y = j.second;
            res[x][y] = cur[find(getPar(x, y))];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cout << res[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
