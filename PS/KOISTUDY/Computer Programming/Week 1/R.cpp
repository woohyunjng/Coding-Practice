#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, ans = 1;

    cin >> N >> M;

    for (int i = M + 1; i <= N; i++)
        ans = ans * i / (i - M);

    cout << ans << '\n';

    return 0;
}