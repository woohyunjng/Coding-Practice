#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int A[MAX];

void solve() {
    int N, X, V[2] = {1'000'000'001, -1'000'000'001};
    bool ans = true;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], V[0] = min(V[0], A[i]), V[1] = max(V[1], A[i]);

    cin >> X;
    ans = V[0] <= X && X <= V[1];

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