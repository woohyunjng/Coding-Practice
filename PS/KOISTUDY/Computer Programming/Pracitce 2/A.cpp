#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;

    queue<int> q;
    vector<int> ans;

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        q.push(i);

    while (N--) {
        for (int i = 0; i < K - 1; i++)
            q.push(q.front()), q.pop();
        ans.push_back(q.front()), q.pop();
    }

    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}