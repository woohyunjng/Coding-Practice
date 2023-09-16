#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, M, a, b, c, diff, j, root;
    cin >> T;

    while (T--)
    {
        cin >> N;

        vector<int> arr[N + 1];
        int parent[N + 1][15] = {}, depth[N + 1] = {};

        for (int i = 0; i < N - 1; i++)
        {
            cin >> a >> b;
            parent[b][0] = a;
            arr[a].push_back(b);
        }

        for (int i = 1; i <= N; i++)
        {
            if (!parent[i][0])
                root = i;
        }

        stack<int> st;
        st.push(root);

        while (!st.empty())
        {
            a = st.top();
            st.pop();

            for (int i : arr[a])
            {
                depth[i] = depth[a] + 1;
                for (int j = 1; 1 << j <= N; j++)
                {
                    if (!parent[i][j - 1])
                        break;
                    parent[i][j] = parent[parent[i][j - 1]][j - 1];
                }

                st.push(i);
            }
        }

        cin >> a >> b;
        if (depth[a] < depth[b])
        {
            c = b;
            b = a;
            a = c;
        }

        diff = depth[a] - depth[b];
        j = 0;

        while (diff)
        {
            if (diff % 2)
                a = parent[a][j];
            j++;
            diff /= 2;
        }

        for (int j = 14; j >= 0; j--)
        {
            if (parent[a][j] != parent[b][j])
            {
                a = parent[a][j];
                b = parent[b][j];
            }
        }
        if (a != b)
            a = parent[a][0];

        cout << a << '\n';
    }
}
