#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;

int row[600], col[600], arr[600][600];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    bool checked;
    cin >> N;

    priority_queue<pr> pq;
    stack<pr> st;

    for (int i = 0; i < N; i++)
    {
        cin >> row[i];
        if (row[i])
            pq.push({row[i], i});
    }

    for (int i = 0; i < N; i++)
        cin >> col[i];

    for (int i = 0; i < N; i++)
    {
        while (col[i])
        {
            if (pq.empty())
            {
                cout << -1;
                return 0;
            }

            pr j = pq.top();
            pq.pop();
            if (arr[j.second][i])
            {
                st.push(j);
                continue;
            }

            col[i]--;
            if (j.first > 1)
                pq.push({j.first - 1, j.second});
            arr[j.second][i] = 1;
        }

        while (!st.empty())
        {
            pq.push(st.top());
            st.pop();
        }
    }
    if (!pq.empty())
    {
        cout << -1;
        return 0;
    }

    cout << 1 << '\n';

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j];
        cout << '\n';
    }

    return 0;
}