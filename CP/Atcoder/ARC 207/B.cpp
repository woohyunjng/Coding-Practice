#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    vector<pr> ans;

    cin >> N;
    if (N <= 5) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 1; i <= N / 2; i++)
        for (int j = N / 2 + 1; j <= N / 2 * 2; j++)
            if (i + j != N / 2 * 2 + 1)
                ans.push_back({i, j});
    if (N & 1)
        for (int i = 1; i <= N / 2; i++)
            ans.push_back({i, N});

    cout << ans.size() << '\n';
    for (pr i : ans)
        cout << i[0] << ' ' << i[1] << '\n';

    return 0;
}