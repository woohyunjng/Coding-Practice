#include <bits/stdc++.h>
#define int long long

using namespace std;

int query(int l, int r) {
    int ret;
    cout << "? " << l << ' ' << r << '\n', cout.flush();
    cin >> ret;
    return ret;
}

void answer(int x) {
    cout << "! " << x << '\n', cout.flush();
}

void solve() {
    int N, L, R, V, K, S, ans = 0;

    cin >> N, L = 1, R = N;
    S = ans = query(1, N);

    while (L < R && (S % 2 == 0)) {
        K = -1, S >>= 1;
        for (int st = L, en = R - 1, md; st <= en;) {
            md = st + en >> 1;
            if (query(L, md) <= S)
                K = md, st = md + 1;
            else
                en = md - 1;
        }
        if (query(L, K) != S)
            break;

        ans = S;
        if (K - L >= R - K - 1)
            L = K + 1;
        else
            R = K;
    }

    answer(ans);
}

signed main() {
    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}