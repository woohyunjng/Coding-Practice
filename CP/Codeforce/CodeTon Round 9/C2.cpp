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
    int N, M, res = 0, K = 0, X, st, en, mid, cnt = 0, def;
    cin >> N >> M;

    X = N;
    while (X)
        K++, X >>= 1;

    for (int i = 1; i < min(M + 1, 1ll << K); i++) {
        X = N ^ i;
        if (X % i == 0 || X % N == 0)
            cnt++;
    }

    st = 0;
    while (N * st < (1ll << K))
        st++;
    en = M / N * 2, res = st - 1, def = st;

    while (st <= en) {
        mid = st + en >> 1ll;
        X = N * mid;

        if ((X >> K) < (M >> K)) {
            res = mid;
            st = mid + 1;
        } else
            en = mid - 1;
    }

    for (int i = res + 1; ((N * i) >> K) == (M >> K); i++) {
        if (((N * i) ^ N) <= M)
            res++;
    }
    res = res - def + 1;

    cout << res + cnt << '\n';
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