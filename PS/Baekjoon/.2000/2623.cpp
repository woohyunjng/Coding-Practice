#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> arr[1010];
int in_degree[1010];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, A, B;
    cin >> N >> M;

    while (M--)
    {
        cin >> K >> A;
        for (int i = 0; i < K - 1; i++)
        {
            cin >> B;
            arr[A].push_back(B);
            in_degree[B]++;
            A = B;
        }
    }

    vector<int> res;
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (!in_degree[i])
            q.push(i);
    }

    while (N--)
    {
        if (q.empty())
        {
            cout << 0;
            return 0;
        }

        A = q.front();
        res.push_back(A);
        q.pop();

        for (int i : arr[A])
        {
            in_degree[i]--;
            if (!in_degree[i])
                q.push(i);
        }
    }

    for (int i : res)
        cout << i << '\n';

    return 0;
}