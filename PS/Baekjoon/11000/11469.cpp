#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, V, K;
    vector<int> ans;

    cin >> T;
    while (T--) {
        cin >> N, ans.clear(), V = 1;

        while (N) {
            while (N % 2 == 0)
                N /= 2, V *= 2;
            while (N % 3 == 0)
                N /= 3, V *= 3;
            if (N == 1)
                ans.push_back(V), N = 0;
            else {
                for (int i = 60;; i--) {
                    if ((1ll << i) > N)
                        continue;
                    if ((N - (1ll << i)) % 3 == 0) {
                        ans.push_back(V * (1ll << i)), N -= 1ll << i;
                        break;
                    }
                }
            }
        }

        cout << ans.size() << '\n';
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}