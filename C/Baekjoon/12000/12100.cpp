#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int N, arr[22][22];

int dfs(int K)
{
    int copy[22][22], res = 0, cnt, i, j;
    vector<int> row[22], col[22];

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            copy[i][j] = arr[i][j];
            if (arr[i][j])
            {
                row[i].push_back(arr[i][j]);
                col[j].push_back(arr[i][j]);
            }
            arr[i][j] = 0;
        }
    }

    for (i = 1; i <= N; i++)
    {
        cnt = 1;
        for (j = 0; j < row[i].size(); j++)
        {
            if (j + 1 < row[i].size() && row[i][j] == row[i][j + 1])
            {
                arr[i][cnt] = row[i][j] + 1;
                j++;
            }
            else
                arr[i][cnt] = row[i][j];
            cnt++;
        }
    }
    if (K < 5)
        res = max(res, dfs(K + 1));
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            res = max(res, arr[i][j]);
            arr[i][j] = 0;
        }
    }

    for (i = 1; i <= N; i++)
    {
        cnt = N;
        for (j = row[i].size() - 1; j >= 0; j--)
        {
            if (j - 1 >= 0 && row[i][j] == row[i][j - 1])
            {
                arr[i][cnt] = row[i][j] + 1;
                j--;
            }
            else
                arr[i][cnt] = row[i][j];
            cnt--;
        }
    }
    if (K < 5)
        res = max(res, dfs(K + 1));
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            res = max(res, arr[i][j]);
            arr[i][j] = 0;
        }
    }

    for (i = 1; i <= N; i++)
    {
        cnt = 1;
        for (j = 0; j < col[i].size(); j++)
        {
            if (j + 1 < col[i].size() && col[i][j] == col[i][j + 1])
            {
                arr[cnt][i] = col[i][j] + 1;
                j++;
            }
            else
                arr[cnt][i] = col[i][j];
            cnt++;
        }
    }
    if (K < 5)
        res = max(res, dfs(K + 1));
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            res = max(res, arr[i][j]);
            arr[i][j] = 0;
        }
    }

    for (i = 1; i <= N; i++)
    {
        cnt = N;
        for (j = col[i].size() - 1; j >= 0; j--)
        {
            if (j - 1 >= 0 && col[i][j] == col[i][j - 1])
            {
                arr[cnt][i] = col[i][j] + 1;
                j--;
            }
            else
                arr[cnt][i] = col[i][j];
            cnt--;
        }
    }
    if (K < 5)
        res = max(res, dfs(K + 1));
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            res = max(res, arr[i][j]);
            arr[i][j] = copy[i][j];
        }
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> K;
            while (K)
            {
                K >>= 1;
                arr[i][j]++;
            }
        }
    }

    cout << (1 << (dfs(1) - 1));
    return 0;
}