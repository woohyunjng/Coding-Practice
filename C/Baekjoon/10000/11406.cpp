#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, res = 0, val = 0;
    cin >> N >> M;

    int size = N + M + 1;

    vector<int> arr[size + 1];
    stack<int> st;
    int mx[size + 1][size + 1], flow[size + 1][size + 1], parent[size + 1];

    memset(mx, 0, sizeof(mx));
    memset(flow, 0, sizeof(flow));

    for (int i = 1; i <= N; i++)
    {
        cin >> mx[0][i];
        arr[0].push_back(i);
        arr[i].push_back(0);
    }

    for (int i = 1; i <= M; i++)
    {
        cin >> mx[N + i][size];
        arr[N + i].push_back(size);
        arr[size].push_back(N + i);
    }

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> mx[j][N + i];
            arr[j].push_back(N + i);
            arr[N + i].push_back(j);
        }
    }

    while (true)
    {
        val = 100;
        memset(parent, -1, sizeof(parent));

        st.push(0);
        parent[0] = 0;

        while (!st.empty())
        {
            A = st.top();
            st.pop();

            if (A == size)
                break;

            for (int i : arr[A])
            {
                if (flow[A][i] < mx[A][i] && parent[i] == -1)
                {
                    parent[i] = A;
                    st.push(i);
                }
            }
        }

        if (parent[size] == -1)
            break;

        A = size;
        while (A > 0)
        {
            val = min(val, mx[parent[A]][A] - flow[parent[A]][A]);
            A = parent[A];
        }

        A = size;
        while (A > 0)
        {
            flow[parent[A]][A] += val;
            flow[A][parent[A]] -= val;
            A = parent[A];
        }
        res += val;

        while (!st.empty())
            st.pop();
    }

    cout << res;
}