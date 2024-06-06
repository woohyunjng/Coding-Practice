#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

vector<int> arr[33000];
int in_degree[33000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, A, B;
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
        K = pq.top();
        pq.pop();

        cout << K << ' ';

        for (int j : arr[K])
        {
            in_degree[j]--;
            if (!in_degree[j])
                pq.push(j);
        }
    }

    return 0;
}