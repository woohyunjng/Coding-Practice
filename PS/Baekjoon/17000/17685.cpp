#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int D[MAX], V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, L, R, X, ans;

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> D[i];
        if (i > 1)
            D[i] = (D[i] + D[i - 1] - 1) / D[i - 1] * D[i - 1];
    }

    function<int(int, int)> get = [&](int T, int X) {
        int st = 1, en = N, md, res = 0;

        while (st <= en) {
            md = st + en >> 1;
            if ((T / D[md]) * D[md] - md >= X)
                res = md, st = md + 1;
            else
                en = md - 1;
        }

        return res;
    };

    while (Q--) {
        cin >> T >> L >> R, ans = T >= L && T <= R;
        ans += get(T, L) - get(T, R + 1);
        cout << ans << '\n';
    }

    return 0;
}