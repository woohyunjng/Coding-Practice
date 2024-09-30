#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, B, C, D, res, K;
    bool check;
    cin >> T;

    while (T--) {
        cin >> B >> C >> D;

        res = 0;
        K = 0, check = true;

        while (B || C || D) {
            if (D & 1) {
                if (!(B & 1)) {
                    if (C & 1) {
                        check = false;
                        break;
                    } else
                        res += (1ll << K);
                }
            } else {
                if (B & 1) {
                    if (C & 1)
                        res += (1ll << K);
                    else {
                        check = false;
                        break;
                    }
                }
            }

            K++;
            B >>= 1, C >>= 1, D >>= 1;
        }

        if (!check)
            res = -1;

        cout << res << '\n';
    }

    return 0;
}