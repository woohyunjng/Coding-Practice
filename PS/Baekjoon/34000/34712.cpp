#include <bits/stdc++.h>
#define int long long

using namespace std;

int query(int X) {
    int res;
    cout << "? " << X << '\n', cout.flush();
    cin >> res;
    return res;
}

signed main() {
    int N, S = 0, K, ans;

    cin >> N, S = 100000 * N - query(100000);

    for (int st = 1, en = 100000, md; st <= en;) {
        md = st + en >> 1, K = query(md);
        if (md * N - K == S)
            ans = md, en = md - 1;
        else
            st = md + 1;
    }

    cout << "! " << ans << '\n', cout.flush();

    return 0;
}