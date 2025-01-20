#include <bits/stdc++.h>
#define int long long

#define MAX 200
using namespace std;

int A[MAX];

void solve() {
    int N, X = 0, Y = 0, res;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i] & 1)
            X++;
        else
            Y++;
    }

    if (Y == 0)
        res = X - 1;
    else
        res = X + 1;

    cout << res << '\n';
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