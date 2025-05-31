#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MAX_B = 61;

int A[MAX], B[MAX], C[MAX], R[MAX_B], V[MAX_B];

void solve() {
    int N, ans = 0, K;
    string S;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    fill(R, R + MAX_B, 0), fill(V, V + MAX_B, 0);

    cin >> S;
    for (int i = 1; i <= N; i++)
        C[i] = S[i - 1] - '0';

    for (int i = 1; i <= N; i++)
        ans ^= A[i], A[i] ^= B[i];

    for (int i = N; i >= 1; i--) {
        for (int j = MAX_B - 1; j >= 0; j--)
            if (A[i] & (1ll << j))
                A[i] ^= V[j];
        K = -1;
        for (int j = 0; j < MAX_B; j++)
            if (A[i] & (1ll << j))
                K = j;
        if (K == -1)
            continue;
        V[K] = A[i], R[K] = C[i];
    }

    for (int i = MAX_B - 1; i >= 0; i--) {
        if (R[i] == 1)
            ans = max(ans, ans ^ V[i]);
        else
            ans = min(ans, ans ^ V[i]);
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