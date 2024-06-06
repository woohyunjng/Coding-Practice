#include <bits/stdc++.h>
#define MAX 1010
#define int long long

using namespace std;
typedef pair<int, int> pr;

int parent[MAX * MAX], cnt[MAX * MAX], res[MAX][MAX];
bool arr[MAX][MAX], checked[MAX][MAX];
pr X, go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int subst(int A, int B) { return A * MAX + B; }
pr to_pair(int K) { return {K / MAX, K % MAX}; }

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

    int N, M, x, y;
    string S;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> S;
        for (int j = 1; j <= M; j++)
        {
            parent[subst(i, j)] = subst(i, j);
            if (S[j - 1] == '1')
                arr[i][j] = true;
            else
                arr[i][j] = false;
        }
    }

    queue<pr> q;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (checked[i][j] || arr[i][j])
                continue;
            q.push({i, j});
            checked[i][j] = true;

            while (!q.empty())
            {
                X = q.front();
                q.pop();

                for (pr k : go)
                {
                    x = X.first + k.first, y = X.second + k.second;
                    if (x <= 0 || y <= 0 || x > N || y > M || checked[x][y] || arr[x][y])
                        continue;
                    checked[x][y] = true;
                    uni(subst(X.first, X.second), subst(x, y));
                    q.push({x, y});
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cnt[find(subst(i, j))]++;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (!arr[i][j])
                continue;

            unordered_set<int> uset;
            for (pr k : go)
            {
                x = i + k.first, y = j + k.second;
                if (x <= 0 || y <= 0 || x > N || y > M || arr[x][y])
                    continue;
                uset.insert(find(subst(x, y)));
            }
            for (int k : uset)
                res[i][j] += cnt[k];
            res[i][j]++;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cout << res[i][j] % 10;
        cout << '\n';
    }

    return 0;
}