#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 200001
using namespace std;

int parent[MAX];

int find(int i)
{
    if (i != parent[i])
        parent[i] = find(parent[i]);
    return parent[i];
}

void uni(int i, int j)
{
    i = find(i), j = find(j);
    parent[max(i, j)] = min(i, j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, Q, U, V, A, B, rt = -1;
    long long W, def = 0;
    vector<pair<long long int, pair<int, int>>> unsorted_lines, lines;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    int money[N + 1][N + 1];

    while (M--)
    {
        cin >> U >> V >> W;
        money[U][V] = W;
        money[V][U] = W;

        lines.push_back({W, {U, V}});
        unsorted_lines.push_back({W, {U, V}});
    }
    sort(lines.begin(), lines.end());

    vector<pair<int, long long int>> arr[N + 1];
    int depth[N + 1]{};
    stack<int> st;
    pair<int, long long int> parent[N + 1][18] = {(pair<int, long long int>){0, 0}};
    bool checked[N + 1] = {};

    for (pair<long long int, pair<int, int>> i : lines)
    {
        A = find(i.second.first), B = find(i.second.second);
        if (A == B)
            continue;

        uni(A, B);
        def += i.first;

        arr[i.second.first].push_back({i.second.second, i.first});
        arr[i.second.second].push_back({i.second.first, i.first});

        if (rt == -1)
            rt = A;
    }

    st.push(rt);
    checked[rt] = true;

    while (!st.empty())
    {
        A = st.top();
        st.pop();

        for (pair<int, long long int> i : arr[A])
        {
            if (checked[i.first])
                continue;

            parent[i.first][0] = {A, i.second};
            checked[i.first] = true;
            depth[i.first] = depth[A] + 1;

            for (int j = 1; 1 << j <= N; j++)
            {
                if (!parent[i.first][j - 1].first)
                    break;

                parent[i.first][j] = {
                    parent[parent[i.first][j - 1].first][j - 1].first,
                    max(parent[parent[i.first][j - 1].first][j - 1].second, parent[i.first][j - 1].second)};
            }

            st.push(i.first);
        }
    }

    cin >> Q;
    while (Q--)
    {
        cin >> A >> B;

        if (depth[A] < depth[B])
            swap(A, B);

        int diff = depth[A] - depth[B], j = 0, U = money[A][B];
        long long int res = 0;

        while (diff)
        {
            if (diff % 2)
            {
                res = max(res, parent[A][j].second);
                A = parent[A][j].first;
            }
            j++;
            diff >>= 1;
        }

        for (int j = 17; j >= 0; j--)
        {
            if (parent[A][j].first != parent[B][j].first)
            {
                res = max(res, max(parent[A][j].second, parent[B][j].second));
                A = parent[A][j].first, B = parent[B][j].first;
            }
        }

        if (A != B)
            res = max(res, max(parent[A][0].second, parent[B][0].second));

        cout << def - res + U << '\n';
    }
}