#include <bits/stdc++.h>
#define int long long
#define MAX 400

using namespace std;

vector<int> arr[MAX];
stack<int> st;
int mx[MAX][MAX], flow[MAX][MAX], parent[MAX];
bool checked[MAX];

void add_path(int A, int B, int mx_size)
{
    arr[A].push_back(B);
    arr[B].push_back(A);
    mx[A][B] = mx_size;
}

int maximum_flow(int start, int end)
{
    int res = 0;

    while (true)
    {
        int val = LLONG_MAX, max_point = 0, A;
        memset(parent, -1, sizeof(parent));
        memset(checked, false, sizeof(checked));

        st.push(start);
        checked[start] = true;

        while (!st.empty())
        {
            A = st.top();
            st.pop();
            max_point = max(max_point, A);

            if (A == end)
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

        if (max_point != end)
            break;
        A = end;
        while (parent[A] != -1)
        {
            val = min(val, mx[parent[A]][A] - flow[parent[A]][A]);
            A = parent[A];
        }
        A = end;
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

    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, D, mx_size, Z, go;
    cin >> N >> K >> D;

    for (int i = 1; i <= D; i++)
    {
        cin >> mx_size;
        add_path(N + i, N + D + 1, mx_size);
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> Z;
        add_path(0, i, K);
        while (Z--)
        {
            cin >> go;
            add_path(i, N + go, 1);
        }
    }

    cout << maximum_flow(0, N + D + 1);

    return 0;
}