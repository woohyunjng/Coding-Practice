#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

int D[501];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    vector<pr> ans;

    cin >> N;

    for (int i = 2; i <= N; i++) {
        cout << "? 1 " << i << '\n', cout.flush();
        cin >> D[i];
    }

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++) {
            if (abs(D[i] - D[j]) != 1)
                continue;
            cout << "? " << i << ' ' << j << '\n', cout.flush();
            cin >> X;
            if (X == 1)
                ans.push_back({i, j});
        }

    cout << "! " << ans.size() << '\n';
    for (pr i : ans)
        cout << i[0] << ' ' << i[1] << '\n';

    return 0;
}