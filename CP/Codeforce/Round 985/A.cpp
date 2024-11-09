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
    int L, R, K, res = 0, st, md, en;
    cin >> L >> R >> K;

    st = L, en = R;
    while (st <= en) {
        md = st + en >> 1;
        if (R / md >= K) {
            res = md - L + 1;
            st = md + 1;
        } else
            en = md - 1;
    }

    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}