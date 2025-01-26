#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, cnt, res;
    vector<int> arr;

    cin >> T;

    while (T--) {
        cin >> N >> K, arr.clear(), res = -1;
        for (int i = 0; (1ll << i) <= N; i++)
            if (!(N & (1ll << i)))
                arr.push_back(i);

        cnt = (int)arr.size();
        if (K <= (1ll << cnt)) {
            res = N;
            for (int k = cnt - 1; k >= 0; k--) {
                if (K > (1ll << k))
                    res |= (1ll << arr[k]), K -= (1ll << k);
            }
        }
        cout << res << '\n';
    }

    return 0;
}