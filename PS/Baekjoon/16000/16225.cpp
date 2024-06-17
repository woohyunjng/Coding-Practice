#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], B[MAX];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, lst, res = 0, x, y;
    pr K;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    vector<pr> arr;
    for (int i = 1; i <= N; i++)
        arr.push_back({B[i], A[i]});
    sort(arr.begin(), arr.end());

    priority_queue<int> pq;
    for (int i = 1; i <= N / 2; i++)
    {
        if (i == 1)
            pq.push(arr[0].second);
        else
        {
            pq.push(arr[i * 2 - 3].second);
            pq.push(arr[i * 2 - 2].second);
        }
        res += pq.top();
        pq.pop();
    }

    cout << res;

    return 0;
}