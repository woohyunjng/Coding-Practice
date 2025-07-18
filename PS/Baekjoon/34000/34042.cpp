#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T, X, V, cnt[3], ans;

    cin >> N >> T;

    while (T--) {
        cnt[0] = cnt[1] = cnt[2] = 0;
        V = 0, ans = 1;

        for (int i = 0; i < N; i++) {
            cin >> X;
            if (X > 0)
                ans *= X, V++;
            else
                cnt[-X]++;
        }

        while (cnt[2] >= 2)
            ans *= 4, cnt[2] -= 2, V += 2;
        if (cnt[2] == 1 && cnt[1] > 0)
            ans *= 2, cnt[1]--, cnt[2]--, V += 2;
        while (cnt[1] >= 2)
            cnt[1] -= 2, V += 2;
        if (V == 0)
            ans = cnt[0] > 0 ? 0 : (cnt[1] > 0 ? -1 : -2);

        cout << ans << '\n';
    }

    return 0;
}
