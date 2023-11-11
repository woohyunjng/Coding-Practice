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

    int N, M, K, A, B, max_point;
    cin >> N >> M >> K;

    vector<int> arr[N + M + 4];
    stack<int> st;

    int mx[N + M + 4][N + M + 4], flow[N + M + 4][N + M + 4], res = 0, parent[N + M + 4], val = 0;
    bool checked[N + M + 4];
    memset(mx, 0, sizeof(mx));
    memset(flow, 0, sizeof(flow));

    arr[0].push_back(1);
    arr[1].push_back(0);
    arr[0].push_back(2);
    arr[2].push_back(0);
    mx[0][1] = N;
    mx[0][2] = K;

    for (int i = 3; i <= N + 2; i++)
    {
        arr[1].push_back(i);
        arr[i].push_back(1);
        arr[2].push_back(i);
        arr[i].push_back(2);
        mx[1][i] = 1;
        mx[2][i] = 1;

        cin >> A;
        for (int j = 0; j < A; j++)
        {
            cin >> B;
            arr[i].push_back(N + B + 2);
            arr[N + B + 2].push_back(i);
            mx[i][N + B + 2] = 1;
        }
    }

    for (int i = 3; i <= M + 2; i++)
    {
        arr[N + i].push_back(N + M + 3);
        arr[N + M + 3].push_back(N + i);
        mx[N + i][N + M + 3] = 1;
    }

    while (true)
    {
        val = 100;
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

            if (A == N + M + 3)
                break;

            for (int i : arr[A])
            {
                if (flow[A][i] >= mx[A][i] || parent[i] != -1 || checked[i])
                    continue;
                checked[i] = true;
                parent[i] = A;
                st.push(i);
            }
        }

        if (max_point != N + M + 3)
            break;

        A = N + M + 3;
        while (parent[A] != -1)
        {
            val = min(val, mx[parent[A]][A] - flow[parent[A]][A]);
            A = parent[A];
        }
        A = N + M + 3;
        while (parent[A] != -1)
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