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

    int N, M, A, B, res = 0, val = 0;
    cin >> N >> M;

    vector<int> arr[N + M + 2];
    stack<int> st;
    int mx[N + M + 2][N + M + 2], flow[N + M + 2][N + M + 2], parent[N + M + 2];

    memset(mx, 0, sizeof(mx));
    memset(flow, 0, sizeof(flow));

    for (int i = 1; i <= N; i++)
    {
        arr[0].push_back(i);
        arr[i].push_back(0);
        mx[0][i] = 1;

        cin >> A;
        while (A--)
        {
            cin >> B;
            arr[i].push_back(N + B);
            arr[N + B].push_back(i);
            mx[i][N + B] = 1;
        }
    }

    for (int i = 1; i <= M; i++)
    {
        arr[N + i].push_back(N + M + 1);
        arr[N + M + 1].push_back(N + i);
        mx[N + i][N + M + 1] = 1;
    }

    while (true)
    {
        val = 1;
        memset(parent, -1, sizeof(parent));

        st.push(0);
        parent[0] = 0;

        while (!st.empty())
        {
            A = st.top();
            st.pop();

            if (A == N + M + 1)
                break;

            for (int i : arr[A])
            {
                if (flow[A][i] >= mx[A][i] || parent[i] != -1)
                    continue;
                parent[i] = A;
                st.push(i);
            }
        }

        if (parent[N + M + 1] == -1)
            break;

        A = N + M + 1;
        while (A > 0)
        {
            val = min(val, mx[parent[A]][A] - flow[parent[A]][A]);
            A = parent[A];
        }

        A = N + M + 1;
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