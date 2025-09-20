#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], T[MAX], ans[32], S[32];

void solve() {
    int N, Q, X, val, M = 0, Y, Z;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i], M |= A[i];

    S[0] = M & 1;
    for (int i = 1; i < 32; i++)
        S[i] = S[i - 1] + ((M >> i) & 1);

    fill(ans, ans + 32, 0);
    ans[0] = (M & 1) ? 0 : 1;

    for (int i = 1; i < 32; i++) {
        if (M & (1ll << i)) {
            ans[i] = ans[i - 1];
            continue;
        }

        for (int j = 1; j <= N; j++)
            T[j] = A[j] & ((1ll << (i + 1)) - 1);

        for (int j = i; j >= 0; j--) {
            X = 0, Y = INF;
            for (int k = 1; k <= N; k++) {
                if ((T[k] >> j) & 1)
                    Y = 0;
                else {
                    Z = (1ll << j) - (T[k] & ((1ll << j) - 1));
                    if (Z < Y)
                        Y = Z, X = k;
                }
            }
            T[X] += Y, ans[i] += Y;
        }
    }

    while (Q--) {
        cin >> X, val = S[31];
        for (int i = 0; i < 32 && ans[i] <= X; i++)
            val = max(val, S[31] - S[i] + i + 1);
        cout << val << '\n';
    }
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