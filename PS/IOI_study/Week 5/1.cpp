#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[300100], res;
int in_degree[300100];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B;
    cin >> N >> M;

    while (M--)
    {
        cin >> A >> B;
        arr[A].push_back(B);
        in_degree[B]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++)
    {
        if (!in_degree[i])
            pq.push(i);
    }

    while (!pq.empty())
    {
        A = pq.top();
        pq.pop();

        res.push_back(A);
        for (int i : arr[A])
        {
            in_degree[i]--;
            if (!in_degree[i])
                pq.push(i);
        }
    }

    if (res.size() != N)
        cout << -1;
    else
    {
        for (int i : res)
            cout << i << ' ';
    }

    return 0;
}