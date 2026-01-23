#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 101;

int A[MAX];

void solve() {
    int N, H, L, X = 0, Y = 0, ans = 0;

    cin >> N >> H >> L;
    if (H > L)
        swap(H, L);

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    sort(A + 1, A + N + 1);

    for (int i = 1; i <= N; i++) {
        if (A[i] <= H)
            X = i;
        if (A[i] <= L)
            Y = i;
    }
    Y -= X, Y = min(Y, X);
    ans += Y, X -= Y, ans += X / 2;

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