#include <bits/stdc++.h>
#define int long long

using namespace std;

int ans[1000001];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X;
    queue<int> q;

    cin >> N >> M;

    while (M--)
        cin >> X, q.push(X), ans[X] = 1;

    while (!q.empty()) {
        X = q.front(), q.pop();
        if (X - 1 > 0 && ans[X - 1] == 0)
            ans[X - 1] = ans[X] + 1, q.push(X - 1);
        if (X + 1 <= N && ans[X + 1] == 0)
            ans[X + 1] = ans[X] + 1, q.push(X + 1);
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}