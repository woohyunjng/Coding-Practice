#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int parent[100001][18] = {}, depth[100001] = {};

int LCA(int u, int v)
{
    if (depth[u] < depth[v])
    {
        int temp = v;
        v = u;
        u = temp;
    }

    int diff = depth[u] - depth[v], i = 0;
    while (diff)
    {
        if (diff % 2)
            u = parent[u][i];
        i++;
        diff /= 2;
    }

    for (int i = 17; i >= 0; i--)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    if (u != v)
        u = parent[u][0];
    return u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, r, u, v;
    cin >> N;

    vector<int> arr[N + 1];
    bool checked[N + 1] = {};

    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v;
        arr[v].push_back(u);
        arr[u].push_back(v);
    }

    stack<int> st;
    st.push(1);
    checked[1] = true;

    while (!st.empty())
    {
        u = st.top();
        st.pop();

        for (int i : arr[u])
        {
            if (checked[i])
                continue;

            parent[i][0] = u;
            checked[i] = true;
            depth[i] = depth[u] + 1;

            for (int j = 1; 1 << j <= N; j++)
            {
                if (!parent[i][j - 1])
                    break;
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }

            st.push(i);
        }
    }

    cin >> M;
    while (M--)
    {
        cin >> r >> u >> v;
        int i = LCA(r, u), j = LCA(u, v), k = LCA(v, r), res;

        if (depth[i] >= depth[j] && depth[i] >= depth[k])
        {
            res = i;
        }
        else if (depth[j] >= depth[i] && depth[j] >= depth[k])
        {
            res = j;
        }
        else
        {
            res = k;
        }

        cout << res << '\n';
    }
}
