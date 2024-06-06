#include <bits/stdc++.h>
#define MAX_LONG_LONG 9223372036854775807
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int arr[1010][1010], parent[10101010], res[1010][1010];
bool checked[10101010];
pr go[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<pr> vec[10101010];

int subst(int A, int B) { return A * 1001 + B; }
pr to_pair(int K) { return {K / 1001, K % 1001}; }

int find(int K)
{
    if (parent[K] != K)
        parent[K] = find(parent[K]);
    return parent[K];
}

void uni(int A, int B)
{
    A = find(A), B = find(B);
    if (A > B)
        swap(A, B);
    parent[B] = A;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, x, y, z, w, K, mx;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
            parent[subst(i, j)] = subst(i, j);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (pr k : go)
            {
                x = i + k.first, y = j + k.second;
                if (x <= 0 || x > N || y <= 0 || y > M || arr[x][y] != arr[i][j])
                    continue;
                uni(subst(x, y), subst(i, j));
            }
        }
    }

    vector<pr> size_index;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            K = find(subst(i, j));
            vec[K].push_back({i, j});
            if (checked[K])
                continue;

            pr A = to_pair(K);
            size_index.push_back({arr[A.first][A.second], K});
            checked[K] = true;
        }
    }

    sort(size_index.begin(), size_index.end());

    for (pr i : size_index)
    {
        mx = -1;
        for (pr j : vec[i.second])
        {
            x = j.first, y = j.second;
            for (pr k : go)
            {
                z = x + k.first, w = y + k.second;
                if (z <= 0 || z > N || w <= 0 || w > M || arr[x][y] <= arr[z][w])
                    continue;
                mx = max(mx, res[z][w]);
            }
        }
        for (pr j : vec[i.second])
        {
            x = j.first, y = j.second;
            res[x][y] = mx + 1;
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