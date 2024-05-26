#include <bits/stdc++.h>
#define int long long
using namespace std;

int parent[201000], depth[201000];
bool checked[201000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, A, B, x, y, K, mx_depth, res;
    cin >> T;

    while (T--)
    {
        cin >> N;
        cin >> A >> B;

        vector<int> graph[N + 1];

        for (int i = 0; i < N - 1; i++)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        stack<int> st;
        fill(checked, checked + N + 1, false);
        fill(depth, depth + N + 1, 0);

        st.push(A);
        checked[A] = true;

        while (!st.empty())
        {
            K = st.top();
            st.pop();

            for (int i : graph[K])
            {
                if (checked[i])
                    continue;
                checked[i] = true;
                st.push(i);
                parent[i] = K;
                depth[i] = depth[K] + 1;
            }
        }

        x = depth[B] - depth[B] / 2;
        res = x + 2 * (N - 1);
        while (x--)
            B = parent[B];

        fill(checked, checked + N + 1, false);
        fill(depth, depth + N + 1, 0);

        st.push(B);
        checked[B] = true;
        mx_depth = 0;

        while (!st.empty())
        {
            K = st.top();
            st.pop();

            for (int i : graph[K])
            {
                if (checked[i])
                    continue;
                checked[i] = true;
                st.push(i);
                parent[i] = K;
                depth[i] = depth[K] + 1;
                mx_depth = max(mx_depth, depth[i]);
            }
        }

        res -= mx_depth;
        cout << res << '\n';
    }

    return 0;
}