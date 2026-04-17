#include <bits/stdc++.h>
using namespace std;

int ans[5000];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, E, K;

    cin >> N >> K;
    S = 1, E = N;

    for (int i = 1; i <= N; i++) {
        if (K >= E - S)
            ans[i] = E, K -= E - S, E--;
        else
            ans[i] = S, S++;
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}