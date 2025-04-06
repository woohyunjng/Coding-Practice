#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int N;

    cin >> N;
    if (N % 2 == 0)
        cout << -1 << '\n';
    else {
        cout << N << ' ';
        for (int i = 1; i < N; i++)
            cout << i << ' ';
        cout << '\n';
    }
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