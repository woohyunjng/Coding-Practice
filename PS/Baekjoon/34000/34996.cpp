#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    cout << N * (N + 1) - 1 << '\n';
    for (int i = 1; i <= N; i++)
        cout << -i << ' ';
    cout << 0 << ' ';
    for (int i = N; i >= 1; i--)
        cout << i << ' ';
    cout << '\n';

    return 0;
}