#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N, res, ans;
    cin >> N;

    for (int st = 1, en = N, md; st <= en;) {
        md = st + en >> 1;
        cout << "? " << md << '\n', cout.flush();
        cin >> res;

        if (res == -1)
            st = md + 1;
        else if (res == 1)
            en = md - 1;
        else {
            ans = md;
            break;
        }
    }

    cout << "= " << ans << '\n', cout.flush();

    return 0;
}