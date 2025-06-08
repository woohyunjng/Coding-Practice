#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200000;
const int MAX_B = 61;

int X[MAX], Y[MAX], V[MAX_B], R[MAX_B];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, K, ans;

    cin >> T;
    while (T--) {
        cin >> N >> M, ans = 0;
        for (int i = 1; i <= N; i++) {
            cin >> X[i] >> Y[i];
            ans ^= X[i], X[i] ^= Y[i];
        }
        for (int i = N + 1; i <= N + M; i++) {
            cin >> X[i] >> Y[i];
            ans ^= X[i], X[i] ^= Y[i];
        }

        fill(R, R + MAX_B, 0), fill(V, V + MAX_B, 0);

        for (int i = N + M; i >= 1; i--) {
            for (int j = MAX_B - 1; j >= 0; j--)
                if (X[i] & (1ll << j))
                    X[i] ^= V[j];
            K = -1;
            for (int j = 0; j < MAX_B; j++)
                if (X[i] & (1ll << j))
                    K = j;
            if (K == -1)
                continue;
            V[K] = X[i], R[K] = i;
        }

        for (int i = MAX_B - 1; i >= 0; i--) {
            if (R[i] <= N)
                ans = max(ans, ans ^ V[i]);
            else
                ans = min(ans, ans ^ V[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}