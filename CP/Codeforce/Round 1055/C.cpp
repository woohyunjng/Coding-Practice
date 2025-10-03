#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 250001;

int A[MAX], S[MAX][2], V[MAX][2];

void solve() {
    int N, Q, L, R, ans;
    bool flag;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], S[i][A[i]]++;
        S[i][0] += S[i - 1][0], S[i][1] += S[i - 1][1];

        V[i][i & 1] = A[i];
        V[i][0] += V[i - 1][0], V[i][1] += V[i - 1][1];
    }

    while (Q--) {
        cin >> L >> R, ans = 0;

        flag = (S[R][0] - S[L - 1][0]) % 3 == 0 && (S[R][1] - S[L - 1][1]) % 3 == 0;
        if (!flag) {
            cout << -1 << '\n';
            continue;
        }

        flag = false;
        flag |= (V[R][0] - V[L - 1][0]) == 0 && (V[R][1] - V[L - 1][1]) == (R - L + 1) / 2;
        flag |= (V[R][0] - V[L - 1][0]) == (R - L + 1) / 2 && (V[R][1] - V[L - 1][1]) == 0;
        flag &= (R - L + 1) % 2 == 0;

        ans = (R - L + 1) / 3 + flag;
        cout << ans << '\n';
    }

    for (int i = 1; i <= N; i++)
        S[i][0] = S[i][1] = V[i][0] = V[i][1] = 0;
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