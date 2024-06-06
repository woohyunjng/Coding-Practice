#include <bits/stdc++.h>
#define int long long
#define MAX 300

using namespace std;

vector<int> arr[MAX];
stack<int> st;
int mx[MAX][MAX], flow[MAX][MAX], parent[MAX], res[MAX][MAX];
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

    int N, A, mx = -1, sm = 0, start, end, mid, res_mid;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> A;
        mx = max(mx, A);
        add_path(0, i, A);
        sm += A;
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> A;
        mx = max(mx, A);
        add_path(N + i, 2 * N + 1, A);
    }

    start = 1, end = mx;
    while (start <= end)
    {
        mid = (start + end) / 2;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
                add_path(i, N + j, mid);
        }
        memset(flow, 0, sizeof(flow));
        A = maximum_flow(0, 2 * N + 1);

        if (A != sm)
            start = mid + 1;
        else
        {
            res_mid = mid;
            end = mid - 1;
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= N; j++)
                    res[i][j] = flow[i][N + j];
            }
        }
    }

    cout << res_mid << '\n';
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << res[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}