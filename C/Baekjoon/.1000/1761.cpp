#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, a, b, c, diff, j, x, y;
    cin >> N;

    vector<pair<int, int>> arr[N + 1];
    bool checked[N + 1] = {};

    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b >> c;
        arr[a].push_back(make_pair(b, c));
        arr[b].push_back(make_pair(a, c));
    }

    stack<int> st;
    int parent[N + 1][17] = {}, depth[N + 1] = {}, length[N + 1] = {};

    st.push(1);
    checked[1] = true;

    while (!st.empty())
    {
        a = st.top();
        st.pop();

        for (pair<int, int> i : arr[a])
        {
            if (checked[i.first])
                continue;

            parent[i.first][0] = a;
            checked[i.first] = true;
            depth[i.first] = depth[a] + 1;
            length[i.first] = length[a] + i.second;

            for (int j = 1; 1 << j <= N; j++)
            {
                if (!parent[i.first][j - 1])
                    break;
                parent[i.first][j] = parent[parent[i.first][j - 1]][j - 1];
            }

            st.push(i.first);
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        if (depth[a] < depth[b])
        {
            x = b;
            y = a;
        }
        else
        {
            x = a;
            y = b;
        }

        diff = depth[x] - depth[y];
        j = 0;

        while (diff)
        {
            if (diff % 2)
                x = parent[x][j];
            j++;
            diff /= 2;
        }

        for (int j = 16; j >= 0; j--)
        {
            if (parent[x][j] != parent[y][j])
            {
                x = parent[x][j];
                y = parent[y][j];
            }
        }

        if (x != y)
            x = parent[x][0];

        cout << length[a] + length[b] - length[x] * 2 << '\n';
    }
}
