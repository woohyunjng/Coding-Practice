#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MAX_LOG = 63;

int V[MAX_LOG];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X;
        for (int j = MAX_LOG - 1; j >= 0; j--) {
            if (!(X & (1ll << j)))
                continue;
            X ^= V[j];
        }
        Y = -1;
        for (int j = 0; j < MAX_LOG; j++) {
            if (!(X & (1ll << j)))
                continue;
            Y = j;
        }
        if (Y != -1)
            V[Y] = X;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--)
        ans = max(ans, ans ^ V[i]);

    cout << ans << '\n';

    return 0;
}