#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int ans[MAX];

void solve() {
    int N;

    cin >> N;
    for (int i = N, j = 1; i >= 1; i -= 2, j++)
        ans[i] = j;
    for (int i = N - 1, j = N; i >= 1; i -= 2, j--)
        ans[i] = j;

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}