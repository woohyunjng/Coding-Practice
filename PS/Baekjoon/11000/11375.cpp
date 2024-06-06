#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, max_point;
    cin >> N >> M;

    vector<int> arr[N + M + 2];
    stack<int> st;

    int mx[N + M + 2][N + M + 2], flow[N + M + 2][N + M + 2], res = 0, parent[N + M + 2], val = 0;
    bool checked[N + M + 2];
    memset(mx, 0, sizeof(mx));
    memset(flow, 0, sizeof(flow));

    for (int i = 1; i <= N; i++)
    {
        arr[0].push_back(i);
        arr[i].push_back(0);
        mx[0][i] = 1;

        cin >> A;
        for (int j = 0; j < A; j++)
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
        val = 2;
        memset(parent, -1, sizeof(parent));
        memset(checked, false, sizeof(checked));

        max_point = 0;
        st.push(0);
        checked[0] = true;

        while (!st.empty())
        {
            A = st.top();
            st.pop();
            max_point = max(max_point, A);

            if (A == N + M + 1)
                break;

            for (int i : arr[A])
            {
                if (flow[A][i] >= mx[A][i] || parent[i] != -1 || checked[i])
                    continue;
                parent[i] = A;
                checked[i] = true;
                parent[i] = A;
                st.push(i);
            }
        }

        if (max_point != N + M + 1)
            break;

        A = N + M + 1;
        while (parent[A] != -1)
        {
            val = min(val, mx[parent[A]][A] - flow[parent[A]][A]);
            flow[parent[A]][A] = mx[parent[A]][A];
            flow[A][parent[A]] = -mx[parent[A]][A];
            A = parent[A];
        }
        res += val;

        while (!st.empty())
            st.pop();
    }

    cout << res;
}