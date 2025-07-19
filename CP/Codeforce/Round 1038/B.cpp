#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int A[MAX], B[MAX], C[MAX], D[MAX];

void solve() {
    int N, ans = 0, X = 0, Y = 0;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        if (B[i] > D[i])
            ans += A[i] + B[i] - D[i];
        else if (A[i] > C[i])
            ans += A[i] - C[i];
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