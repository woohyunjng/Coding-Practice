#include <bits/stdc++.h>
using namespace std;

int A[200001];

void solve() {
    int N, X, ans = -1;
    string S;

    cin >> N >> S;
    for (int i = 1; i <= N; i++)
        A[i] = S[i - 1] == '(' ? 1 : -1;

    X = 0;
    for (int i = N; i >= 1; i--) {
        if (A[i] == -1)
            ans = X >= 2 ? N - 2 : ans;
        else
            X++;
    }

    cout << ans << '\n';
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