#include <bits/stdc++.h>
using namespace std;

int V[2001];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, X;

    cin >> N;
    for (int i = 1; i <= N * 2; i++) {
        cin >> X;
        if (!V[X])
            V[X] = i;
        else
            ans = max(ans, i - V[X] - 1);
    }

    cout << ans << '\n';

    return 0;
}