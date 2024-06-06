#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> arr[100100];
bool vst[100100];

void dfs(int K)
{
    cout << K << ' ';
    for (int i : arr[K])
    {
        if (vst[i])
            continue;
        vst[i] = true;
        dfs(i);
    }
}

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
        arr[B].push_back(A);
    }

    vst[1] = true;
    dfs(1);

    fill(vst, vst + N + 1, false);
    queue<int> q;
    q.push(1);
    vst[1] = true;
    cout << '\n';

    while (!q.empty())
    {
        int K = q.front();
        q.pop();

        cout << K << ' ';
        for (int i : arr[K])
        {
            if (vst[i])
                continue;
            q.push(i);
            vst[i] = true;
        }
    }

    return 0;
}