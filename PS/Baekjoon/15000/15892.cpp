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

    int N, M, a, b, c, res = 0, val = 0;
    cin >> N >> M;

    vector<int> arr[N + 1];
    stack<int> st;
    int mx[N + 1][N + 1], flow[N + 1][N + 1], parent[N + 1];

    memset(mx, 0, sizeof(mx));
    memset(flow, 0, sizeof(flow));

    while (M--)
    {
        cin >> a >> b >> c;
        arr[a].push_back(b);
        arr[b].push_back(a);
        mx[a][b] += c;
        mx[b][a] += c;
    }

    while (true)
    {
        val = 101;
        memset(parent, 0, sizeof(parent));

        st.push(1);
        parent[1] = -1;

        while (!st.empty())
        {
            a = st.top();
            st.pop();

            if (a == N)
                break;

            for (int i : arr[a])
            {
                if (flow[a][i] >= mx[a][i] || parent[i])
                    continue;
                parent[i] = a;
                st.push(i);
            }
        }

        if (!parent[N])
            break;

        a = N;
        while (a > 1)
        {
            val = min(val, mx[parent[a]][a] - flow[parent[a]][a]);
            a = parent[a];
        }

        a = N;
        while (a > 1)
        {
            flow[parent[a]][a] += val;
            flow[a][parent[a]] -= val;
            a = parent[a];
        }
        res += val;

        while (!st.empty())
            st.pop();
    }

    cout << res;
}