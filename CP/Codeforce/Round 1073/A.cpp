#include <bits/stdc++.h>
using namespace std;

int V[101];

void solve() {
    int N, X;
    bool ans = true;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> X, V[X] = i;

    for (int i = 1; i + 1 <= N; i++)
        ans &= (V[i] & 1) != (V[i + 1] & 1);
    cout << (ans ? "YES" : "NO") << '\n';
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