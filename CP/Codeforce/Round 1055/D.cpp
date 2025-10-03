#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 250001;

int A[MAX], S[MAX], cnt[MAX];

void solve() {
    int N, Q, L, R, X, ans;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], X = A[i];
        while (X > 1)
            X >>= 1, S[i]++;

        cnt[i] = A[i] == ((1ll << S[i]) + 1);
        S[i] += A[i] != (1ll << S[i]);
        S[i] += S[i - 1], cnt[i] += cnt[i - 1];
    }

    while (Q--) {
        cin >> L >> R;
        ans = S[R] - S[L - 1] - (cnt[R] - cnt[L - 1] + 1) / 2;
        cout << ans << '\n';
    }

    for (int i = 1; i <= N; i++)
        A[i] = S[i] = cnt[i] = 0;
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