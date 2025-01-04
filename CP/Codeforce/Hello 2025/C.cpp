#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

void solve() {
    int L, R, X = 0, K;
    cin >> L >> R;

    for (int i = 30; i >= 0; i--) {
        if ((L & (1ll << i)) ^ (R & (1ll << i))) {
            K = i;
            break;
        } else
            X |= L & (1ll << i);
    }

    for (int i = K; i >= 0; i--) {
        if ((L & (1ll << i)) == (R & (1ll << i))) {
            if (L & (1ll << i)) {
                for (int j = i + 1; j <= K; j++)
                    X |= R & (1ll << j);
            } else {
                X |= 1ll << i;
                for (int j = i + 1; j <= K; j++)
                    X |= L & (1ll << j);
            }
            K = i - 1;
            break;
        }

        if (i == 0)
            K = -1;
    }

    if (K == -1)
        X = R - 1;
    for (int i = K; i >= 0; i--) {
        if ((L & (1ll << i)) == (R & (1ll << i)))
            X |= L & (1ll << i) ^ (1ll << i);
        else
            X |= 1ll << i;
    }

    cout << L << ' ' << R << ' ' << X << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}