#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int A[MAX], B[MAX], C[MAX];

void solve() {
    int N, X, K = 0, ans = -1;

    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i] >> C[i];
        X -= (B[i] - 1) * A[i];
        K = max(K, -C[i] + B[i] * A[i]);
    }

    if (X <= 0)
        ans = 0;
    else if (X > 0 && K != 0)
        ans = (X + K - 1) / K;
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