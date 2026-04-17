#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int T, X, st, en, md, ans, cnt;

    cin >> T;

    st = 1, en = 3'000'000'000'000'0;
    while (st <= en) {
        md = st + en >> 1, cnt = 0, X = sqrt(md);
        for (int i = 1; i <= X; i++)
            cnt += md / i;
        for (int i = 1; i < md / X; i++)
            cnt += (md / i - md / (i + 1)) * i;
        if (cnt <= T)
            ans = md, st = md + 1;
        else
            en = md - 1;
    }

    cout << ans << '\n';
}