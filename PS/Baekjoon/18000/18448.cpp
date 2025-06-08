#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 200001;

int W[MAX];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, V, X, Y, st, en, md, ans;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> W[i];
    rotate(W + 1, min_element(W + 1, W + N + 1), W + N + 1);

    st = W[1] * 2, en = 2e9, ans = 0;
    while (st <= en) {
        md = st + en >> 1, X = Y = 2e9, V = 0;
        for (int i = 1; i <= N; i++) {
            if (W[i] * 2 <= md) {
                V++;
                if (X <= md - max(Y, W[i]))
                    V++;
                X = 2e9, Y = W[i];
            } else
                X = min(X, W[i]);
        }
        if (X <= md - Y)
            V++;

        if (V >= K)
            en = md - 1, ans = md;
        else
            st = md + 1;
    }

    cout << ans << '\n';

    return 0;
}