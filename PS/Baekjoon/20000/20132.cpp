#include <bits/stdc++.h>
#define int long long
#define MAX 120000
#define MAX_LOG 18

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, uf_parent[MAX], depth[MAX];
bool checked[MAX];
vector<tp> link;
vector<pr> arr[MAX];
tp parent[MAX][MAX_LOG];

int second_max(int a, int b, int c, int d)
{
    int scl[4] = {a, b, c, d};
    sort(scl, scl + 4);
    for (int i = 2; i >= 0; i--)
    {
        if (scl[i] < scl[3])
            return scl[i];
    }
    return -1;
}

void clear(int K)
{
    for (int i = 1; i <= K; i++)
        uf_parent[i] = i;
}

int find(int K)
{
    if (uf_parent[K] != K)
        uf_parent[K] = find(uf_parent[K]);
    return uf_parent[K];
}

void uni(int A, int B)
{
    A = find(A), B = find(B);
    if (A > B)
        swap(A, B);
    uf_parent[B] = A;
}

void dfs(int K)
{
    int A;
    stack<int> st;

    st.push(K);
    checked[K] = true;

    while (!st.empty())
    {
        A = st.top();
        st.pop();

        for (pr i : arr[A])
        {
            if (checked[i.first])
                continue;
            parent[i.first][0] = {A, i.second, -1};
            checked[i.first] = true;
            depth[i.first] = depth[A] + 1;

            for (int j = 1; j < MAX_LOG; j++)
            {
                if (!parent[i.first][j - 1][0])
                    continue;
                parent[i.first][j] = {
                    parent[parent[i.first][j - 1][0]][j - 1][0],
                    max(parent[parent[i.first][j - 1][0]][j - 1][1], parent[i.first][j - 1][1]),
                    second_max(parent[i.first][j - 1][2], parent[i.first][j - 1][1], parent[parent[i.first][j - 1][0]][j - 1][1], parent[parent[i.first][j - 1][0]][j - 1][2])};
            }

            st.push(i.first);
        }
    }
}

pr max_weight(int A, int B)
{
    if (depth[A] < depth[B])
        swap(A, B);

    int diff = depth[A] - depth[B], res_first = -1, res_second = -1;
    for (int i = 0; diff; i++)
    {
        if (diff & 1)
        {
            if (parent[A][i][1] > res_first)
            {
                res_second = res_first;
                res_first = parent[A][i][1];
            }
            else if (res_first > parent[A][i][1] && parent[A][i][1] > res_second)
                res_second = parent[A][i][1];
            if (parent[A][i][2] > res_first)
            {
                res_second = res_first;
                res_first = parent[A][i][2];
            }
            else if (res_first > parent[A][i][2] && parent[A][i][2] > res_second)
                res_second = parent[A][i][2];
            A = parent[A][i][0];
        }
        diff >>= 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--)
    {
        if (parent[A][i][0] != parent[B][i][0])
        {
            if (parent[A][i][1] > res_first)
            {
                res_second = res_first;
                res_first = parent[A][i][1];
            }
            else if (res_first > parent[A][i][1] && parent[A][i][1] > res_second)
                res_second = parent[A][i][1];
            if (parent[B][i][1] > res_first)
            {
                res_second = res_first;
                res_first = parent[B][i][1];
            }
            else if (res_first > parent[B][i][1] && parent[B][i][1] > res_second)
                res_second = parent[B][i][1];
            A = parent[A][i][0], B = parent[B][i][0];
        }
    }
    if (A != B)
    {
        if (parent[A][0][1] > res_first)
        {
            res_second = res_first;
            res_first = parent[A][0][1];
        }
        else if (res_first > parent[A][0][1] && parent[A][0][1] > res_second)
            res_second = parent[A][0][1];
        if (parent[B][0][1] > res_first)
        {
            res_second = res_first;
            res_first = parent[B][0][1];
        }
        else if (res_first > parent[B][0][1] && parent[B][0][1] > res_second)
            res_second = parent[B][0][1];
    }
    return {res_first, res_second};
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V, E, A, B, C, res = 0, cnt = 0, odd_min = -1, even_min = -1;
    cin >> V >> E;

    clear(V);

    while (E--)
    {
        cin >> A >> B >> C;
        link.push_back({C, A, B});
    }
    sort(link.begin(), link.end());

    for (tp i : link)
    {
        A = find(i[1]), B = find(i[2]);
        if (A == B)
            continue;

        uni(A, B);
        res += i[0];
        cnt++;
        arr[i[2]].push_back({i[1], i[0]});
        arr[i[1]].push_back({i[2], i[0]});
    }

    if (cnt != V - 1)
    {
        cout << -1 << ' ' << -1;
        return 0;
    }

    dfs(1);

    vector<int> second_mst;
    second_mst.push_back(res);
    for (tp i : link)
    {
        pr val = max_weight(i[1], i[2]);
        if (val.second != -1 && i[0] > val.second)
            second_mst.push_back(res + i[0] - val.second);
        if (val.first != -1 && i[0] > val.first)
            second_mst.push_back(res + i[0] - val.first);
    }
    sort(second_mst.begin(), second_mst.end());
    second_mst.erase(unique(second_mst.begin(), second_mst.end()), second_mst.end());

    for (int i : second_mst)
    {
        if (i % 2 && odd_min == -1)
            odd_min = i;
        else if (i % 2 == 0 && even_min == -1)
            even_min = i;
    }

    cout << odd_min << ' ' << even_min;

    return 0;
}