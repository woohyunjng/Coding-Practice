#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;

int arr[1010][1010], parent[10101010];
bool checked[10101010];
pr go[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int find(int i)
{
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

void uni(int i, int j)
{
    if (i > j)
        swap(i, j);
    parent[j] = i;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, res = 0;
    string input;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> input;
        for (int j = 1; j <= M; j++)
        {
            if (input[j - 1] == 'D')
                arr[i][j] = 2;
            else if (input[j - 1] == 'U')
                arr[i][j] = 3;
            else if (input[j - 1] == 'L')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
            parent[1001 * i + j] = 1001 * i + j;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            int cur = 1001 * i + j, next = 1001 * (i + go[arr[i][j]].first) + (j + go[arr[i][j]].second);
            cur = find(cur), next = find(next);
            if (cur != next)
                uni(cur, next);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            int cur = find(1001 * i + j);
            if (!checked[cur])
            {
                checked[cur] = true;
                res++;
            }
        }
    }

    cout << res;

    return 0;
}